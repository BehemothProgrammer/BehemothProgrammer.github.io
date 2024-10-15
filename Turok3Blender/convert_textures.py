# (C) 2024 Eric Serio
#
# Version     : 1.0.0 (10/15/2024)
# Description : Converts/Copies all textures from the "textures_src" folder to the "textures" and "HiResTextures" folders.
# Requirements: ImageMagick - https://imagemagick.org/archive/binaries/ImageMagick-7.1.1-38-Q16-HDRI-x64-dll.exe
# License     : GNU General Public License v3.0. See <https://www.gnu.org/licenses/gpl-3.0.html> for details.
#               This program is provided without warranty.

import sys, os, time, json, hashlib, traceback, shutil, subprocess, asyncio, multiprocessing, argparse
from pathlib import Path
from typing import Any, Union, List, Tuple

MAX_PROCESSES: int = multiprocessing.cpu_count()
PATH_CURRENT: Path  = Path(__file__).resolve().parent
PATH_ROOT: Path     = PATH_CURRENT.parent

TEXSRC_PATH: Path   = PATH_ROOT / "textures_src"
TEXLOW_PATH: Path   = PATH_ROOT / "textures"
TEXHI_PATH: Path    = PATH_ROOT / "HiResTextures"
MANIFEST_FILE: Path = PATH_CURRENT / "convert_textures_manifest.json"
MAGICK_EXE: str = "magick"
EXT_INFOS: dict = {
    ".tga":
    {
        "dir": TEXLOW_PATH,
        "args": ["-define", "tga:compression=none"]
    },
    ".dds":
    {
        "dir": TEXHI_PATH,
        "args": ["-define", "dds:mipmaps=5"]
    }
}

VERBOSITY_QUIET: int = 0
"""Show nothing"""
VERBOSITY_NORMAL: int = 1
"""Show errors and complete msg"""
VERBOSITY_VERBOSE: int = 2
"""Show logs, errors"""

g_verbosity: int = VERBOSITY_NORMAL
g_num_copied_textures: int = 0
g_num_coverted_textures: int = 0
g_msg_wait: bool = False


def print_verbose(verbosity: int, *objects: object) -> None:
    if g_verbosity >= verbosity:
        print(*objects)


def print_exception_verbose(verbosity: int) -> None:
    if g_verbosity >= verbosity:
        traceback.print_exception(*sys.exc_info())


def hash_file(filepath: Path) -> str:
    h = hashlib.sha1()
    mv = memoryview(bytearray(131072))
    with open(filepath, "rb", buffering=0) as f:
        for n in iter(lambda: f.readinto(mv), 0):
            h.update(mv[:n])

    return h.hexdigest()
    

def json_save(path: Path, obj: Any) -> bool:
    try:
        with open(path, "w", encoding="utf-8") as file:
            json.dump(obj, file, indent=2)
    except:
        g_msg_wait = True
        print_exception_verbose(VERBOSITY_NORMAL)
        return False

    return True


def json_load(path: Path) -> dict:
    try:
        with open(path, "r") as file:
            return json.load(file)
    except FileNotFoundError:
        print_exception_verbose(VERBOSITY_VERBOSE)
        return {}
    except:
        g_msg_wait = True
        print_exception_verbose(VERBOSITY_NORMAL)
        
    return {}


def remove_file(path: Path) -> bool:
    try:
        os.remove(path)
    except FileNotFoundError:
        print_exception_verbose(VERBOSITY_VERBOSE)
        return False
    except:
        print_exception_verbose(VERBOSITY_NORMAL)
        return False
    else:
        print_verbose(VERBOSITY_VERBOSE, f'Deleted file "{path}"')

    return True


def remove_dir(path: Path) -> bool:
    try:
        shutil.rmtree(path)
    except FileNotFoundError:
        print_exception_verbose(VERBOSITY_VERBOSE)
        return False
    except:
        g_msg_wait = True
        print_exception_verbose(VERBOSITY_NORMAL)
        return False
    else:
        print_verbose(VERBOSITY_NORMAL, f'Removed folder "{path}"')

    return True


