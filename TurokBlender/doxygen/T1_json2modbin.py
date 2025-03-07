# Created By  : BehemothProgrammer
# Description : Converts a json dictionary file to a Turok 1 Mod Data File that can be used in scripting.
# Usage       : T1_json2modbin input.json output.dat
#

from pathlib import Path
import sys, argparse, struct, json

STRING_ENCODING: str = "ascii" #"utf-8"

def read_uint32(buf) -> int:
    return struct.unpack('<I', buf.read(4))[0]
    
def read_string(buf, length: int) -> str:
    return buf.read(length).decode(STRING_ENCODING) # .rstrip('\x00')
    
def write_uint32(buf, val: int) -> None:
    buf.write(struct.pack('<I', val))

def write_string(buf, s: str) -> None:
    buf.write(bytes(s, STRING_ENCODING)+b'\0')
    
def exit_error(s: str) -> None:
    print(s)
    sys.exit(1)

if __name__ == "__main__":
    parser: argparse.ArgumentParser = argparse.ArgumentParser()
    parser.add_argument("paths", nargs=2, help=f"input.json output.dat")
    args = parser.parse_args()
    
    input_path: Path = Path(args.paths[0]).resolve()
    output_path: Path = Path(args.paths[1]).resolve()
    
    d: dict = {}
    with open(input_path, 'r') as file:
        d = json.load(file)
    
    if not isinstance(d, dict):
        exit_error("ERROR: The JSON data is not a dictionary.")
        
    # Check if all values are strings
    for key, value in d.items():
        if not isinstance(value, str):
            exit_error(f"ERROR: The key '{key}' does not have a string value. It has a value of type '{type(value).__name__}'")
        
    entryCount = len(d)
    with open(output_path, 'wb') as file:
        print("Entries: %s" % (len(d)))
        write_uint32(file, len(d))
        for key, value in d.items():
            write_uint32(file, len(key) + 1)
            write_string(file, key)
            write_uint32(file, len(value) + 1)
            write_string(file, value)
    
    print(f"File written to {output_path}")
    
    # with open(output_path, 'rb') as file:
        # entires = read_uint32(file)
        # print("Entries: %s" % (len(d)))
        # for key, value in d.items():
            # keylen = read_uint32(file)
            # keystr = read_string(file, keylen)
            # valuelen = read_uint32(file)
            # valuestr = read_string(file, valuelen)