def copy_textures() -> bool:
    """ Copies textures that are already tga or dds. """
    global g_num_copied_textures
    for tex_info in textures:
        if not tex_info["process"]: continue
        for target_ext, ext_info in EXT_INFOS.items():
            if tex_info["ext"] != target_ext: continue
            try:
                shutil.copy2(tex_info["path"], ext_info["dir"] / tex_info["rel_path"])
            except Exception as e:
                print_verbose(VERBOSITY_NORMAL, f'[ERROR] Copying texture from "{tex_info["rel_path"]}" to "{ext_info["dir"] / tex_info["rel_path"]}": {e}')
                return False
            else:
                g_num_copied_textures += 1
                print_verbose(VERBOSITY_VERBOSE, f'Copied "{tex_info["rel_path"]}" to "{ext_info["dir"] / tex_info["rel_path"]}"')
                break

    return True


async def convert_texture(semaphore: asyncio.Semaphore, tex_info: dict, target_ext: str) -> bool:
    async with semaphore:
        ext_info: dict = EXT_INFOS[target_ext]
        args: List[str] = [
            str(tex_info["path"]), # src path
            *ext_info["args"],
            str((ext_info["dir"] / tex_info["rel_path"]).with_suffix(target_ext)), #dest path
        ]
        proc = await asyncio.create_subprocess_exec(
            MAGICK_EXE,
            *args,
            stdout=asyncio.subprocess.PIPE,
            stderr=asyncio.subprocess.STDOUT,
        )
        retcode = await proc.wait()
        if retcode == 0:
            print_verbose(VERBOSITY_VERBOSE, f'Converted "{tex_info["rel_path"]}" to "{target_ext}"')
        else:
            if g_verbosity >= VERBOSITY_NORMAL:
                print(f'[ERROR] Failed to convert "{tex_info["rel_path"]}" to "{target_ext}" (Return code: {retcode})')
                output, _ = await proc.communicate()
                sys.stdout.buffer.write(output)
            return False

        return True


async def process_textures(textures: List) -> bool:
    """ Converts/Copies textures """
    # Copy Textures
    copy_coro = asyncio.to_thread(copy_textures)
    copy_task = asyncio.create_task(copy_coro)

    # Convert Textures
    semaphore: asyncio.Semaphore = asyncio.Semaphore(MAX_PROCESSES)
    tasks = []
    for tex_info in textures:
        if tex_info["process"]:
            for target_ext in EXT_INFOS:
                if tex_info["ext"] != target_ext:
                    tasks.append(convert_texture(semaphore, tex_info, target_ext))
    results = await asyncio.gather(*tasks)
    
    # Get results
    copy_result = await copy_task
    results.append(copy_result)
    global g_num_coverted_textures
    g_num_coverted_textures = len(tasks)
    
    return all(results)


def finish_exit(code: int = 0):
    # Give the user time to see messages
    if g_verbosity > VERBOSITY_QUIET:
        if g_msg_wait or code > 0:
            print("...")
            time.sleep(3)
    sys.exit(code)


if __name__ == "__main__":
    start_time = time.time()
    
    # Parse Arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--verbose", type=int, default=g_verbosity, help="0: Silent, 1: Normal, 2: Verbose")
    parser.add_argument("-f", "--force", action="store_true", help="Forces all textures to get converted/copied (same as deleting the manifest)")
    parser.add_argument("-c", "--clean", action="store_true", help='Deletes the "textures" and "HiResTextures" folders before converting')
    args: Any = parser.parse_args()
    g_verbosity = args.verbose
    force_convert: bool = args.force
    clean_textures: bool = args.clean
    if clean_textures:
        force_convert = True
    save_manifest: bool = False
    
    # If cleaning then delete the "textures" and "HiResTextures" folders
    if clean_textures:
        save_manifest = True
        remove_dir(TEXLOW_PATH)
        remove_dir(TEXHI_PATH)

    # Source textures folder must exist
    if not TEXSRC_PATH.is_dir():
        print_verbose(VERBOSITY_NORMAL, f"{TEXSRC_PATH.name} folder doesn't exist.")
        remove_file(MANIFEST_FILE)
        finish_exit(1)
        
    # Finds all textures in the source textures folder
    textures = [
        {
            "path": file,
            "rel_path": file.relative_to(TEXSRC_PATH),
            "ext": file.suffix.lower(),
            "process": False
        }
        for file in TEXSRC_PATH.rglob('*') if file.is_file()
    ]

    # Do not continue if there are no textures to convert/copy
    if not textures:
        print_verbose(VERBOSITY_NORMAL, f"No files found in {TEXSRC_PATH.name}.")
        remove_file(MANIFEST_FILE)
        finish_exit(1)
        
    # Check if texture files have the same path but different ext.
    # Prints a warning message to the user to fix that.
    if g_verbosity >= VERBOSITY_NORMAL:
        stems = set()
        for tex_info in textures:
            stem: str = tex_info["path"].stem
            if stem in stems:
                print(f'[!!!!!WARNING!!!!!] There is another file with the same filename but different extension as "{tex_info["rel_path"]}"')
                g_msg_wait = True
            else:
                stems.add(stem)
        del stems

    # Create directories if they don't exist
    TEXLOW_PATH.mkdir(parents=True, exist_ok=True)
    TEXHI_PATH.mkdir(parents=True, exist_ok=True)
    for tex_info in textures:
        for ext_info in EXT_INFOS.values():
            (ext_info["dir"] / tex_info["rel_path"]).parent.mkdir(parents=True, exist_ok=True)

    # Hash the source textures
    last_manifest: dict = json_load(MANIFEST_FILE) if not force_convert else {}
    manifest: dict = {}
    for tex_info in textures:
        tex_rel_path: str = str(tex_info["rel_path"])
        tex_hash: str = hash_file(tex_info["path"])
        last_hash: str = last_manifest.get(tex_rel_path, "")
        manifest[tex_rel_path] = tex_hash
        if tex_hash != last_hash:
            tex_info["process"] = True
            save_manifest = True

    # Remove textures from the low and hi textures folders that are no longer in the
    # texture source directory but once were before as indicated by the manifest file
    if not clean_textures:
        num_removed_textures: int = 0
        missing_textures = set(last_manifest.keys()) - set(manifest.keys())
        if not save_manifest and len(missing_textures) > 0:
            save_manifest = True
        for tex_rel_path in missing_textures:
            for target_ext, ext_info in EXT_INFOS.items():
                tex_path: Path = (ext_info["dir"] / tex_rel_path).with_suffix(target_ext)
                did_remove: bool = remove_file(tex_path)
                if did_remove:
                    num_removed_textures += 1
    
    # Save manifest
    if save_manifest:
        json_save(MANIFEST_FILE, dict(sorted(manifest.items())))
        
    # Convert textures to tga and dds
    converted_all_textures: bool = asyncio.run(process_textures(textures))
    
    # Show completion info
    if g_verbosity >= VERBOSITY_NORMAL:
        text_deleted: str = "Cleaned. " if clean_textures else f"Deleted: {num_removed_textures} " if num_removed_textures > 0 else ""
        text_copied: str = f"Copied: {g_num_copied_textures} " if g_num_copied_textures > 0 else ""
        text_converted: str = f"Converted: {g_num_coverted_textures} " if g_num_coverted_textures > 0 else ""
        print(f"[COMPLETE] {text_deleted}{text_copied}{text_converted}({(time.time() - start_time):.3f}s)")

    # Show failed message if any textures failed to convert/copy
    if not converted_all_textures:
        print_verbose(VERBOSITY_NORMAL, "Failure! Not all textures were processed successully.")
        finish_exit(1)

    finish_exit(0)
