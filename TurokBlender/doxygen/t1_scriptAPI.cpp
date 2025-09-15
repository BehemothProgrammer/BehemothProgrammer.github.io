enum EnumPlaneSide
{
	PSIDE_FRONT = 0,
	PSIDE_BACK = 1,
	PSIDE_ON = 2
};

enum kexLocPlatform_e ///< Not used (garbage included automatically from kexengine)
{
	LocPlatform_UserPlatformCount = 8,
	LocPlatform_Windows = 1,
	LocPlatform_Linux = 2,
	LocPlatform_Mac = 4,
	LocPlatform_Switch = 8,
	LocPlatform_XboxOne = 16,
	LocPlatform_PlayStation4 = 32,
	LocPlatform_XboxSeries = 64,
	LocPlatform_WindowsStore = 128,
	LocPlatform_PlayStation5 = 256,
	LocPlatform_FirstUserPlatform = 16777216,
	LocPlatform_Current = 1
};

enum EnumAnimStateFlags
{
	ANF_BLEND = 1,
	ANF_LOOP = 2,
	ANF_STOPPED = 4,
	ANF_NOINTERRUPT = 8,
	ANF_ROOTMOTION = 16,
	ANF_PAUSED = 32,
	ANF_CYCLECOMPLETED = 64,
	ANF_LINEARBLEND = 128
};

enum EnumActorFlags
{
	AF_SOLID = 1, ///< Can be collided
	AF_DORMANT = 2, ///< if on then is asleep (won't be updated onTick) else is awake
	AF_SNAPTOFLOOR = 4, ///< adjust z-axis to floor on spawn
    AF_CLIMBWALLS = 8, ///< allows entering of wall sectors
	AF_WOUNDEDMORTALLY = 16, ///< if on this actor will drop a mortal wound because it was hit by a super arrow shot
	AF_CASTSHADOW = 32, ///< can cast a simple shadow
	AF_TRIGGERSTUFF = 64, ///< NOT USED
	AF_HIDDEN = 128, ///< don't draw but continue updating. can't be collided
	AF_ACTIVATED = 256, ///< was triggered
	AF_DISABLED = 512, ///< don't update animations
	AF_ENTEREDAREAEVENT = 1024, ///< just entered a trigger sector
	AF_REMOVEONCOMPLETION = 2048, ///< remove after finishing a special animation
	AF_NOBLOOD = 4096, ///< don't spawn particles flagged as blood
	AF_AVOIDWATER = 8192, ///< clip against edges linking to water sectors
	AF_FLOATINWATERONDEATH = 16384, ///< rise to the surface while dead
	AF_DEAD = 32768, ///< actor is dead. handle special cases for collision
	AF_STATIONARY = 65536, ///< Sniper. don't update the animation's root motion
	AF_ALIGNTOFLOOR = 131072, ///< rotate along slopes
	AF_NODRAW = 262144, ///< don't render
	AF_NONSHOOTABLE = 524288, ///< Fx won't hit actors if this flag is set.
	AF_FULLVOLUME = 1048576, ///< all sounds coming from this actor will be heard at full volume
	AF_CANBETOUCHED = 2097152, ///< allow invoking the OnTouch callback
	AF_IGNORESOUNDEVENTS = 4194304, ///< don't call kexAnimState::Action_PlaySound
	AF_TRIGGERANIMATION = 8388608, ///< play special animation on trigger/spawn
	AF_HOLDTRIGGERANIM = 16777216, ///< pause special animation until triggered (is also invincible)
	AF_TRIGGERNAIMDELAY = 33554432, ///< delay a bit before starting special animation
	AF_STAYINWATER = 67108864, ///< can't exit water sectors
	AF_ALWAYSACTIVE = 134217728, ///< never sleep or go dormant
	AF_COLLIDEDWITHWALL = 268435456, ///< collided with an edge. cleared at every OnTick call
	AF_INVINCIBLE = 536870912, ///< will not receive damage. OnDamage and OnDeath are never called
	AF_ALLOWTINYENEMYCHEAT = 1073741824, ///< affected by tiny enemy game cheat
	AF_NOMOVEMENT = -2147483648 ///< will not do collision movement
};

enum EnumActorSpawnFlags1
{
	ASF1_SOLID = 1,
	ASF1_PROJECTILEATTACK1 = 2, ///< High Priest Flame Attack (anim_aiRangeAttack1)
	ASF1_LEADER = 4, ///< Flocker ai run toward Leaders to get attention.
	ASF1_SNAPTOFLOOR = 8,
	ASF1_EXPLOSIONDEATH = 16, ///< NOT USED
	ASF1_CLIMBWALLS = 32,
	ASF1_PROJECTILEATTACK2 = 64, ///< Pistol Fire (anim_aiRangeAttack2)
	ASF1_NOREPEATEXPLOSION = 128, ///< NOT USED
	ASF1_DIEONEXPLOSION = 256, ///< NOT USED
	ASF1_FLOCKER = 512, ///< flocks to a leader kAI
	ASF1_SLOW = 1024, ///< NOT USED
	ASF1_RANDOMRESURRECTION = 2048, ///< NOT USED
	ASF1_RANDOMFEIGNDEATH = 4096, ///< NOT USED
	ASF1_KAMIKAZE = 8192, ///< if has no target then targets player and sets agitation to 300
	ASF1_AVOIDPLAYERS = 16384, ///< NOT USED
	ASF1_FLOATINWATERONDEATH = 32768, ///< kAI will float up to the top of the water when they are dead
	ASF1_TELEPORT = 65536, ///< allows kAI to teleport on SetupAISpawnFlags
	ASF1_CASTSHADOW = 131072, ///< sets AF_CASTSHADOW on SetSpawnParams
	ASF1_TELEPORTWAIT = 262144, ///< allows enemy to move around for 1.5 - 4.5 seconds before teleporting back in.
	ASF1_USESTRONGATTACKS = 524288, ///< anim_aiMelee1
	ASF1_USEWEAKATTACKS = 1048576, ///< anim_aiAltMelee1
	ASF1_SNIPER = 2097152,
	ASF1_MELTONDEATH = 4194304, ///< allows melt effect and regeneration
	ASF1_AVOIDWATER = 8388608, ///< sets AF_AVOIDWATER on SetSpawnParams
	ASF1_FLYING = 16777216, ///< NOT USED
	ASF1_TELEPORTAVOIDWATER = 33554432,
	ASF1_TELEPORTAVOIDCLIFFS = 67108864,
	ASF1_TRIGGERSTUFF = 134217728, ///< Sets AF_TRIGGERSTUFF on SetupSpawnParams
	ASF1_CANNOTCAUSEAFIGHT = 268435456, ///< if another actor was damaged by this actor with this flag set then other actor will not target this actor.
	ASF1_NOWALLCOLLISION = 536870912, ///< NOT USED
	ASF1_SCREENSHAKE = 1073741824, ///< Used in floor mover scripts to shake screen.
	ASF1_RESPAWNANIMATION = -2147483648 ///< Enables respawning animation effect
};

enum EnumActorSpawnFlags2
{
	ASF2_DROPITEM_MASK1 = 1, ///< Explosive shells
	ASF2_DROPITEM_MASK2 = 2, ///< Grenade
	ASF2_DROPITEM_MASK3 = 4, ///< Medium Health
	ASF2_DROPITEM_MASK4 = 8, ///< Full Health
	ASF2_DROPITEM_MASK5 = 16, ///< Ultra Health
	ASF2_DROPITEM_MASK6 = 32, ///< Small Health
	ASF2_DROPITEM_MASK7 = 64, ///< Large Health
	ASF2_DROPITEM_MASK8 = 128, ///< Minigun ammo
	ASF2_DROPITEM_MASK9 = 256, ///< Mortal Wound
	ASF2_DROPITEM_MASK10 = 512, ///< 4 Rockets
	ASF2_DROPITEM_MASK11 = 1024, ///< Shotgun Shells
	ASF2_DROPITEM_MASK12 = 2048, ///< Energy Cell
	ASF2_DROPITEM_MASK13 = 4096, ///< Large Energy Cell
	ASF2_DROPITEM_MASK14 = 8192, ///< Clip
	ASF2_REMOVEONCOMPLETION = 16384, ///< Sets AF_REMOVEONCOMPLETION
	ASF2_NOBLOOD = 32768,
	ASF2_HOLDTRIGGERANIMATION = 65536,
	ASF2_PROJECTILEATTACK3 = 131072, ///< crouch rifle Fire (anim_aiRangeAttack7)
	ASF2_PROJECTILEATTACK4 = 262144, ///< (anim_aiRangeAttack8)
	ASF2_DROPITEMONDAMAGE = 524288, ///< NOT USED
	ASF2_NOAUTOMAPDRAW = 1048576,  ///< if map all or show enemies cheats are on then will not draw this actor on the automap.
	ASF2_ALTERNATEMOVES = 2097152, ///< is for holding two handed weapons
	ASF2_UNUSED1 = 4194304, ///< NOT USED
	ASF2_UNUSED2 = 8388608, ///< NOT USED
	ASF2_PROJECTILEATTACK5 = 16777216, ///< Stand Rifle Fire (anim_aiRangeAttack5)
	ASF2_PROJECTILEATTACK6 = 33554432, ///< Pipe Blow (anim_aiRangeAttack6)
	ASF2_MORTALWOUNDIMPACT = 67108864, ///< Can be hit by a super arrow shot and if ASF2_DROPITEM_MASK9 is on has a chance to drop a mortal wound
	ASF2_STAYINWATER = 134217728, ///< sets AF_STAYINWATER on SetSpawnParams
	ASF2_WARPDEATH = 268435456, ///< NOT USED
	ASF2_STOREWARPRETURN = 536870912, ///< Used in portal scripts
	ASF2_PROJECTILEATTACK7 = 1073741824, ///< Grenade Throw (anim_aiRangeAttack3)
	ASF2_PROJECTILEATTACK8 = -2147483648 ///< High Priest Homing Blue Flame (anim_aiRangeAttack4)
};

enum EnumActorSpawnFlags3
{
	ASF3_RETURNWARP = 1, ///< Used in portal scripts
	ASF3_PLAYTRIGGERANIMONCE = 2, ///< MarkPersistentBit(false) when activated
	ASF3_REGENERATEFROMSTART = 4, ///< Regen from starting position
	ASF3_WALKINSTRAIGHTLINE = 8, ///< Set animation to Blend(ANIM_WALKING, (m_animSpeed * m_animScalar), 10, ANF_LOOP|ANF_ROOTMOTION); and do nothing else.
	ASF3_KILLOUTSIDEOFVIEW = 16, ///< NOT USED
	ASF3_NOTHINKER = 32, ///< AI will not function. Actors will not update movement. Actors OnBeginLevel will set their animation to ANIM_SPECIAL_EVENT.
	ASF3_AVOIDPLAYERS2 = 64, ///< NOT USED
	ASF3_NOVIOLENTDEATH = 128, ///< ANIM_AIDEATHSTAND and ANIM_DEATHSTANDALT will not play when kAI is killed.
	ASF3_PROJECTILEATTACK9 = 256, ///< Demon chest Hadoken (anim_aiRangeAttack9)
	ASF3_PROJECTILEATTACK10 = 512, ///< High Priest Lightning Red Flames (anim_aiRangeAttack10)
	ASF3_MAKESPAWNANIMVISIBLE = 1024, ///< clears actor flags: ~(AF_HIDDEN|AF_DISABLED)
	ASF3_NODRAWONCAMERA = 2048 ///< Will not draw this actor when viewing from camera unless camera flags has CMF_SHOW_HIDDEN_OBJECTS.
};

enum EnumPlayerFlags
{
	PF_NOCLIP = 1,
	PF_FLY = 2,
	PF_DEAD = 4,
	PF_GOD = 8, ///< Is reset when level beings
	PF_JUMPING = 16, ///< is jumping (moving up). flag is off when reached max jump height or let go of jump button.
	PF_HASJUMPED = 32,
	PF_INWARPAREA = 64, ///< in sector area with AAF_TELEPORT flag.
	PF_CLIMBTHRUST = 128,
	PF_NOAIRFRICTION = 256,
	PF_CRAWLING = 512,
	PF_PREVENTDEATHCAM = 1024, ///< will stop the death cinematic or the deadAnimView from triggering when the player dies.
	PF_FIREDPROJECTILE = 2048, ///< set when FireProjectile is called. Cleared OnTick if weapon is not in WS_FIRE state and player is not locked.
	PF_FALLINGDEATHPIT = 4096, ///< currently falling in a death pit. Cleared after level begins.
	PF_WEAPONSTEAL = 8192, ///< on when campaigner steals weapon
	PF_NOSECTORMUSIC = 16384, ///< disables music changes when changing sectors
	PF_NOTOUCH = 32768, ///< disables invoking onTouch callbacks
    PF_NOCEILINGGLIDE = 65536 ///< disables the ceiling glide glitch
};

enum EnumPlayerStates
{
    PS_WALKING = 0,
    PS_JUMPING = 1,
    PS_CLIMBING = 2,
    PS_SWIMMING = 3,
    PS_UNDERWATER = 4,
    PS_FALLDEATH = 5,
    PS_ANTIGRAVITY = 6
};

enum EnumCheatFlags
{
	GC_BIG_HEADS = 1 << 0,
	GC_TINY_ENEMY = 1 << 1,
	GC_INFINITE_AMMO = 1 << 2,
	GC_PURDY_COLORS = 1 << 3,
	GC_SPIRIT_MODE = 1 << 4,
	GC_INVINCIBILITY = 1 << 5,
	GC_FLIGHT = 1 << 6,
	GC_DISCO = 1 << 7,
	GC_INFINITE_LIVES = 1 << 8,
	GC_ALL_MAP = 1 << 9,
	GC_SHOW_ENEMIES = 1 << 10,
	GC_NOCLIP = 1 << 11,
};

enum EnumAIFlags
{
	AIF_ATTACKING = 1, ///< playing an attacking animation
	AIF_WASSOLID = 2,
	AIF_FIRSTATTACK = 4,
	AIF_HEARDLOUDNOISE = 8,
	AIF_BLOWNAWAY = 16, ///< being blown away by explosion
	AIF_GOBACKTOLEASH = 32,
	AIF_RESSURECT = 64,
	AIF_FEIGNDEATH = 128,
	AIF_REGENERATE = 256,
	AIF_SEETARGET = 512,
	AIF_NOCHASE = 1024, ///< disable chase logic
	AIF_REGENERATEANIM = 2048,
	AIF_NOTHINK = 4096, ///< don't run ai logic
	AIF_RUNNING = 8192, ///< Is playing running animation
	AIF_GETATTENTION = 16384,
	AIF_REGENANIMDELAY = 32768,
	AIF_HEARDQUIETNOISE = 65536,
	AIF_AWAYFROMLEASH = 131072,
	AIF_TELEPORTAWAY = 262144, ///< playing teleport out animation
	AIF_TELEPORTMOVESLOW = 524288, ///< chasing while underground
	AIF_TELEPORTING = 1048576, ///< in teleport state. ignore all chase logic
	AIF_TELEPORTIN = 2097152, ///< playing teleport in animation
	AIF_WAITFORCYCLE = 4194304, ///< prevent other animations from interrupting until the current one finishes
	AIF_DAMAGEPANIC = 8388608 ///< become aggressive when target is outside its active threshold (good for forcing AI to attack their target)
};

enum EnumImpactType
{
	IT_DEFAULT = 0,
	IT_WATER = 1,
	IT_METAL = 2,
	IT_STONE = 3,
	IT_FLESH_HUMAN = 4,
	IT_FLESH_CREATURE = 5,
	IT_FLESH_UNDEAD = 6, ///< AKA IT_FLESH_WATER
	IT_LAVA = 7,
	IT_SLIME = 8,
	IT_FORCEFIELD = 9
};

enum EnumGameFontType
{
	GFT_BIG = 0,
	GFT_SMALL = 1,
	GFT_NUMBERS = 2,
	GFT_TTF = 3
};

enum EnumClipResultFlags
{
	CRF_NOCOLLISION = 0,
	CRF_FLOOR = 1, ///< made contact with a floor
	CRF_CEILING = 2, ///< made contact with a ceiling
	CRF_WALL = 4, ///< made contact with an edge (sector edge that isn't linked to another sector)
	CRF_OBJECT = 8, ///< made contact with an actor
	CRF_MESH = 16, ///< made contact with a static object
	CRF_ADJUST = 32, ///< z-axis was adjusted (ceiling or floor)
	CRF_WALLRADIUS = 64 ///< made contact with an edge during the wall radius collision test
};

enum EnumWeaponStates
{
	WS_IDLE = 0,
	WS_RAISE = 1,
	WS_LOWER = 2,
	WS_FIRE = 3, ///< Is currently firing
	WS_HOLDSTER = 4, ///< Set when dead (with no death cinematic) or when climbing. Should set weapon anim to ANIM_WEAPONSWAPOUT if you set this state manually.
	WS_WALK = 5, ///< NOT USED
	WS_RUN = 6, ///< NOT USED
	WS_DISCHARGE = 7, ///< set after OnEndFire is called. If was in WS_FIRE state and not pressing the Attack button.
	WS_FIREUNDERWATER = 8 ///< NOT USED
};

enum EnumInputActions
{
	IA_ATTACK = 0,
	IA_JUMP = 1,
	IA_FORWARD = 2,
	IA_BACKWARD = 3,
	IA_STRAFELEFT = 4,
	IA_STRAFERIGHT = 5,
	IA_WEAPNEXT = 6,
	IA_WEAPPREV = 7,
	IA_MAPZOOMIN = 8,
	IA_MAPZOOMOUT = 9,
	IA_CUSTOM1 = 10,
	IA_CUSTOM2 = 11
};

enum EnumPlayerButtons
{
	BC_ATTACK = 1,
	BC_JUMP = 2,
	BC_FORWARD = 4,
	BC_BACKWARD = 8,
	BC_STRAFELEFT = 16,
	BC_STRAFERIGHT = 32,
	BC_WEAPONRIGHT = 64,
	BC_WEAPONLEFT = 128,
	BC_MAPZOOMIN = 256,
	BC_MAPZOOMOUT = 512,
	BC_CUSTOM1 = 1024,
	BC_CUSTOM2 = 2048
};

enum EnumPlayerConButtons
{
	CBC_WEAPON1 = 1,
	CBC_WEAPON2 = 2,
	CBC_WEAPON3 = 4,
	CBC_WEAPON4 = 8,
	CBC_WEAPON5 = 16,
	CBC_WEAPON6 = 32,
	CBC_WEAPON7 = 64,
	CBC_WEAPON8 = 128,
	CBC_WEAPON9 = 256,
	CBC_WEAPON10 = 512,
	CBC_WEAPON11 = 1024,
	CBC_WEAPON12 = 2048,
	CBC_WEAPON13 = 4096,
	CBC_WEAPON14 = 8192,
	CBC_AUTOMAP = 16384,
	CBC_CHANGEAMMO = 32768,
	CBC_RUNWALK = 65536,
	CBC_MENUUP = 131072,
	CBC_MENUDOWN = 262144,
	CBC_MENULEFT = 524288,
	CBC_MENURIGHT = 1048576,
	CBC_MENUSELECT = 2097152,
	CBC_MENUDESELECT = 4194304,
	CBC_MENUBACK = 8388608,
	CBC_MENUCANCEL = 16777216,
	CBC_MENUACTIVATE = 33554432
};

enum EnumGameButtonEvents
{
	GBE_MENU_UP = 1,
	GBE_MENU_RIGHT = 2,
	GBE_MENU_DOWN = 4,
	GBE_MENU_LEFT = 8,
	GBE_MENU_SELECT = 16,
	GBE_MENU_CANCEL = 32,
	GBE_MENU_BACK = 64,
	GBE_MENU_ACTIVATE = 128,
	GBE_MENU_DESELECT = 256,
	GBE_MENU_MOUSESELECT = 512
};

enum EnumDifficulty
{
	DIFFICULTY_EASY = 0,
	DIFFICULTY_NORMAL = 1,
	DIFFICULTY_HARD = 2,
	DIFFICULTY_HARDCORE = 3
};

enum EnumClipFlags
{
	CF_CLIPEDGES = 1, ///< clip movement against edges that don't link to sectors
	CF_IGNOREBLOCKERS = 2, ///< don't clip edges belonging to blocking sectors
	CF_DROPOFF = 4, ///< allows passing through platforms or ledges
	CF_NOENTERWATER = 8, ///< block all edges that links to a water sector
	CF_NOEXITWATER = 16, ///< block all edges that links to a non-water sector
	CF_NOCLIPSTATICS = 32, ///< don't collide with static models
	CF_NOCLIPACTORS = 64, ///< don't collide with dynamic objects/actors
	CF_WALKWALLS = 128, ///< don't restrict movement to steep slopes
	CF_COLLIDEFLOORS = 256, ///< project and clip movement against non-flat floors
	CF_HITSCAN = 512, ///< performs a single-pass trace. useful for hitscans
	CF_ALLOWCLIMB = 1024, ///< collide with sectors flagged as climbable
	CF_ALLOWCRAWL = 2048, ///< collide with sectors flagged as crawlable
	CF_NOSTEPDOWN = 4096, ///< don't clamp z-axis when walking down slopes
	CF_NOSLOPESTEP = 8192, ///< don't project z-axis movement along slopes
	CF_COLLIDEHEIGHT = 16384, ///< clip against ceilings
	CF_COLLIDECORPSES = 32768, ///< clip against actors flagged as dead
	CF_NOEXITWALLS = 65536, ///< clip all edges, regardless if they link to another sector or not
	CF_NOCOLLIDEFUNC = 131072, ///< don't invoke the OnCollide callback on the moving object
	CF_NOFLOORADJUST = 262144, ///< don't keep z-axis above floor plane
	CF_NOCEILINGADJUST = 524288, ///< don't keep z-axis below ceiling plane
	CF_COLLIDEWATER = 1048576, ///< clip movement against the water surface
	CF_USEWALLRADIUS = 2097152, ///< clip and project movement away from walls based on wall radius
	CF_NOCLIPTARGETACTORS = 4194304, ///< don't clip actors that are targeted by moving object
	CF_COLLIDETRIGGERS = 8388608, ///< block edges belonging to a trigger
	CF_STANDONOBJECTS = 16777216, ///< allow vertical clipping of objects
	CF_GREASESLIDEOBJECTS = 33554432, ///< always keep movement projected away from collided objects
	CF_ALLOWRESTRICTEDAREAS = 67108864, ///< don't collide with edges belonging to a restricted sector
	CF_COLLIDECLIFFS = 134217728, ///< collide with non-walkable floors
	CF_CHECKLINKEDBRIDGES = 268435456, ///< do extensive checks against overlapping bridge sectors
	CF_POLYCOLLISION = 536870912 ///< clip movement against all model polygons of an object
};

enum EnumWaterLevel
{
	WLT_INVALID = 0, ///< Not in water sectors
	WLT_OVER = 1, ///< In water sector but over the water height
	WLT_BETWEEN = 2, ///< In water sector and floating above the water
	WLT_UNDER = 3 ///< In water sector and under the water height
};

/**
 * @brief Lerp type when doing AutoPlayPositionTrack, AutoPlayRotationTrack, or AutoPlayBlendTrack.
 * When a view has one of those active the view's time variable is then increased by GAME_DELTA_TIME.
 */
enum EnumCameraLerpType
{
	CMLT_NONE = 0, ///< time is set to time / speed.
	CMLT_LINEAR = 1, ///< time is set to time / speed.
	CMLT_LINEARLOOP = 2, ///< time is set to time / speed. If time is > 1.0 then time -= 1.0
	CMLT_COSINE = 3, ///< time will never be higher than speed. time = CosTween(time * (1.0f / speed));
	CMLT_COSINE_POW = 4 ///< time will never be higher than speed. time = CosTween(Pow(time * (1.0f / speed), 3));
};

enum EnumCameraFlags
{
	CMF_NO_INITIAL_FADEOUT = 1,
	CMF_NO_LETTERBOX = 2,
	CMF_LOCK_PLAYER = 4,
	CMF_UNLOCK_PLAYER_ON_FINISH = 8,
	CMF_INITIAL_FADEIN = 16,
	CMF_SHOW_CREDITS = 32,
	CMF_CHANGE_MAP_AFTER_FADE = 64,
	CMF_SHOW_HIDDEN_OBJECTS = 128,
	CMF_NO_INITIAL_FADEIN = 256
};

enum EnumCameraStates
{
	CAMS_IDLE = 0,
	CAMS_FADEOUT = 1,
	CAMS_FADEIN = 2,
	CAMS_ACTIVE = 3,
	CAMS_ACTIVE_TO_FADEOUT = 4,
	CAMS_FADEBACK_TO_CLIENT = 5,
	CAMS_RESTORE_TO_CLIENT = 6
};

enum EnumAreaFlags
{
	AAF_WATER = 1,
	AAF_BLOCK = 2,
	AAF_TOGGLE = 4, ///< if on and AAF_BLOCK is on then sectors won't be marked on automap until it's unblocked. Used for door areas.
	AAF_CLIFF = 8, ///< is a wall
	AAF_CLIMB = 16, ///< climb up sectors faster than AAF_LADDER
	AAF_ONESIDED = 32, ///< Bridge
	AAF_CEILING = 64,
	AAF_CRAWL = 128,
	AAF_ENTERCRAWL = 256, ///< Exactly the same as AAF_CRAWL
	AAF_HIDDEN = 512,
	AAF_ENTERED = 1024, ///< Not shown in Editor. Used in kex editor only for fill sector commands. When map is saved in kex editor all sectors will have this flag off.
	AAF_SECRET = 2048,
	AAF_RESTRICTED = 4096, ///< kAI can't enter the area
	AAF_SLOPETEST = 8192, ///< overrides AAF_CLIFF flag. If the sectors floor plane up direction is <= 0.5 then is a wall (a wall is the same as the AAF_CLIFF flag).
	AAF_DEATHPIT = 16384,
	AAF_MAPPED = 32768,
	AAF_EVENT = 65536,
	AAF_REPEATABLE = 131072, ///< Unused
	AAF_TELEPORT = 262144,
	AAF_DAMAGE = 524288,
	AAF_DRAWSKY = 1048576,
	AAF_TELEPORTAIR = 2097152,
	AAF_LAVA = 4194304,
	AAF_EVENTSOUND = 8388608,
	AAF_ANTIGRAVITY = 16777216,
	AAF_LADDER = 33554432, ///< climb up sectors slower than AAF_CLIMB
	AAF_CHECKPOINT = 67108864,
	AAF_SAVEGAME = 134217728,
	AAF_WARPRETURN = 268435456, ///< Unused
	AAF_SHALLOWWATER = 536870912,
	AAF_DRAWSUN = 1073741824,
	AAF_STOREWARPRETURN = -2147483648  ///< Unused
};

namespace kexVibrationPlayer
{
	enum channel_e
	{
		CHANNEL_WEAPON = 0,
		CHANNEL_BODY = 1,
		CHANNEL_DAMAGE = 2,
		CHANNEL_WORLD = 3
	};

	enum position_e
	{
		POSITION_LEFT = 0,
		POSITION_RIGHT = 1,
		POSITION_NEUTRAL = 2
	};
}

/**
 * @class array<T>
It is possible to declare array variables with the array identifier followed by the type of the elements within angle brackets.

Example:

@code{.cpp}
  array<int> a, b, c;
  array<Foo@> d;
@endcode

a, b, and c are now arrays of integers, and d is an array of handles to objects of the Foo type.

When declaring arrays it is possible to define the initial size of the array by passing the length as a parameter to the constructor. The elements can also be individually initialized by specifying an initialization list. Example:

@code{.cpp}
  array<int> a;           // A zero-length array of integers
  array<int> b(3);        // An array of integers with 3 elements
  array<int> c(3, 1);     // An array of integers with 3 elements, all set to 1 by default
  array<int> d = {5,6,7}; // An array of integers with 3 elements with specific values
@endcode

Multidimensional arrays are supported as arrays of arrays, for example:

@code{.cpp}
  array<array<int>> a;                     // An empty array of arrays of integers
  array<array<int>> b = {{1,2},{3,4}}      // A 2 by 2 array with initialized values
  array<array<int>> c(10, array<int>(10)); // A 10 by 10 array of integers with uninitialized values
@endcode

Each element in the array is accessed with the indexing operator. The indices are zero based, i.e. the range of valid indices are from 0 to length - 1.

@code{.cpp}
    a[0] = some_value;
@endcode

When the array stores handles the elements are assigned using the handle assignment.

@code{.cpp}
  // Declare an array with initial length 1
  array<Foo@> arr(1);
@endcode

@code{.cpp}
    // Set the first element to point to a new instance of Foo
    @arr[0] = Foo();
@endcode

Arrays can also be created and initialized within expressions as anonymous objects.

@code{.cpp}
  // Call a function that expects an array of integers as input
  foo(array<int> = {1,2,3,4});
@endcode

 */
template <class T>
class array	// class array<T>
{
public:
	void insertAt(uint index, const T&in value); ///< Inserts a new element into the array at the specified index.
	void insertAt(uint index, const T[]&inout arr); ///< Inserts another array of elements into the array at the specified index.
	void insertLast(const T&in value); ///< Appends an element at the end of the array.
	void removeAt(uint index); ///< Removes the element at the specified index.
	void removeLast(); ///< Removes the last element of the array.
	void removeRange(uint start, uint count); ///< Removes count elements starting from start.
	uint length() const; ///< Returns the length of the array.
	void reserve(uint length);
	void resize(uint length); ///< Sets the new length of the array.
	void sortAsc(); ///< Sorts the elements in the array in ascending order. For object types, this will use the type's opCmp method.
	void sortAsc(uint startAt, uint count); ///< Sorts only the elements starting at index startAt and the following count elements in the array in ascending order. For object types, this will use the type's opCmp method.
	void sortDesc(); ///< Sorts the elements in the array in descending order. For object types, this will use the type's opCmp method.
	void sortDesc(uint startAt, uint count); ///< Sorts only the elements starting at index startAt and the following count elements in the array in descending order. For object types, this will use the type's opCmp method.
	void reverse(); ///< Reverses the order of the elements in the array.

    /**
    * @brief Returns the index of the first element that has the same value as the wanted value.
    * For object types, this will use the type's opEquals or opCmp method to compare the value. For arrays of handles any null handle will be skipped.
    * If no match is found will return a negative value.
    */
	int find(const T&in value) const;

    /**
    * @brief Returns the index of the first element that has the same value as the wanted value.
    * For object types, this will use the type's opEquals or opCmp method to compare the value. For arrays of handles any null handle will be skipped.
    * If no match is found will return a negative value.
    */
	int find(uint startAt, const T&in value) const;

    /**
    * @brief Searches for a matching address. These are especially useful for arrays of handles where specific instances of objects are desired, and not just objects that happen to have equal value.
    * If no match is found will return a negative value.
    */
	int findByRef(const T&in value) const;

    /**
    * @brief Searches for a matching address. These are especially useful for arrays of handles where specific instances of objects are desired, and not just objects that happen to have equal value.
    * If no match is found will return a negative value.
    */
	int findByRef(uint startAt, const T&in value) const;
	bool isEmpty() const;
	T& opIndex(uint index);
	const T& opIndex(uint index) const;
	T[]& opAssign(const T[]&in);
	bool opEquals(const T[]&in) const;
    funcdef bool less(const ?&in a, const ?&in b); ///<  sorting function for sort
	void sort(less&in, uint startAt = 0, uint count = uint ( - 1 )); ///< sorts array using the passed in less function
};

/**
 * @class kStr
 * @brief String class functions
 */
class kStr
{
public:
	kStr();
	kStr(const kStr&in s);
	uint Hash() const; ///< Returns HashID from this instance
	kStr& ToUpper(); ///< Converts string to upper case characters
	kStr& ToLower(); ///< Converts string to lower case characters
	int Atoi() const; ///< Converts string to int
	float Atof() const; ///< Converts string to float
	bool Contains(const kStr&in) const; ///< contains the string
	bool ContainsNoCase(const kStr&in) const; ///< contains the string ignoring case
	bool IsEmpty() const; ///< length of string is 0
	uint64 IndexOf(const kStr&in s) const; ///< Reports the zero-based index of the first occurrence of a specified string within this instance. The method returns uint64(-1) if the string is not found in this instance.
	uint64 Length() const; ///< Returns the length of the string
    kStr Substr(uint64 start, uint64 length) const; ///< Return a substring from the current string. Will return the current string if start or length indexes are out of range.
    kStr ReplaceSubstr(const kStr &in from, const kStr &in to) const; ///< Returns a new kStr that replaced all occurrences of from with to.
    bool StartsWith(const kStr &in s) const; ///< Returns true if this string starts with s
    bool EndsWith(const kStr &in s) const; ///< Returns true if this string ends with s
    const int8 opIndex(const uint64 i) const; ///< Returns the ASCII code of the character at the strings index
    int8 &opIndex(const uint64 i); ///< Get/Set the ASCII code of the character at the strings index
	bool opEquals(const kStr&in s) const;
	kStr& opAssign(const kStr&in s);
	kStr opAdd(const kStr&in s) const;
	kStr opAdd(bool b) const;
	kStr opAdd(int i) const;
	kStr opAdd(uint i) const;
	kStr opAdd(int64 i) const;
	kStr opAdd(uint64 i) const;
	kStr opAdd(int16 i) const;
	kStr opAdd(uint16 i) const;
	kStr opAdd(float f) const;
	kStr& opAddAssign(const kStr&in s);
	kStr& opAddAssign(bool b);
};

/**
 * @class kAngle
 * @brief Angle functions
 */
class kAngle
{
public:
	kAngle();
	kAngle(float rads);
	kAngle(const kAngle&in other);
	float Diff(const float rads) const;
	float Diff(const kAngle&in other) const;
	float Interpolate(const float a, const float b) const;
	kAngle opAdd(const float f) const;
	kAngle& opAddAssign(const float f);
	kAngle opSub(const float f) const;
	kAngle& opSubAssign(const float f);
	kAngle opAdd(const kAngle&in a) const;
	kAngle& opAddAssign(const kAngle&in a);
	kAngle opSub(const kAngle&in a) const;
	kAngle& opSubAssign(kAngle&in a);
	kAngle& opAssign(const float f);
	kAngle& opAssign(const kAngle&in a);
	kAngle opNeg() const;
	float opImplConv();
};

/**
 * @class kVec3
 * @brief Representation of 3D vectors and points.
 */
class kVec3
{
public:
	kVec3();
	kVec3(float x, float y, float z);
	kVec3(const kVec3&in v);
	kVec3& Normalize(); ///< Makes this vector have a magnitude of 1
	kVec3 Cross(const kVec3&in v) const; ///< Cross Product of two vectors
	float Dot(const kVec3&in v) const; ///< Dot Product of two vectors
	float Length() const; ///< Returns the length of this vector. Exactly the same as Unit()
	float LengthSq() const; ///< Returns the squared length of this vector. Exactly the same as UnitSq()
	float DistanceSq(const kVec3&in other) const; ///< Returns the squared distance between this instance and other
	float ToYaw(); ///< Returns the Yaw direction in Rads
	float ToPitch(); ///< Returns the Pitch direction in Rads
	void Clear(); ///< Sets x, y and z components to 0
	void Set(const float x, const float y, const float z); ///< Set x, y and z components of this kVec3
	kVec3 Lerp(const kVec3&in other, const float t) const; ///< Linearly interpolates between two vectors
	kVec3& Lerp(const kVec3&in other, const float t); ///< Linearly interpolates between two vectors
	kVec3& Project(const kVec3&in normal, const float value); ///< Projects a vector onto another vector
	kVec3& Reflect(const kVec3&in normal, const float energyFactor); ///< Reflects a vector off the plane defined by a normal
	kVec3& Randomize(const float value); ///< Randomizes x, y, z, components by value
	kVec3& CubicCurve(const kVec3&in pt1, const float value, const kVec3&in pt2);
	kVec3& QuadraticCurve(const kVec3&in pt1, const float value, const kVec3&in pt2, const kVec3&in pt3);
	kVec3 opAdd(const kVec3&in v) const;
	kVec3 opAdd(const float f) const;
	kVec3& opAddAssign(const kVec3&in v);
	kVec3& opAddAssign(const float f);
	kVec3 opNeg();
	kVec3 opSub(const kVec3&in v) const;
	kVec3 opSub(const float f) const;
	kVec3& opSubAssign(const kVec3&in v);
	kVec3& opSubAssign(const float f);
	kVec3 opMul(const kVec3&in v);
	kVec3 opMul(const float val);
	kVec3& opMulAssign(const kVec3&in v);
	kVec3& opMulAssign(const float f);
	kVec3 opDiv(const kVec3&in v);
	kVec3 opDiv(const float val);
	kVec3& opDivAssign(const kVec3&in v);
	kVec3& opDivAssign(const float f);
	kVec3& opAssign(const kVec3&in v);
	float opIndex(int i) const;
	float& opIndex(int i);
	float Distance(const kVec3&in other) const; ///< Returns the distance between this instance and other vector
	kStr ToString();
	kVec3 opMul(const kQuat&in rot) const;
	kVec3& opMulAssign(const kQuat&in rot);
	kQuat ToQuaternion() const;
	kQuat ToQuat() const;
	float Unit() const; ///< Returns the length of this vector. Exactly the same as Length()
	float UnitSq() const; ///< Returns the squared length of this vector. Exactly the same as LengthSq()
	float x;
	float y;
	float z;
};

/**
 * @class kQuat
 * @brief Quaternions used to represent rotations
 */
class kQuat
{
public:
	kQuat();
	kQuat(float angle, float x, float y, float z);
	kQuat(float angle, kVec3&in vector);
	kQuat(float rotX, float rotY, float rotZ);
	kQuat(const kQuat&in other);
	kQuat& Normalize();
	kQuat& NormalizeNoInvSqrt();
	kQuat Slerp(const kQuat&in rot, float t) const;
	kQuat Inverse() const;
	void GetAngles(float&out yaw, float&out pitch, float&out roll);
	kQuat Diff(const kQuat&in rot) const;
	void Set(const float x, const float y, const float z, const float w);
	void Clear(); ///< x,y,z = 0.0  w = 1.0
	kQuat opAdd(const kQuat&in rot);
	kQuat opSub(const kQuat&in rot);
	kQuat opMul(const kQuat&in rot);
	kQuat& opAssign(const kQuat&in rot);
	kQuat& opMulAssign(const kQuat&in rot);
	kStr ToString() const;
	float x;
	float y;
	float z;
	float w;
};

/**
 * @class kPlane
 * @brief Plane functions
 */
class kPlane
{
public:
	kPlane();
	kPlane(const float a, const float b, const float c, const float d);
	kPlane(const kVec3&in a, const kVec3&in b, const kVec3&in c);
	kPlane(const kVec3&in a, const kVec3&in b);
	kPlane(const kAngle&in a);
	const kVec3& Normal() const;
	kVec3& Normal();
	float Dot(const kVec3&in point) const;
	float Dot(const kPlane&in plane) const;
	float Distance(const kVec3&in point) const; ///< 0 = PSIDE_ON. > 0 is PSIDE_FRONT. < 0 PSIDE_BACK.
	float ToYaw() const; ///< Yaw of this plane.

    /**
     * @brief Returns true if yaw is facing toward the plane. Usually used for climbing sectors.
     * @code{.cpp}
     * bool Climbable(const float yaw) const
     * {
     *     return (floorPlane.c <= 0.5f && flags & AAF_CLIMB && floorPlane.IsFacing(yaw));
     * }
     * @endcode
     */
	bool IsFacing(const float yaw) const;
	const int PointOnSide(const kVec3&in point) const; ///< Returns EnumPlaneSide. If point is in front, behind or on the plane.
};

class kColor ///< Not used (included automatically from kexengine)
{
public:
	kColor();
	kColor(const kColor&in c);
	kColor(uint8 r, uint8 g, uint8 b, uint8 a);
	kColor(const kColor&in rgb, uint8 a);
	kColor(uint8 rgb, uint8 a);
	kColor(uint rgba);
	kColor(float r, float g, float b);
	uint DwColor() const;
	kVec3 ToVec3() const;
	void FromVec3(const kVec3&in v);
	kVec3 ToVec3Linear() const;
	void FromVec3Linear(const kVec3&in v);
	void SetGrayScale();
	void SetSaturation(float);
	void SetLuminance(float);
	float GetSaturation() const;
	float GetLuminance() const;
	kColor& opAssign(const kColor&in c);
	void LerpRGB(const kColor&in c, float t);
	kColor ToPreMultiplied() const;
	void PreMultiply();
	void RGBToHSV(float&out hue, float&out sat, float&out result) const;
	void HSVToRGB(float hue, float sat, float val);
	void RGBToHSL(float&out hue, float&out sat, float&out lit) const;
	void HSLToRGB(float hue, float sat, float lit);
	bool opEquals(const kColor&in c) const;
	kColor opAdd(const kColor&in c) const;
	kColor opSub(const kColor&in c) const;
	kColor opMul(const kColor&in c) const;
	kColor opMul(float f) const;
	kColor& opAddAssign(const kColor&in c);
	kColor& opSubAssign(const kColor&in c);
	kColor& opMulAssign(const kColor&in c);
	kColor& opMulAssign(float f);
	uint8 r;
	uint8 g;
	uint8 b;
	uint8 a;
};

class kBitDelta ///< Not used (garbage included automatically from kexengine)
{
public:
	bool WriteByte(const uint8 i);
	uint8 ReadByte();
};

class kexTranslation ///< Not used (garbage included automatically from kexengine)
{
public:
	uint GetGroupIndex(const kStr&in groupName);
	kStr GetString(const kStr&in key, kexLocPlatform_e plat) const;
	kStr GetString(int key, kexLocPlatform_e plat) const;
	kStr GetGroupString(const kStr&in key, uint groupIndex, uint plat) const; ///< plat: kexLocPlatform_e
	kStr GetGroupString(int key, uint groupIndex, uint plat) const; ///< plat: kexLocPlatform_e
	kStr TranslateString(const kStr&in key, kexLocPlatform_e plat) const;
	kStr TranslateString(const kStr&in key) const; ///< Same as Game.GetLocalizedText
	kStr TranslateGroupString(const kStr&in key, uint groupIndex, uint plat) const; ///< plat: kexLocPlatform_e
	kStr TranslateStringWithArgs(const kStr&in key, const kDict&in pairs, uint plat) const; ///< plat: kexLocPlatform_e
	kStr TranslateGroupStringWithArgs(const kStr&in key, const kDict&in pairs, uint groupIndex, uint plat) const; ///< plat: kexLocPlatform_e
};

class ref
{
public:
	~ref();
	ref();
	ref(const ref&in);
	ref(const ?&in);
	void opCast(?&out);
	ref& opHndlAssign(const ref&in);
	ref& opHndlAssign(const ?&in);
	bool opEquals(const ref&in) const;
	bool opEquals(const ?&in) const;
};

class kScriptObject
{
public:
	ref obj;
};

class ScriptObject
{
public:
	void OnTick();
	void OnSpawn();
};

class ScriptObjectWeapon
{
public:
	void OnBeginFire();
	void OnFire();
	void OnEndFire();
	void OnLower();
	void OnRaise();
	void OnHoldster();
};

/**
 * @class kDict
 * @brief Editable Dictionary object that holds keys and values
 */
class kDict
{
public:
	void Add(const kStr&in key, const kStr&in value); ///< Adds a new key/value
	void Empty(); ///< Removes all keys/values
	void SetValue(const kStr&in key, const kStr&in value); ///< Sets the value for the specified key
	const bool HasKey(const kStr&in key); ///< Returns true if key exists
	bool GetFloat(const kStr&in key, float&out floatResult, const float defaultValue = 0); ///< Returns true if found the key as a float type
	bool GetInt(const kStr&in key, int&out intResult, const int defaultValue = 0); ///< Returns true if found the key as a int type
	bool GetBool(const kStr&in key, bool&out boolResult, const bool defaultValue = false); ///< Returns true if found the key as a bool type
	bool GetString(const kStr&in key, kStr&out stringResult); ///< Returns true if found the key as a kStr type
	bool GetVector(const kStr&in key, kVec3&out vectorResult); ///< Returns true if found the key as a kVec3 type
};

/**
 * @class kDictMem
 * @brief Read only Dictionary object that holds keys and values
 */
class kDictMem
{
public:
	bool GetFloat(const kStr&in key, float&out floatResult, const float defaultValue = 0); ///< Returns true if found the key as a float type
	bool GetInt(const kStr&in key, int&out intResult, const int defaultValue = 0); ///< Returns true if found the key as a int type
	bool GetBool(const kStr&in key, bool&out boolResult, const bool defaultValue = false); ///< Returns true if found the key as a bool type
	bool GetString(const kStr&in key, kStr&out stringResult); ///< Returns true if found the key as a kStr type
	bool GetVector(const kStr&in key, kVec3&out vectorResult); ///< Returns true if found the key as a kVec3 type
};

/**
 * @class kSelectionListInt
 * @brief For selecting a int value based on weights
 */
class kSelectionListInt
{
public:
	kSelectionListInt();
	void AddItem(int item, const int weight);
	int& Select(); ///< Returns a value based on item weights
	void Reset(); ///< clears all items in the list
	const uint GetNumEntries() const; ///< returns number of items in the list
	kSelectionListInt& opAssign(const kSelectionListInt&in other);
};

/**
 * @class kSelectionListFloat
 * @brief For selecting a float value based on weights
 */
class kSelectionListFloat
{
public:
	kSelectionListFloat();
	void AddItem(float item, const int weight);
	float& Select(); ///< Returns a value based on item weights
	void Reset(); ///< clears all items in the list
	const uint GetNumEntries() const; ///< returns number of items in the list
	kSelectionListFloat& opAssign(const kSelectionListFloat&in other);
};

class kRenderModel
{
public:
	void SetModel(const kStr&in modelPath, const kStr&in modelAnimPath);
	void SetRotationOffset(const int nodeIndex, const float rads, const float x, const float y, const float z);
	void SetRotationOffset(const int nodeIndex, const kQuat&in rotation);
	void SetTexture(const int section, const int textureID);
	void SetVisibility(const int nodeIndex, const bool visible);
	void HideSection(const int nodeIndex, const int section, const bool hide); ///< section is the surface index. must be 0-31 and must not be >= number of surfaces or will do nothing.
	void AddTrailEffect(const kStr&in trailName, const int nodeIndex);
	void RemoveTrailEffect(); ///< Removes all trail effects
	const int GetNumAttachedTrails();
	kVec3& Offset();
	const int GetNumNodes() const;
	kVec3 GetNodeOrigin(const int node, const kVec3&in offset); ///< Is calculated on draw. Can call ForceUpdateJoints if you need the current value for interpolation.
	kQuat GetNodeRotation(const int node); ///< Is calculated on draw. Can call ForceUpdateJoints if you need the current value for interpolation.
	kVec3 GetNodeScale(const int node);
    void ForceUpdateJoints(const float interpolatedFraction = 1.0f); ///< Force update node matrices and then call GetNodeOrigin/GetNodeRotation to get current value. interpolatedFraction should be in the range 0.0 (prev) to 1.0 (current). This is an expensive operation so use sparingly.
	kStr GetModelFile() const;
	kStr GetAnimFile() const;
	const bool IsMorph() const;

    /**
     * @brief Set Morph Updating.
     * @param bUpdate: Set to false to handle updating it yourself per ModelFile (not per Actor).
     *
        Default Tick code:
        @code{.cpp}
        if(time >= 1.0f)
        {
            time = 0;
            frame++;

            if(frame >= maxFrames)
            {
                frame = 2;
            }
            nextFrame = frame + 1;
        }
        time += GAME_DELTA_TIME * 7.5f;
        @endcode
     */
	void SetMorphUpdating(const bool bUpdate);

    /**
     * @brief Get Morph frame info
     * @param frame: 1=Init Frame, 2=Start Loop Frame. >= maxFrames then 1.
     * @param nextFrame: 2=Init Frame, 3=Start Loop Frame. >= maxFrames then 2.
     * @param maxFrames
     * @param time: 0..1 (lerp time between frame and nextFrame meshes)
     */
	void GetMorphFrame(int&out frame, int&out nextFrame, int&out maxFrames, float&out time) const;
	void SetMorphFrame(const int frame, const int nextFrame, const float time);
    void ColorOverride(const int node, const float r = 1.0f, const float g = 1.0f, const float b = 1.0f, const float a = 1.0f); ///< color values range from -1.0f to 1.0f. Call ColorOverrideSections to enable the override for sections on the node.
    void ColorOverrideSections(const int node, const int sectionMask = -1); ///< enable the color override for specific sections(materials) on the node by setting each bit. -1 = All, 0 = Stop override
    void ScaleOverride(const int node, const kVec3 &in scale);
    kVec3 &PrevOffset();
	void SetRotationOffset(const int nodeIndex, const float rads, const float x, const float y, const float z, const bool clearInterpolation = false);
	void SetRotationOffset(const int nodeIndex, const kQuat&in rotation, const bool clearInterpolation = false);
};

class kAnimState
{
public:
	void Blend(const int animID, float speed, float blend, int flags); ///< EnumAnimStateFlags
	void Set(const int animID, float speed, int flags); ///< EnumAnimStateFlags
	const int CurrentFrame(); ///< current frame playing for the current animation. Must have an animation action keyframe for this to work, otherwise use TrackFrame() instead. This should be named more like last frame an action was checked to execute.
	const int NumFrames(); ///< number of frames in this animation
	const int NumNodes(); ///< number of nodes in this animation
	const float PlayTime(); ///< increases by GAME_DELTA_TIME if not stopped or paused.
	const float TrackTime(); ///< time from 0(on first frame) to 1(on last frame).
	bool IsPlaying(const int animID); ///< Returns true if current animations ID is animID and the animation is not stopped.
	bool CheckAnimID(const int animID); ///< checks if animID exists
	const int PlayingID() const; ///< the current animations ID
	void Stop(); ///< flags |= ANF_STOPPED; flags &= ~ANF_LOOP;
	void Pause(); ///< flags |= ANF_PAUSED;
	void Resume(); ///< flags &= ~ANF_PAUSED;
	const bool Stopped() const; ///< (flags & ANF_STOPPED) != 0
	const bool Blending() const; ///< (flags & ANF_BLEND) != 0
	const bool Looping() const; ///< (flags & ANF_LOOP) != 0
	const bool CycleCompleted() const; ///< (flags & ANF_CYCLECOMPLETED) != 0
	void ChangeSpeed(const float speed); ///< Scales speed of the current animation where 1.0 = 15fps and 4.0 = 60fps
	void SetLastFrame(const bool execActions = false); ///< if execActions is true, runs all key frame actions in the animation except Footstep(55) and PlaySound(248). applies the stop flag (flags |= ANF_STOPPED).
	void SetPlayTime(const float time); ///< The total time in seconds this animation has been playing
	void SetTrackTime(const float time); ///< 0.0(first frame) to 1.0(last frame)
    const int TrackFrame(void) const; ///< current frame playing for the current animation.
    const int TrackNextFrame(void) const; ///< next frame to play for the current animation.
    kQuat GetRotation(const int animID, int nodeNum, int frame);
    kVec3 GetOrigin(const int animID, int nodeNum, int frame);
    const int GetAnimNumFrames(const int animID);
	int flags; ///< EnumAnimStateFlags
};

/**
 * @class kActor
 * @brief Base type used by all actors.
 */
class kActor
{
public:
	const bool IsStale() const; ///< Actor is marked as removed and is waiting to be freed from memory when it next checks if there are no more references to this actor.
	kAngle& Yaw();
	kAngle& Pitch();
	kAngle& Roll();
	kVec3& Origin(); ///< Position in world space
	kVec3& Scale();
	kVec3& PrevOrigin();
	void SetTarget(kActor@ actor);
	kActor@ GetTarget();
	void SetSector(const uint sectorIndex);
	void Remove(); ///< Removes the actor and sets stale to true. Actor will only internally be removed when there are no references to this actor.
	kVec3& Velocity();
	kVec3& Movement();
	kQuat& Rotation();
	int16& Health();
	int& Type(); ///< The actors Type ID
	int& ImpactType(); ///< EnumImpactType
	int& ImpactTypeDmg(); ///< EnumImpactType. Overrides the damage def used. if is -1 (default) then does not override ImpactType()
    bool &IgnoreSectorHeightChange(void); ///< if true will not change position(or velocity and movement) when sector height changes.
	int& ModelVariation();
	int& SpeciesMask();
	uint& Flags(); ///< EnumActorFlags
	const uint SpawnFlags1() const; ///< EnumActorSpawnFlags1
	const uint SpawnFlags2() const; ///< EnumActorSpawnFlags2
	const uint SpawnFlags3() const; ///< EnumActorSpawnFlags3
	const int TID() const;
	float& Radius();
	float& Height();
	float& StepHeight(); ///< AKA Dead Height. Used for moving up steps, figuring out if in waterheight, and the height of the actor when they are dead so you can still shoot them.
	float& WallRadius();
	float& Gravity();
	float& Friction();
	float& AnimSpeed();
	float& BounceDamp();
	float& FloorHeight();
	float& CeilingHeight();
	const int SectorIndex();
	const int AreaID() const;
	bool InstanceOf(const kStr&in className) const; ///< example: InstanceOf("kexPuppet")
	void PlaySound(const kStr&in soundPath);
	void PlaySoundWithLookupID(const int soundID);
	void StopSound();
	void StopLoopingSounds();
	const int GameTicks() const;
	kAnimState& AnimState();
	kRenderModel@ RenderModel();
	const bool InWater() const;
	bool CheckPosition(const kVec3&in origin); ///< checks if the actor can move to this location
	bool CheckPosition(const float angle, const float distance); ///< calls CheckPosition(kVec3 origin) with origin being: Actor.Origin() + (angle*distance*Actor.Radius())
	float GetTurnYaw(const kVec3&in lookAtLocation) const;
	float GetAvoidanceAngle(const kVec3&in lookAtLocation, const float distance);
	const float GetWaterHeight() const;
	const bool CanSee(kActor@ actor, const uint excludeClipFlags = 0); ///< excludeClipFlags to ignore/disable (EnumClipFlags)
	uint& ClipFlags(); ///< EnumClipFlags
	kDictMem@ Definition(); ///< get actors def data
	bool OnGround() const;
	int GetWaterLevel() const; ///< EnumWaterLevel
	kActor@ CastToActor(); ///< Casts to a kActor. Only used for kPuppet Actor().
	kAI@ CastToAI(); ///< Casts to kAI. returns null if isn't a kAI.
	kFx @SpawnProjectile(const kStr&in fxPath, const kVec3&in pos, const kVec3&in targetLocation, const float maxAngle); ///< Returns the first Fx spawned
	void MeleeObject(const kStr&in damageType, const kVec3&in offset, const float radius);
	kFx @SpawnFx(const kStr&in fxPath, const kVec3&in pos);
	kFx @SpawnFx(const kStr&in fxPath, const kVec3&in pos, const kQuat&in rot);
	kVec3 GetTransformedVector(const kVec3&in vector);
	float DistanceToPoint(const kVec3&in point) const; ///< calls DistanceToPoint(x,y,z)
	float DistanceToPoint(const float x, const float y, const float z) const; ///< actors point is in the center
	void InflictGenericDamage(kActor@ inflictor, const int damage);
	void InflictGenericDamage(kActor@ inflictor, const kexStr &damageDef, const int damage); ///< Can pass in a damage def. The damageDef keys used are mainly for custom scripting purposes only. Only the following keys are used internally when calling this function: bImpact, impactDamp, impactFalloff, bKnockback, knockBackForce
	void InflictDamage(kActor@ inflictor, const kStr&in damageDef);
    /**
     * @brief Calls a script function on all actors that are in the AreaNodes (KD-Tree search) contained inside a bounds. The bounds is calculated as: pos + this actors bounds(model bounds) + this actors radius. This will call for actors not necessarily in the bounds of the actor so checking distance is required in your script function.
     * @param pos The world position of where to check for actors
     * @param callbackFunc a function on this actors script class that will be called (if it exists) for each actor in range. function header must be: void callbackFunc(kActor@ actor, const float arg1, const float arg2, const float arg3, const float arg4)
     */
    void InteractActorsAtPosition(const kVec3&in pos, const kStr&in callbackFunc, const float arg1 = 0, const float arg2 = 0, const float arg3 = 0, const float arg4 = 0);
	kScriptObject@ ScriptObject();
	void MoveToPosition(const float x, const float y); ///< Moves the world object to a desired position at xy coordinates. Movement will use hitscan collision for quick collision tests.
	bool RandomDecision(const int randomBit) const; ///< randomBit should be >= 2. if a random value has the bit set and actors GameTicks also has the bit set then returns true.
	void SetPosition(const kVec3&in pos, const bool clearInterpolation = true); ///< best way to set an actors position (if you don't know the sector), will also set the sector and optionally clear interpolation

    /**
     * @brief Get a map actors param value
     * @param paramID
     * (0) Target ID -32768..32767
     * (1) Trigger Anim 0..255
     * (2) Health -32768..32767
     * (3) Max Regenerations -32768..32767
     * (4) Attach Chance 0..255
     * (5) Texture -128..127
     * (6) Params 2 -128..127
     * (7) Params 1 -128..127
     */
	const int16 SpawnParams(const int paramID) const;
	const float GetCeilingHeight() const; ///< calculates the ceiling height from the actors sector and origin. Returns 0 if not in a sector.
	const float GetFloorHeight() const; ///< calculates the floor height from the actors sector and origin. Returns 0 if not in a sector.
	void RunFxEvent(const kStr&in fxEventName); ///< Runs an ActorFX event. Example: RunFxEvent("Enemy_Freeze");
    bool FxEventActive(); ///< Returns true if FxEvent is running
	const int GetSectorIndexAtLocation(const kVec3&in pos, uint excludeClipFlags = 0); ///< excludeClipFlags to ignore/disable (EnumClipFlags)
	void MarkPersistentBit(const bool clear);
	const bool IsPersistentMarked();
	void SetHeadTrackTarget(kActor@ actor);
	void ClearInterpolation();
	void AutomapToggle(const bool show); ///< Use with Game.AutomapCustom(true);
	void SetAutomapColor(const int r, const int g, const int b);

    /**
     * @brief  Sets the actors param value. all params are int16.
     * @param param
     * (0) Target ID -32768..32767
     * (1) Trigger Anim 0..255
     * (2) Health -32768..32767
     * (3) Max Regenerations -32768..32767
     * (4) Attach Chance 0..255
     * (5) Texture -128..127
     * (6) Params 2 -128..127
     * (7) Params 1 -128..127
     * @param value
     */
	void SetSpawnParams(const int param, const int16 value);
	void SetSpawnFlags1(const uint flags); ///< EnumActorSpawnFlags1
	void SetSpawnFlags2(const uint flags); ///< EnumActorSpawnFlags2
	void SetSpawnFlags3(const uint flags); ///< EnumActorSpawnFlags3
	void SetupSpawnParams(); ///< call after setting your actors spawnflags for them to take effect on the kActor
	void SetCustomDeadHeight(const bool bUse, const float height); ///< Height of actor when they are dead. Only for non map actors. (actors spawned with ActorFactory)
	const float GetCustomDeadHeight();
	const bool GetUsingCustomDeadHeight();
	const bool OverridingKeyTouchTID(); ///< used only for key pickups
	const int16 GetOverrideKeyTouchTID(); ///< used only for key pickups
	void OverrideKeyTouchTID(const bool bOverride, const int16 tid); ///< used only for key pickups to tell what key it is in the hub
	bool& SkipKeyTouchCinema(); ///< used only for key pickups
	void SetModel(kStr&in modelFile, kStr&in animFile); ///< a way to set the model/anim for actors that had no model set previously
	bool& TriggerInvincibility(); ///< Can't damage if true. Gets set to true if enemy has trigger anim and false when activated.
    bool &DrawDelay(); ///< Don't draw until has ticked once.
	void GetBoundsMinMax(kVec3&out min, kVec3&out max) const; ///< actor must not be sleeping and have a model set and not be a pickup. otherwise will return default min/max values of (-128, -128, -128) (128, 128, 128). Sets the min and max kVec3 values (the actors origin is added to the values)
	const int MapActorIndex() const; ///< Returns -1 if not a map actor
	int& DifficultyMode(); ///< The difficulty this actor is currently set to
	void OverrideOnDamageValue(const int damage, const bool bOverride = true); ///< call in OnPreDamage
	bool& NoKnockBack(); ///< Will not receive knock back movement from things like the alien weapon for example.
	const float BaseHeight() const; ///< height of actor when spawned or when kAI regenerated
	void RunAction(const int funcID, const float w = 0.0f, const float x = 0.0f, const float y = 0.0f, const float z = 0.0f); ///< run a function on the actor defined in defs/animActions.txt
	float& AirFriction(); ///< default = 1.0f
	float& WaterFriction(); ///< default = 0.5f (same as Friction)
	float& Mass(); ///< default = GAME_SCALE * 1.0f
	const float GetSkyHeight() const;
    bool &ChildOfTarget(void); ///< if this actors Target is an actor that belongs to the owner of the Fx, explosion or melee attack then won't collide/get damaged.
    kVec3 DamageOrigin(void) const; ///< The Origin point of the attacker (Fx, Actor, or null (returns this actors origin in that case)) who damaged this actor last. Gets set before OnPreDamage.
    kVec3 DamageVelocity(void) const; ///< The Velocity of the attacker (Fx, Actor, or null (returns this actors velocity in that case)) who damaged this actor last. Gets set before OnPreDamage.
	const bool CanSee(kPuppet@ puppet, const uint excludeClipFlags = 0); ///< excludeClipFlags to ignore/disable (EnumClipFlags). Note: This function that takes in the kPuppet arg is only available for kActor, not for kPuppet or kAI or kWeapon.
    const kVec3 &PrevLerpOrigin(void) const;
    const kQuat &PrevLerpRotation(void) const;
    const kAngle &PrevLerpPitch(void) const;
    const kAngle &PrevLerpRoll(void) const;
    const kAngle &PrevLerpYaw(void) const;
    const int RefCount() const;    ///< Returns the number of references there are to this actor. If actor is stale and RefCount is 0 then it will be removed after the actor ticks.
    bool HasCustomRef(void) const;
    void AddCustomRef(void); ///< Keeps the actor from getting freed from memory.
    void ClearCustomRef(void); ///< Allows the actor to get freed from memory if it has no references. This will be called automatically when level is unloaded.
    void SetupHeadTrack(const kStr &in headTrackDef);   ///< Sets a headtrack
    float &SoundPitchModify();  ///< Override the final pitch of sounds owned by this actor. A value of 1000 raises the pitch by the amount tiny cheat does. A value of -1000 lowers the pitch by the amount the big head cheat does. Set to 0 to stop overriding. if less than 1 will override with no pitch change so tiny and big head mode don't affect it.
    void RotateAroundOrigin(const kAngle &in angle, const kVec3 &in platformOrigin, const bool setPos = true); ///< The angle amount to rotate this actors position. if setPos is true will use SetPosition to position the actor else will use MoveToPosition.
    void LinkArea(); ///< Links the actor to an area node so that internally the actor can be found in quick searches (similar to a kd-tree) for explosive damage radius checks, when InteractActorsAtPosition is called, kAI GetAttention checks, and collision checks against actors. Should only call whenever you set the actors Origin() directly. Calling MoveToPosition or SetPosition or when the actors movement is updated by velocity changes or by gravity then LinkArea will be called internally.
    void CheckLinkArea();   ///< If origin or radius changed since the last LinkArea then calls LinkArea else does nothing. Links the Actor to an area node so that internally the Actor can be found in quick searches (similar to a kd-tree).
    float SoundPlayTime(const kStr &in file); ///< returns -1 if sound is not playing. Returns the amount of time in seconds the sound has been playing for. file is the "wavefile" property in the sound shader.
    bool &RemoveTrailsOnAnimChange(); ///< Will remove all model trails on this actor when animation is set/blend
    const float GetCurrentGameSpeed(void) const; ///< Gamespeed of this Actor (default 1.0f)
    void SetCurrentGameSpeed(const float speed); ///< Set Gamespeed of this Actor (default 1.0f)
    bool &IgnoreGameSpeed(); ///< GameSpeed used for this actor will be CurrentGameSpeed. (Default is true for kPuppet and kPlayerWeapon. Default is False for every other actor)
    bool &IgnoreFxGameSpeed(); ///< GameSpeed used for Fx whose source is this actor will always be CurrentGameSpeed. (Default is false)
    const float GetGameSpeed() const; ///< Returns CurrentGameSpeed if IgnoreGameSpeed is true else returns CurrentGameSpeed * GlobalGameSpeed.
    kFx @DamageFx() const;  ///< The kFx that hit this actor. Will be null if no Fx hit this actor. Only use in OnPreDamage/OnDamage/OnDeath. Do not use anywhere else or it could be pointing to a random place in memory then the game will crash!
    const float DecayTime(void);    ///< Value used to melt kAI when they regen. Values range from 0.0 (normal) to 60.0 (fully melted).
    void SetDecayTime(const float value);   ///< Used to melt kAI when they regen. Value range should be 0 (normal) to 60 (fully melted).
    float RadiusDamageFactor(const kVec3 &in origin, const float radius) const;
    bool &UseNewExplosiveRadiusCheck(void); ///< (default False) Set to true to enable explosive damage checks from radius to actor cylinder(more accurate) instead of radius to actors center point.
};

/**
 * @class kActorIterator
 * @brief The way to iterate through all actors in the map. Example code:
 * @code{.cpp}
 *  kActorIterator it;
 *  kActor @actor;
 *  while((@actor = it.Get()) !is null)
 *  {
 *      // Do something with actor
 *  }
 * @endcode
 */
class kActorIterator
{
public:
	kActorIterator();
	kActor@ Get(); ///< Returns the next actor in the iterator
	void Reset(); ///< Resets the iterator back to the first actor
};

class kWeapon : public kActor
{
public:
	kVec3 TransformToOwnerPosition(); ///< returns the OffsetPosition() * the players matrix.
	kVec3 TransformToOwnerPosition(const kVec3&in vector); ///< returns the (OffsetPosition() + vector) * the players matrix.

    /**
     * @brief SpawnsFx at the players at the position passed in * players rotation, then adds the
     * viewHeight + landingViewOffset to the z position. Sets PF_FIREDPROJECTILE PlayerFlags.
     * adjustToPerspective will change the position you pass in like this:
     * @code{.cpp}
     * float d = kexMath::Pow(47.5f / fov, fov / 60.0f);
     * vOrigin.y *= d;
     * vOrigin.z += (1.0f - d) * 2.0f;
     * @endcode
     */
	kFx @FireProjectile(const kStr&in fxPath, const float x, const float y, const float z, const bool adjustToPerspective = false);
	bool& PreventFire(); ///< Use in OnBeginFire to internally prevent from entering its Fire state.
    bool &NoGenericBobbing(); ///< Disables the generic weapon bobbing menu option from affecting this weapon
	kVec3& OffsetPosition(); ///< Offset position of weapon
	int& State(); ///< EnumWeaponStates
    bool &AllowUnderwater(); ///< Set to true to allow the weapon underwater. Gets reset back to the weapons def value after OnBeginLevel.
	kPlayer& Owner();
    bool &ClearInterpolationOffsetPosition(); ///< Set to true to clear the OffsetPosition interpolation after the weapon ticks, then it gets set back to false.
    float &PlaySpeed(); ///< Get/Set speed of weapon animations (default = 4.0f)
    float &PlaySpeedSwapIn(); ///< Get/Set speed of weapon lower animation (default = 4.0f)
    float &PlaySpeedSwapOut(); ///< Get/Set speed of weapon raise animation (default = 3.0f)
    float &FOV();   ///< Get/Set weapon FOV (default = 47.5f)
    bool &NoWalkAnim(); ///< Get/Set the usage of the walk anim. Run animation will be used instead.
    bool &ForceGenericBobbing();

};

class kAI : public kActor
{
public:
	uint& AIFlags(); ///< EnumAIFlags
	void SetupAISpawnFlags(); ///< call after setting your actors spawnflags for them to take effect on the kAI
	int& AttackChance(); ///< 0-100
	float& AttackRange(); ///< squared
	float& MeleeRange(); ///< squared
	float& LeashRadius(); ///< squared
	float& SightRange(); ///< squared
	float& LoudRange(); ///< squared
	float& QuietRange(); ///< squared
	float& FlyHeight(); ///< squared
	float& SightFOV(); ///< in rads
	int& Agitation(); ///< 0-300.  0-99=IDLE, 100-199=AGITATED, 200-300=CHASE
	float& AnimScalar(); ///< default = 1.0f
	float& BlendScalar(); ///< default = 10.0f
    int &Regenerate();  ///< get/set current number of times the enemy will regenerate value. Regenerate is set right after OnBeginLevel is called and is set to a random value from 0 to the mapActors maxRegenerations value or the actors def ai.maxRegenerations value(for non map actors).
};

class kPuppet : public kActor
{
public:
	float& ViewHeight(); ///< set from the players def "player.viewHeight". Origin.z + ViewHeight() + LandingViewOffset() = Cameras position.
	float& RecoilPitch(); ///< used for weapon recoil that modifies the players pitch.
	const float LandingViewOffset() const; ///< LandingViewOffset changes when jumping and falling. Origin.z + ViewHeight() + LandingViewOffset() = Cameras position.
	uint& PlayerFlags(); ///< EnumPlayerFlags
	void QuietNoiseAlert();
	void LoudNoiseAlert();
    void SetGroundForwardSpeed(const float speed);     ///< default = 10.24f
    void SetGroundBackwardSpeed(const float speed);    ///< default = -10.24f
    void SetGroundStrafeSpeed(const float speed);      ///< default = 10.24f
    void SetGroundForwardAccel(const float accel);     ///< default = 0.05f
    void SetGroundBackwardAccel(const float accel);    ///< default = 0.05f
    void SetGroundStrafeAccel(const float accel);      ///< default = 0.05f
    void SetGroundDeaccel(const float accel);          ///< default = 0.5f
    void SetSwimForwardSpeed(const float speed);       ///< default = 10.24f
    void SetSwimBackwardSpeed(const float speed);      ///< default = -10.24f
    void SetSwimStrafeSpeed(const float speed);        ///< default = 10.24f
    void SetSwimForwardAccel(const float accel);       ///< default = 0.05f
    void SetSwimBackwardAccel(const float accel);      ///< default = 0.05f
    void SetSwimStrafeAccel(const float accel);        ///< default = 0.05f
    void SetSwimDeaccel(const float accel);            ///< default = 0.5f
    void SetJumpMinSpeed(const float speed);           ///< default = GAME_SCALE * 0.855f
    void SetJumpMaxSpeed(const float speed);           ///< default = GAME_SCALE * 1.667f
    void SetJumpClimbSpeed(const float speed);         ///< default = GAME_SCALE * 0.2875f
    void SetOverrideShadow(const int value);           ///< 0=none(default), 1=Force Disable shadow, 2=Force Enable shadow
    void SetOverrideWalkRun(const int value);          ///< 0=none(default), 1=Force Disable Walk
	float& Oxygen(); ///< Time in seconds. 0: full oxygen. >= 55: shows air bar. >= 70: OxygenOut is set to true.
	bool& OxygenOut(); ///< if true will damage player if underwater
	float& OverrideFOV(); ///< set to 1-179. anything else will stop overriding the fov and will use the r_fov cvar.
	void SetCrawl(const bool crawl); ///< use this to manually set if the player is crawling instead of setting PF_CRAWLING directly.
    const float GroundForwardSpeed() const;     ///< default = 10.24f
    const float GroundBackwardSpeed() const;    ///< default = -10.24f
    const float GroundStrafeSpeed() const;      ///< default = 10.24f
    const float GroundForwardAccel() const;     ///< default = 0.05f
    const float GroundBackwardAccel() const;    ///< default = 0.05f
    const float GroundStrafeAccel() const;      ///< default = 0.05f
    const float GroundDeaccel() const;          ///< default = 0.5f
    const float SwimForwardSpeed() const;       ///< default = 10.24f
    const float SwimBackwardSpeed() const;      ///< default = -10.24f
    const float SwimStrafeSpeed() const;        ///< default = 10.24f
    const float SwimForwardAccel() const;       ///< default = 0.05f
    const float SwimBackwardAccel() const;      ///< default = 0.05f
    const float SwimStrafeAccel() const;        ///< default = 0.05f
    const float SwimDeaccel() const;            ///< default = 0.5f
    const float JumpMinSpeed() const;           ///< default = GAME_SCALE * 0.855f
    const float JumpMaxSpeed() const;           ///< default = GAME_SCALE * 1.667f
    const float ClimbJumpAmount() const;        ///< default = GAME_SCALE * 0.2875f
    const int OverrideShadow() const;           ///< default = 0
    const int OverrideWalkRun() const;          ///< default = 0
    const int GetState(void) const;             ///< EnumPlayerStates
    float &MaxFallVelocity(void);               ///< default = -200.0f
    bool &NoWallJump(void);                     ///< default = false
    bool &CustomViewEnable();                   ///< Set to true to enable the custom view
    bool &CustomViewUnderwater();               ///< whether the custom view is underwater or not
    kAngle &CustomViewYaw();
    kAngle &CustomViewPitch();
    kAngle &CustomViewRoll();
    kexVec3 &CustomViewOrigin();
    void SetHeadBobScale(const float scale);
    void SetTurnBobScale(const float scale);
    void SetStrafeBobScale(const float scale);
    void SetUnderwaterBobScale(const float scale);
    void SetJumpBobScale(const float scale);
    void SetOverrideWeaponOnTopFix(const int value);    ///< 0=none(default), 1=Force disable fix, 2=Force enable fix (can use console command "g_weaponontopfix" 1 to turn it on as well)
    void SetMaxLives(const int value);      ///< Max lives allowed from gaining Lifeforces
    void SetMaxLifeforces(const int value); ///< Amount of Lifeforces needed to get an extra life
    const float HeadBobScale() const;
    const float TurnBobScale() const;
    const float StrafeBobScale() const;
    const float UnderwaterBobScale() const;
    const float JumpBobScale() const;
    const int OverrideWeaponOnTopFix() const;
    const int GetMaxLives() const;
    const int GetMaxLifeforces() const;
};

/**
 * @class kActorFactory
 * @brief For Spawning Actors
 */
class kActorFactory
{
public:
	kActor@ Spawn(const int actorID, const float x, const float y, const float z, const float yaw, const int sector = - 1);
	kActor@ Spawn(const kStr&in actorName, const float x, const float y, const float z, const float yaw, const int sector = - 1);
};

/**
 * @class kFx
 */
class kFx
{
public:
    const bool IsStale() const; ///< Fx is marked as removed and is waiting to be freed from memory when it next checks if there are no more references to this fx (after OnTick is called).
	kAngle& Yaw(); ///< Not used by the Fx
	kAngle& Pitch(); ///< Not used by the Fx
	kAngle& Roll(); ///< Not used by the Fx
    kVec3 &Origin();
    kVec3 &Scale();
    kVec3 &PrevOrigin();
    void SetTarget(kActor@ actor);
    kActor @GetTarget();
    void SetSector(const uint sectorIndex);
    kVec3 &Velocity();
    kVec3 &Movement();
    kQuat &Rotation();
    int &ImpactType(); ///< EnumImpactType
    int &ImpactTypeDmg(); ///< EnumImpactType. Overrides the damage def used. if is -1 (default) then does not override ImpactType()
    bool &IgnoreSectorHeightChange();
    float &Radius();    ///< (Default 8.0) Not really used. Only for searches for the fx to define it's bounding box.
    float &Height();    ///< (Default 8.0) Not really used. Only for searches for the fx to define it's bounding box.
    float &WallRadius();
    float &Gravity();
    float &Friction();
    float &BounceDamp();
    float &FloorHeight();
    float &CeilingHeight();
    const int SectorIndex();
    const int AreaID() const;
    bool InstanceOf(const kStr &in className) const; ///< example: InstanceOf("kexFx")
    void PlaySound(const kStr &in soundPath);
    void PlaySoundWithLookupID(const int soundID);
    void StopSound();
    void StopLoopingSounds();
    const float GetWaterHeight() const;
    const bool CanSee(kActor@ actor, const uint excludeClipFlags = 0); ///< excludeClipFlags to ignore/disable (EnumClipFlags)
    bool OnGround() const;
    int GetWaterLevel() const; ///< EnumWaterLevel
    float DistanceToPoint(const kVec3 &in point) const; ///< calls DistanceToPoint(x,y,z)
    float DistanceToPoint(const float x, const float y, const float z) const; ///< Fx point is in the center
    void MoveToPosition(const float x, const float y); ///< Moves the world object to a desired position at xy coordinates. Movement will use hitscan collision for quick collision tests.
    void SetPosition(const kVec3 &in pos, const bool clearInterpolation = true); ///< best way to set an Fx position without knowing the sector, will also find/set the sector and optionally clear interpolation
    const float GetCeilingHeight() const; ///< calculates the ceiling height from the Fx sector and origin. Returns 0 if not in a sector.
    const float GetFloorHeight() const; ///< calculates the floor height from the Fx sector and origin. Returns 0 if not in a sector.
    const int GetSectorIndexAtLocation(const kVec3 &in pos, uint excludeClipFlags = 0); ///< excludeClipFlags to ignore/disable (EnumClipFlags)
    float &AirFriction();
    float &WaterFriction();
    float &Mass();
    const float GetSkyHeight() const;
    bool &ChildOfTarget(); ///< Unused. Only used for kActors.
    void LinkArea(); ///< Links the Fx to an area node so that internally the fx can be found in quick searches (similar to a kd-tree). Use with Game.GetFxInBounds. Should only call whenever you set the actors Origin() directly and then want to call Game.GetFxInBounds right after. LinkArea will be called automatically in OnTick internally so outside of that case you never need to worry about calling this.
    void CheckLinkArea(); ///< If origin or radius changed since the last LinkArea then calls LinkArea else does nothing. Links the Fx to an area node so that internally the Fx can be found in quick searches (similar to a kd-tree). Use with Game.GetFxInBounds. Should only call whenever you set the actors Origin() directly and then want to call Game.GetFxInBounds right after. CheckLinkArea will be called automatically in OnTick internally so outside of that case you never need to worry about calling this.
    void Remove(); ///< Removes the Fx and sets stale to true. Fx will only internally be removed when there are no references to this Fx.
    const int GameTicks() const;
    float RadiusDamageFactor(const kVec3 &in origin, const float radius) const;
    bool InWater();
    kScriptObjectFx @ScriptObject();
    void ClearInterpolation();
    const bool DrawDelay() const;
    const float GetCurrentGameSpeed(void) const; ///< Gamespeed of this Fx (default 1.0f)
    void SetCurrentGameSpeed(const float speed); ///< Set the Gamespeed of this Fx (default 1.0f)
    const float GetGameSpeed() const; ///< Returns CurrentGameSpeed if IgnoreGameSpeed is true else returns the CurrentGameSpeed * GlobalGameSpeed.
    const int RefCount() const; ///< Returns the number of references there are to this Fx. If this Fx is stale and RefCount is 0 then it will be removed after the Fx ticks.
    bool HasCustomRef() const;
    void AddCustomRef(); ///< Keeps the Fx from getting freed from memory.
    void ClearCustomRef(); ///< Allows the Fx to get freed from memory if it has no references. This will be called automatically when level is unloaded.
    const int BounceCount() const;
    float &RecurseLifeTime();
    bool &DidWaterImpact();
    bool &IgnoreGameSpeed(); ///< GameSpeed used for this Fx will always be CurrentGameSpeed. (Default = false)
    kActor @GetOwnerAsActor();
    kFx @GetOwnerAsFx();
    void SetOwnerAsActor(kActor@ actor);
    void SetOwnerAsFx(kFx@ fx);
    kFx @GetParentFx();
    void SetParentFx(kFx@ fx);
    kStr FxFilePath();
    kVec3 &MuzzleOffset();
    const float Distance() const; ///< Distance to the center of the View (Player or Camera) at the time the Fx spawned.
    const float Restart() const; ///< Current delay time before the Fx will start ticking
    int &Frame(); ///< The sprite frame. Make sure this value is < MaxFrames().
    const uint MaxFrames() const; ///< MaxFrames the sprite has. Frame should be < this value.
    float &DrawScale(); ///< Current scale of the sprite
    float &DrawScaleDest(); ///< When the Fx is updating its scale OnTick, the current draw scale will increase to this value in different ways depending if bScaleLerp is true in the fx file.
    float &MaxDrawScale(); ///< The highest value the DrawScale() can become when the Fx is updating its scale OnTick.
    float &RotationOffset(); ///< Current Rotation Offset around the Y Axis. kQuat(RotationOffset(), 0.0f, 1.0f, 0.0f);
    float &RotationSpeed(); ///< Adds this value * (0.25 * GameSpeed) to RotationOffset() when updating rotation OnTick. This value is set on spawn.
    kVec3 &VelocityOffset(); ///< When Fx spawns this is set to the starting velocity of the Fx. And adds to velocity if bAddOffset is true. Has no other use.
    void SetColor1(float r, float g, float b, float a); ///< Values range from 0.0 to 1.0. Color and alpha of sprite.
    void SetColor2(float r, float g, float b, float a); ///< Values range from 0.0 to 1.0. Environment color of the sprite (used in shaders to blend color1 and color2 together). Alpha is always set to the same as Color1.
    void GetColor1(float &out r, float &out g, float &out b, float &out a); ///< Get the color values
    void GetColor2(float &out r, float &out g, float &out b, float &out a); ///< Get the color values
    const bool SwapBloodColor() const;  ///< Is true if fx has bBlood set to true and games blood menu option is set to Green(1). When RandomizeColors() is called which is done automatically when the Fx spawns.
    float &Speed(); ///< Initial forward moving speed, set on spawn from forwardSpeed and forwardSpeedRandom in the fx file.
    float &MovingForce(); ///< initial veolcity.Length() value. if bBullet is true then while updating movement OnTick, if the velocity.length() of the fx is below MovingForce() * 0.65f then removes the Fx.
    float &MuzzleLifeTime();
    const int Instances() const; ///< Same as the instances value in the fx file.
    float &FrameTime(); ///< The current time left before the Fx sprite tries going to the next frame in the sprite.
    int &BulletBounces();
    const int FxIndex() const;  ///< The index in the fx file array
    const int InstanceIndex() const;
    bool &DoUpdateTickEvents(); ///< If set to false the Fx will not call Tick or WaterTick events.
    bool &DoUpdateSpriteAnimation(); ///< If set to false the Fx will not update sprite frame
    bool &DoUpdateRotation(); ///< If set to false the Fx will not update rotation offset
    bool &DoUpdateScaling(); ///< If set to false the Fx will not update draw scale
    bool &DoUpdateFading(); ///< If set to false the Fx will not update color1 and color2 alpha value
    bool &DoUpdateMovement(); ///< If set to false the Fx will not move
    bool &DoUpdateExpireCheck(); ///< If set to false the Fx will not expire and get removed when lifetime is over
    bool &OnCollideForceSetOriginToLast(); ///< If set to true the Fx will set it's origin and sector to what it was before OnCollide was called.
    bool &OnCollideForceNoSetOriginToLast(); ///< If set to true the Fx will never set it's origin and sector to what it was before OnCollide was called.
    void SpawnImpactFx(const int impactType, const kVec3 &in normal, const bool bUseEvent = true, const bool bBlood = true);
    void SpawnWaterImpactFx();
    void RandomizeColors();
    const int FxID() const;
    bool InfoFadeout(void) const;
    bool InfoStopAnimOnImpact() const;
    bool InfoOffsetFromFloor() const;
    bool InfoTextureWrapMirrorWidth() const;
    bool InfoTextureWrapMirrorHeight() const;
    bool InfoLensFlares() const;
    bool InfoBlood() const;
    bool InfoAddOffset() const;
    bool InfoDepthBuffer() const;
    bool InfoScaleLerp() const;
    bool InfoActorInstance() const;
    bool InfoNoDirection() const;
    bool InfoFlash() const;
    bool InfoProjectile() const;
    bool InfoDestroyOnWaterSurface() const;
    bool InfoStickOnTarget() const;
    bool InfoBullet() const;
    bool InfoWeaponView() const;
    bool InfoFullScreen() const;
    bool InfoDecalOffset() const;
    bool InfoNoSpawnNear() const;
    bool InfoNoSpawnFar() const;
    bool InfoOverrideMaxDrawScale() const;
    bool InfoIgnoreGameSpeed() const;
    bool InfoAttachSource() const;
    bool InfoDrawOnBottom() const;
    bool InfoSparkle() const;
    bool InfoCrossFade() const;
    bool InfoImpactEffect() const;
    bool InfoRestrictAim() const;
    bool InfoNoWallSpawn() const;
    bool InfoNoGroundSpawn() const;
    bool InfoNoHitSource() const;
    bool InfoPerPolyCollision() const;
    bool InfoMuzzleEffect() const;
    bool InfoDrawDelay() const;
    bool InfoBounceImpact() const;
    float InfoBounceImpactThreshold() const;
    float InfoNoSpawnNearFarDist() const;
    float InfoMass() const;
    float InfoTranslationGlobalRandomScale() const;
    kVec3 InfoTranslation() const;
    float InfoGravity() const;
    float InfoFriction() const;
    float InfoAirFriction() const;
    float InfoWaterFriction() const;
    float InfoAnimFriction() const;
    kVec3 InfoMuzzleOffset() const;
    float InfoScale() const;
    float InfoScaleDest() const;
    float InfoMaxscale() const;
    float InfoForward() const;
    kVec3 InfoOffset() const;
    float InfoRotationOffset() const;
    float InfoRotationSpeed() const;
    float InfoRotationPivotX() const;
    float InfoRotationPivotY() const;
    int InfoLifetime() const;
    int InfoRecurseLifetime() const;
    float InfoRestart() const;
    int InfoAnimspeed() const;
    int InfoOnCollideActor() const;
    int InfoOnCollideWall() const;
    int InfoOnCollideFloor() const;
    int InfoDrawType() const;
    int InfoAnimType() const;
    int InfoVisibilityType() const;
    kVec3 InfoWhiteColor() const;
    kVec3 InfoBlackColor() const;
    float InfoHueRandom() const;
    float InfoSaturationRandom() const;
    float InfoBrightnessRandom() const;
    int InfoFadeinTime() const;
    int InfoFadeoutTime() const;
    int InfoMaxBulletBounces() const;
    int InfoMaxInstances() const;
    float InfoSpawnDistOffset() const;
    kStr InfoModelName() const; ///< Custom use
    kStr InfoAnimName() const; ///< Custom use
    kStr InfoUserString() const; ///< Custom use
    int InfoUserID() const; ///< Custom use
};

class kCamera
{
public:
	void StartCinematic(const uint flags = 12); ///< EnumCameraFlags
	void StopCinematic(const bool noFade = false); ///< if noFade is true will stop the cinematic immediately without fading out.
	const int CinematicState() const; ///< EnumCameraStates
	void SetLookAtActor(kActor@ actor);
	void ClearLookAtActor();
	void SetRotateEyeVector(const kVec3&in vector); ///< The focus position that is used when AutoPlayRotationTrack is called if there is no LookAtActor set.
	void SetFinalView(const int view); ///< the view to use for the camera origin and direction. view must be in range 0-2
	void SetRotationTrack(const int view, const float startAngle, const float destAngle, const float startDist, const float destDist, const float startEyeZOffset = 0, const float destEyeZOffset = 0, const float startFocusZOffset = 0, const float destFocusZOffset = 0); ///< Use with TweenRotationTrack and AutoPlayRotationTrack.
	void SetPositionTrack(const int view, const kVec3&in startEye, const kVec3&in destEye, const kVec3&in startFocus, const kVec3&in endFocus);  ///< Sets eye and focus start and dest positions for use with TweenPositionTrack and AutoPlayPositionTrack.
	void TweenPositionTrack(const int view, const float time); ///< Lerps eye and focus positions to the start and dest positions using the time param (clamped 0..1). Call SetPositionTrack to set the start and dest positions.
	void TweenRotationTrack(const int view, const kVec3&in pos, const float time); ///< Lerps all variables set when SetRotationTrack was called using the time param (clamped 0..1).
	void AutoPlayPositionTrack(const int view, const float speed, const int lerpType); ///< EnumCameraLerpType. Calls TweenPositionTrack on the view using speed and lerpType
	void AutoPlayRotationTrack(const int view, const float speed, const int lerpType); ///< EnumCameraLerpType. Calls TweenRotationTrack on the view using speed and lerpType
	void AutoPlayBlendTrack(const int viewA, const int viewB, const int viewC, const float speed, const int lerpType); ///< EnumCameraLerpType. Blends between viewB and viewC eye and focus. and sets the results to viewA.
	void SetEyeView(const kVec3&in position); ///< position of camera (finalview). finalview must be set or will do nothing.
	void SetFocusView(const kVec3&in position); ///< position of where the camera (finalview) is looking at. (Sets look direction from eye and focus positions). finalview must be set or will do nothing.
	void ZoomEyeViewToPosition(const kVec3&in position, const float speed); ///< linear lerp finalview eye position to position using speed. finalview must be set or will do nothing.
	void ZoomFocusViewToPosition(const kVec3&in position, const float speed); ///< linear lerp finalview focus position to position using speed. finalview must be set or will do nothing.
	kVec3 GetEyeView(); ///< position of camera (finalview). finalview must be set or will return vecZero.
	kVec3 GetFocusView(); ///< position of where the camera (finalview) is looking at. finalview must be set or will return vecZero.
	void ClearFinalView(); ///< finalview is set to null
	void ClearViewTracks(); ///< views 0-2 all variables are set to 0
	const bool UserInterrupted() const; ///< User pressed left click or escape key or any controller button. While CinematicState() == CAMS_ACTIVE and used EnumCameraFlags CMF_LOCK_PLAYER
    void SetUserInterrupted(const bool toggle); ///< set to false to set the user interrupted to false.
	const bool Active() const;
	const bool Enabled() const; ///< CinematicState() >= CAMS_FADEOUT (Not Idle)
	const bool ViewingFromCamera() const; ///< CinematicState() >= CAMS_FADEIN && CinematicState() <= CAMS_ACTIVE_TO_FADEOUT
	kVec3& Tremor(); ///< x = adds to yaw, y = adds to pitch, z = adds to roll. lerps to vecZero using lerpTime of GAME_FRAME_TIME.
	void SetSector(const uint sectorIndex);
	const int SectorIndex();
	const int AreaID() const;
	void ClearInterpolation();
    const uint Flags() const; ///< EnumCameraFlags
	kVec3 origin; ///< current position of camera. if a finalview is set then the origin will be set to the finalview's eye position.
	kAngle yaw; ///< if a finalview is set then the yaw will be set to the finalview's look direction.
	kAngle pitch; ///< if a finalview is set then the pitch will be set to the finalview's look direction.
	kAngle roll; ///< if a finalview is set then the roll will be set to 0.
	float fov; ///< Camera FOV (default is 74.0)
	float lookZOffset; ///< Used only if LookAtActor has been set.
    bool &ClearInterpolationOnTick(void); ///< set to false to handle interpolation yourself
    bool &AllowMenusWhenActive(void); ///< set to true to allow the pause menu to be opened during a cinematic
};

/**
 * @class kCModel
 * @brief The kCModel(CModel) global stores collision results when certain actor methods are called. Those methods are as follows:
 * GetSectorIndexAtLocation
 * const bool CanSee(kActor@, const uint = 0)
 * MoveToPosition
 * SpawnProjectile
 * bool CheckPosition(const kVec3 &in)
 */
class kCModel
{
public:
	kVec3& InterceptVector(); ///< Returns the vector that intersected the collided geometry
	kVec3& ContactNormal(); ///< Returns the normalized vector of the collided surface
	const float& Fraction(); ///< returns the 0.0 - 1.0 range of the point of intersection from start to end trace. (If fraction is == 1.0 then no intersection occured.)
	const uint ClipResult(); ///< specifies the type of intersection (flags)
	kActor@ ContactActor(); ///< handle pointer to actor that was collided (null if none was collided)
    kVec3& MoveDirection(); ///< Movement vector of the object
};

class kPlayLoop
{
public:
	const int Ticks() const; ///< affected by gamespeed (Ticksf truncated)
    const float Ticksf(void) const; ///< affected by gamespeed
	const int UnscaledTicks() const; ///< Not affected by GameSpeed
	void TagActorForBossBar(kActor@ actor);
	void RemoveBossActor();
	void CheckKeys(); ///< Prints HUD messages to tell the player how many keys they've found on the current HUBID
	void ChangeMap(const kStr&in mapName);
	void StartWarp(kActor@ actor, const int tagID, const int mapID);
	void StartFreeWarp(kActor@ actor, const kVec3&in origin, const float yaw, const int sectorIndex, const int mapID);
	void HandlePlayerDeath(const bool loseLife = true); ///< if loseLife is true and infinite lives cheat is off then player loses a life. if player lives is < 0 then GameOver is called. If has >= 0 lives left then will ChangeMap to the current set check point, or use the current map if no check point is set.
	const bool CheckWarping(); ///< Checks if Warping or FreeWarping is in progress.
	const bool CanOpenPauseMenu(); ///< Checks if it's okay to be able to open a menu
	const bool CanOpenSaveMenu(); ///< Checks if it's okay to be able to open the save menu
    const int NewMapWarpTID(); ///< Returns the warp TID the player warped to from another map. Returns -1 of didn't warp from another map. Check before OnPostBeginLevel.
    void ClearWarpInterpolation(void); ///< Clearing the interpolation for kPuppet will also clear the warp interpolation.
};

class kSys
{
public:
	void Print(const kStr&in message);
	void Warning(const kStr&in message);
	int VideoWidth();
	int VideoHeight();
	int Mouse_X();
	int Mouse_Y();
	const bool GetCvarValue(const kStr&in cvarName, kStr&out result);
	void MouseToHUD(float&out x, float&out y); ///< Returns the HUD position of the mouse
};

class kWorld
{
public:
	kActor@ GetActorByTID(const int tagID, const int typeFilter = - 1) const; ///< if typeFilter is -1 checks any type otherwise only returns the actor of that type
	bool TriggerActorsByTID(kActor@ instigator, const int tagID); ///< Triggers an actor (that is not the instigator) that has the same tagID. Returns true if triggered an actor.
	void ChangeAreaFlag(const int areaID, const uint flags, const bool active); ///< (EnumAreaFlags) Only sets the areaID flags and not the sector flags. Should most likely prefer using FloodMatchingAreaFlags so the sectors get set as well.
	void FloodFillAreaFlags(const int sectorIndex, const uint flags, const bool active); ///< (EnumAreaFlags) Sets flags on all adjacent sectors until it finds a sector that has the flags already set (or cleared if active is false)
	void FloodFillAreaFlags(const kVec3&in origin, const uint flags, const bool active); ///< (EnumAreaFlags) Calls FloodMatchingAreaFlags with FindNextClosestSector(origin) sector.
	void FloodMatchingAreaFlags(const int sectorIndex, const uint flags, const bool active); ///< (EnumAreaFlags) Sets flags on all adjacent sectors with matching areaID.
	const uint GetAreaFlags(const int areaID) const; ///< EnumAreaFlags
	const int GetAreaFloorImpact(const int areaID) const; ///< EnumImpactType
	const int GetAreaWallImpact(const int areaID) const; ///< EnumImpactType
    void ChangeAreaFloorImpact(const int areaID, const int value); ///< value: EnumImpactType
    void ChangeAreaWallImpact(const int areaID, const int value); ///< value: EnumImpactType
	void ChangeAreaWaterHeight(const int areaID, const float height); ///< WaterHeight is stored per area, not per sector or per vertex.

    /**
     * @brief Returns an area arg value
     * @param areaID
     * @param arg
        @code{.cpp}

        though args can be used for anything, they are typically used in this fashion:
        0: warp ID
        1: warp level ID or trigger sound ID
        2: checkpoint ID
        3: tag ID
        4: floor damage hit points
        5: floor damage rate

        Hardcoded:
        0: AAF_TELEPORT: WarpID
        1: AAF_TELEPORT: WarpLevelID,  AAF_EVENT and AAF_EVENTSOUND: soundID to play when player enters sector
        2: AAF_CHECKPOINT or AAF_SAVEGAME: CheckpointID
        3: AAF_EVENT: tag ID
        4: Not used
        5: AAF_SECRET: the secret index value (set automatically when level loads starting at 0. Conflicts with AAF_DAMAGE (so I guess no secrets should be placed on damage sectors))

        Default Scripts:
        0: Not used
        1: Not used
        2: Not used
        3: Not used
        4: AAF_DAMAGE: amount of damage to do to the player when they're on the ground
        5: Always used as floor damage delay no matter the AAF flags. Should be used with AAF_DAMAGE only. 1 second = 1024
        @endcode
    */
	const int16 GetAreaArg(const int areaID, const int arg) const;

    /**
     * @brief
     * @param areaID
     * @param arg
        @code{.cpp}

        though args can be used for anything, they are typically used in this fashion:
        0: warp ID
        1: warp level ID or trigger sound ID
        2: checkpoint ID
        3: tag ID
        4: floor damage hit points
        5: floor damage rate

        Hardcoded:
        0: AAF_TELEPORT: WarpID
        1: AAF_TELEPORT: WarpLevelID,  AAF_EVENT and AAF_EVENTSOUND: soundID to play when player enters sector
        2: AAF_CHECKPOINT or AAF_SAVEGAME: CheckpointID
        3: AAF_EVENT: tag ID
        4: Not used
        5: AAF_SECRET: the secret index value (set automatically when level loads starting at 0. Conflicts with AAF_DAMAGE (so I guess no secrets should be placed on damage sectors))

        Default Scripts:
        0: Not used
        1: Not used
        2: Not used
        3: Not used
        4: AAF_DAMAGE: amount of damage to do to the player when they're on the ground
        5: Always used as floor damage delay no matter the AAF flags. Should be used with AAF_DAMAGE only. 1 second = 1024
        @endcode
     * @param value
     */
	void ChangeAreaArg(const int areaID, const int arg, const int16 value);
	void ChangeSectorHeight(const int sectorIndex, const float height); ///< Changes all sectors floor vertices with the same areaID to the height
	void ChangeSectorCeilingHeight(const int sectorIndex, const float height); ///< Changes all sectors ceiling vertices with the same areaID to the height
	void ChangeSectorCeilingHeightVertices(const int sectorIndex, const float height, const int ptMask = 7); ///< Changes only the sector ceiling vertices(specified using the ptMask) to the height.
	void ChangeSectorHeightVertices(const int sectorIndex, const float height, const int ptMask = 7); ///< Changes only the sector floor vertices(specified using the ptMask) to the height.
	const int FindNextClosestSector(const kVec3&in origin); ///< Returns the sector that this point is best in. Returns -1 if not inside and above/on a sector.
    const int FindClosestSectorByDistance(const kVec3&in origin); ///< Returns the closest sector. Will return -1 only if the map contains no sectors.
    
    /**
     * @brief Get the Sectors vertex position and height
     * Link 1 is pt1 to pt3
     * Link 2 is pt2 to pt1
     * Link 3 is pt3 to pt2
     * @param sectorIndex
     * @param pt1
     * @param pt2
     * @param pt3
     * @param heights: x is the height of pt1, y is the height of pt2, z is the height of pt3.
     */
	void GetSectorCorners(const int sectorIndex, kVec3&out pt1, kVec3&out pt2, kVec3&out pt3, kVec3&out heights) const;

    /**
     * @brief  Get the 3 sectors links. -1 means there was no sector linked to that edge.
     * Link 1 is pt1 to pt3
     * Link 2 is pt2 to pt1
     * Link 3 is pt3 to pt2
     * @param sectorIndex
     * @param sectorIndex1
     * @param sectorIndex2
     * @param sectorIndex3
     */
	void GetSectorLinks(const int sectorIndex, int&out sectorIndex1, int&out sectorIndex2, int&out sectorIndex3) const; ///< a sectorIndex with -1 is no sector.
	const uint GetSectorNumBridges(const int sectorIndex) const; ///< number of bridge sectors this sector has
	const int GetSectorBridge(const int sectorIndex, const uint bridge) const; ///< Get the sector of the bridge. Use GetSectorNumBridges to loop through them all.
	const int GetSectorAreaID(const int sectorIndex) const;
	const int GetNumSectors() const;
	const int GetNumAreas() const;
	const int GetNumActors() const; ///< number of actors that are in the current maps data
    const int GetSectorFlags(const int sectorIndex) const; ///< Returns a 16 bit unsigned integer. Only the first 16 area flags (up to AAF_MAPPED) are used for sectors.
    void SetSectorFlags(const int sectorIndex, const int flags); ///< Keep in mind sector flags are a 16 bit unsigned integer and only the first 16 area flags (up to AAF_MAPPED) are used for sector flags.
    const kStr GetSkyMaterial() const;
    void OverrideSkyMaterial(const kStr &in path); ///< Example path: "skies/skyMaterials/sky_brown"  You can clear the sky with an empty string: ""  Do not pass in invalid paths!
    void OverrideFogColor(const int r, const int g, const int b);   ///< rgb values are 0-255
    void ClearOverrideFogColor();   ///< Stops overriding and uses the sector color
    void OverrideWaterFogColor(const int r, const int g, const int b);  ///< rgb values are 0-255
    void ClearOverrideWaterFogColor();   ///< Stops overriding and uses the sector color
    const int FindClosestSectorByDistance(const kVec3&in origin);
    const float GetAreaWaterHeight(const int area) const;
    const float GetAreaFogZFar(const int area) const;
    void SetAreaFogZFar(const int area, const float zfar);
    const float GetAreaWaterZFar(const int area) const;
    void SetAreaWaterZFar(const int area, const float zfar);
    const kVec3 GetAreaFogColor(const int area) const;  ///< color values are in range 0-255
    void SetAreaFogColor(const int area, const kVec3 &in color);    ///< color values are in range 0-255
    const kVec3 GetAreaWaterColor(const int area) const;    ///< color values are in range 0-255
    void SetAreaWaterColor(const int area, const kVec3 &in color);  ///< color values are in range 0-255
    const float GetAreaSkyHeight(const int area) const;
    void SetAreaSkyHeight(const int area, const float height);
    const float GetAreaSkySpeed(const int area) const;      ///< speed scale is this value / 100. 100 is normal speed.
    void SetAreaSkySpeed(const int area, const float speed);    ///< speed scale is this value / 100. 100 is normal speed.
    const float GetAreaBlendLength(const int area) const;   ///< the speed to interpolate the fog color/start/zfar values when they change
    void SetAreaBlendLength(const int area, const float blendLength); ///< a blendLength value of 1.0 interpolates the fog color/start/zfar values at 0.066666 (1/15) per tick.
    const int GetAreaAmbience(const int area) const;
    void SetAreaAmbience(const int area, const int ambience);
    const int GetAreaMapColor(const int area) const;
    void SetAreaMapColor(const int area, const int color);
    const int GetAreaMusic(const int area) const;
    void SetAreaMusic(const int area, const int music);
    const int GetAreaCullBits(const int area) const;    ///< if any staticmeshes cullBits have any of the area cullBits set then it will draw. (default callbits is 255)
    void SetAreaCullBits(const int area, const int bits);   ///< if any staticmeshes cullBits have any of the area cullBits set then it will draw. (default callbits is 255)
    const int GetSectorDrawOrder(const int sectorIndex) const;      ///< lowest draw order (0) draws the sectors on the automap last
    void SetSectorDrawOrder(const int sectorIndex, const int drawOrder);    ///< lowest draw order (0) draws the sectors on the automap last
};

class kGame
{
public:
	void CallDelayedMapScript(const kStr&in funcName, kActor@ instigator, const float delay); ///< even with delay 0 it will be called when map scripts update
	void CallDelayedMapScript(const int scriptID, kActor@ instigator, const float delay); ///< even with delay 0 it will be called when map scripts update
    void CallMapScript(const int scriptID, kActor@ instigator); ///< Use to call map script right away
	void HaltMapScript(const int scriptID);
	void PlaySound(const kStr&in path);
	void PlaySoundID(const int soundID);
	void PlayMusic(const kStr&in path, const bool loop);
	bool MusicIsPlaying();
	bool MusicIsPaused();
	void PauseMusic();
	void ResumeMusic();
	kStr MusicSong();
	void MusicPitch(const float pitch);

    /**
     * @brief Start controller vibration from tactile sound file. Returns a handle.
     * @param path the path to the .bnvib file
     * @param channel kexVibrationPlayer::channel_e
     * @param pos kexVibrationPlayer::position_e
     */
	int PlayTactile(const kStr&in path, int channel, int pos);
	bool IsTactilePlaying(int vibHandle);
	bool IsTactilePlaying(int vibHandle, const kStr&in path);
	void StopMusic();
	void StopTactile(int vibHandle);
	void StopAllTactile();
	void Restart();

    /**
     * @brief Print a message to the HUD
     * @param text
     * @param lineNumber must be in range 0..7
     * @param ticks number of ticks message will be visible. 60 ticks = 1 second.
     */
	void PrintLine(const kStr&in text, const int lineNumber, const int ticks = 120);
    /**
     * @brief Print a message to the HUD on the next line.
     * @param text
     * @param ticks number of ticks message will be visible. 60 ticks = 1 second.
     */
    void Print(const kStr &in text, const int ticks = 120);
	void PrintHelp(const kStr&in text, const bool endGame = false);
	void StartTimer();
	void StopTimer();
	void RemoveTimer();
	void ChangeMap(const kStr&in path);
	void ShowMainMenu(const bool mouseCenter = true);
	const int GetMapNumberFromName(const kStr&in mapName); ///< This returns the HUB number NOT the map number. mapName is the HUB name such as "Map_Jungle". Returns -1 if not found.
    const int GetMapIDFromName(const kStr &in mapName); ///< This returns the mapID from the mapName. Returns -1 if not found.
	const int GetCurrentMapID();
	const int GetDifficulty(); ///< EnumDifficulty. Internally calls GameVariables.GetInt("g_difficulty")
	void SetDifficulty(const int value); ///< EnumDifficulty
	float GetGameSpeed();

    /**
     * @brief Sets the current GameSpeed. kPuppet and kPlayerWeapon are not affected by GameSpeed.
     * @param speed 0..1
     * @param blendSpeed must be >= 1.0. This is the time it takes to lerp from current speed to the new speed. (lerp time = 1.0 / blendSpeed)
     */
	void SetGameSpeed(const float speed, const float blendSpeed);
	bool GetHubKeyInfo(const uint hubID, int&out nKeys, int&out remainingKeys, int&out keyBits);
	bool SetHubKey(const uint hubID, int key);
	kFx @SpawnFx(const kStr&in fxPath, kActor@ source, const kVec3&in velocity, const kVec3&in origin, const kQuat&in rotation);
	kFx @SpawnFx(const kStr&in fxPath, kPuppet@ source, const kVec3&in velocity, const kVec3&in origin, const kQuat&in rotation);
	kFx @SpawnFx(const kStr&in fxPath, kActor@ source, const kVec3&in origin, const kQuat&in rotation);
	kFx @SpawnFx(const kStr&in fxPath, kPuppet@ source, const kVec3&in origin, const kQuat&in rotation);
	kFx @SpawnFx(const kStr&in fxPath, kActor@ source, const kVec3&in origin, const float yaw, const float pitch);
	kFx @SpawnFx(const kStr&in fxPath, kPuppet@ source, const kVec3&in origin, const float yaw, const float pitch);
	kFx @SpawnFx(const kStr&in fxPath, const kVec3&in origin, const int sectorIndex);
	kStr GetLocalizedText(const kStr&in key);
	const bool AutomapEnabled(); ///< is the automap displaying on screen
	const bool AutomapDeactived();
	void AutomapToggle(const bool toggle); ///< show/hide the automap.
	void AutomapDeactive(const bool toggle); ///< permanently deactivates the automap.
	void AutomapCustom(const bool toggle); ///< allow actors with custom automap colors to be drawn to the automap. (for mods)
	void LifeForcePulse(); ///< Shows the LifeForces on the HUD
	void LivesPulse(); ///< Shows the Lives on the HUD
	void RunWalkPulse(); ///< Shows the RunWalk graphic on the HUD
	void WeaponWheelPulse(); ///< Shows the WeaponWheel on the HUD
	bool SetWeaponWheelPic(const int weapon, const kStr&in imagePath);
	bool ClearWeaponWheelPic(const int weapon);
	void SetLivesPic(const kStr&in imagePath);
	void ClearLivesPic();
	void SetLifeForcePic(const kStr&in imagePath);
	void ClearLifeForcePic();
	void MessageBox(const kStr&in msg1, const kStr&in msg2);

    /**
     * @brief
     * @param msg1 top line
     * @param msg2 bottom line
        @code{.cpp}
            // Usage:
            Game.ConfirmMenu("Confirm This", "Is that correct?");

            // Then check for result on Tick:

            int result;
            GameVariables.GetInt("ConfirmMenuResult", result);
            switch(result)
            {
            case 1:
                Sys.Print("Selected No");
                GameVariables.SetValue("ConfirmMenuResult", "0");
                break;
            case 2:
                Sys.Print("Selected Yes");
                GameVariables.SetValue("ConfirmMenuResult", "0");
                break;
            default: // There's no ConfirmMenuResult waiting
                break;
            }
        @endcode
     */
	void ConfirmMenu(const kStr&in msg1, const kStr&in msg2);
	void SaveMenu(); ///< Opens the save game menu. Should always check if(PlayLoop.CanOpenSaveMenu())
	void LoadMenu(); ///< Opens the load game menu. Should always check if(PlayLoop.CanOpenPauseMenu())
	void SetDamageFlash(); ///< Shows the damage screen flash
	void SetPickupFlash(); ///< Shows the pickup screen flash
	void SetArmorFlash(); ///< Shows the armor damage screen flash
	const uint ConButtons(); ///< EnumPlayerConButtons
    uint MenuButtons(void) ///< EnumGameButtonEvents
	const int64 GetTimestamp();
	void GetDateAndTime(int&out seconds, int&out minutes, int&out hours, int&out day, int&out month, int&out year, kStr&out text);
	void KillAllFx();
	void StopSounds();

    /**
     * @brief add custom text to the HUD. HUD size is 640x480 (pillar box). AddPic must be done in OnPostBeginLevel or later.
     * if the id already exists then simply sets all its variables.
     * @param font EnumGameFontType
     * @param edge 1=left side  2=right side (for convenience. You can set to 0 and offset x position with GetHUDOffset() as well)
     */
    void AddText(const int id, const int font, const kStr &in text, const float x, const float y,
                 const int edge = 0, const float scale = 1.0f, const bool center = false, const bool shadow = false,
                 const int r = 255, const int g = 255, const int b = 255, const int a = 255,
                 const int r2 = 255, const int g2 = 255, const int b2 = 255, const int a2 = 255);
    bool SetTextMsg(const int id, const kStr &in text);
    bool SetTextOrigin(const int id, const float x, const float y);
    bool SetTextColor(const int id, const int r = 255, const int g = 255, const int b = 255, const int a = 255);
    bool SetTextColors(const int id, const int r = 255, const int g = 255, const int b = 255, const int a = 255, const int r2 = 255, const int g2 = 255, const int b2 = 255, const int a2 = 255);

    /**
     * @brief Set the text scale, font, edge, center, shadow
     * @param font EnumGameFontType
     * @param edge 1=left side  2=right side (for convenience. You can set to 0 and offset x position with GetHUDOffset() as well)
     */
    bool SetTextProps(const int id, const float scale, const int font = 0, const int edge = 0, const bool center = false, const bool shadow = false);
    void SetTextOrder(const int id, const int order);
    void ClearTextInterpolation(const int id);
    bool RemoveText(const int id);
	void ClearText();
    void GetTextSize(const kStr &in text, const int font, const float scale, float &out width, float &out height); ///< EnumGameFontType
    float GetHUDOffset(const bool user = false); ///< if user is false will return the width to the edge of the screen (negative value). if true will return the width from the menu option "HUD Position".

    /**
     * @brief add custom image to the HUD. HUD size is 640x480 (pillar box). AddPic must be done in OnPostBeginLevel or later.
     * if the id already exists then simply sets all its variables.
     * @param edge 1=left side  2=right side (for convenience. You can set to 0 and offset x position with GetHUDOffset() as well)
     */
    bool AddPic(const int id, const kStr &in path, const float x, const float y, const float w, const float h, const int edge = 0,
                const float s1 = 0.0f, const float t1 = 0.0f, const float s2 = 1.0f, const float t2 = 1.0f,
                const int r = 255, const int g = 255, const int b = 255, const int a = 255);
    bool SetPicTex(const int id, const kStr &in path);
    bool SetPicOrigin(const int id, const float x, const float y);
    bool SetPicEdge(const int id, const int edge); ///< edge 1=left side  2=right side (for convenience. You can set to 0 and offset x position with GetHUDOffset() as well)
    bool SetPicAngle(const int id, const float angle); ///< in rads
    bool SetPicWH(const int id, const float w, const float h);
    bool SetPicUV(const int id, const float s1 = 0.0f, const float t1 = 0.0f, const float s2 = 1.0f, const float t2 = 1.0f);
    bool SetPicColor(const int id, const int r = 255, const int g = 255, const int b = 255, const int a = 255);
    void SetPicOrder(const int id, const int order);
    void ClearPicInterpolation(const int id);
    bool RemovePic(const int id);
    void ClearPics(const bool clearImageCache = false);
	bool& HideHealth();         ///< Hide health display on the HUD
	bool& HideAmmo();           ///< Hide ammo display on the HUD
	bool& HideLifeForces();     ///< Hide LifeForces display on the HUD
	bool& HideRunWalk();        ///< Hide RunWalk display on the HUD
	bool& HideLives();          ///< Hide Lives display on the HUD
	bool& HideBossBar();        ///< Hide BossBar display on the HUD
	bool& HideAirBar();         ///< Hide AirBar display on the HUD
	bool& HideWeaponWheel();    ///< Hide WeaponWheel display on the HUD
	bool& HideCrosshair();      ///< Hide Crosshair display on the HUD
	bool& HideHelpMessages();   ///< Hide HelpMessages display on the HUD
	bool& HideMessages();       ///< Hide Messages display on the HUD
	bool& HideTimers();         ///< Hide Timers display on the HUD
    const float GetMaxZDrawDistance();  ///< Returns GetExtraZFar + the max z-draw distance from the active map def.
	const float GetExtraZFar(); ///< a custom amount for modders to add to the zfar value
	void SetExtraZFar(const float zfar); ///< affects actors, ai, particles, fog and underwater. (works normally unlike the cvar r_zfarextent)
	const float ShakeIntensity();
	kVec3 WorldToHUDPoint(const kVec3&in origin);
	bool SphereInView(const kVec3&in origin, const float radius);
	bool BoxInView(const kVec3&in min, const kVec3&in max);
	const float ViewZFar();
	void SaveModFile(const kStr&in filename); ///< Saves a custom save file. make sure to call GameModFileData.Empty() before adding key/values to save
	bool LoadModFile(const kStr&in filename); ///< Loads a custom save file. make sure to call GameModFileData.Empty() after you're done loading
    bool LoadModDataFile(const kStr&in filename); ///< Load any file in your mod that is a kDict binary. Use the python T1_json2modbin.py on the main scripting manual page to convert a json file to a kDict binary. Returns false if couldn't load file. Clears and Sets GameModFileData with the contents of the loaded file.
	void SetNoModSelect(const bool bToggle = true); ///< Disable the mod select menu when selecting new game for workshop mods only. (seta g_nomodselect "1")
	void PlayMovie(const kStr&in filename, const bool skippable = true); ///< Only .ogv or .webm files (replaces/adds extension to filename automatically). Can not read from kpfs.

    /**
     * @brief Returns the key bind name of action. Returns empty string if nothing is bound.
     * @param action EnumInputActions
     * @param first if is false returns a string of all the bound keys separated by the ; character.
     * @param sort sorts binds by keyboard, mouse, and controller binds. depending on if controller or keyboard is active.
     */
	kStr GetActionBind(const int action, const bool first = true, const bool sort = true);

    /**
     * @brief Returns the key bind name of the console command. Returns empty string if nothing is bound.
     * @param command the name of the console command.
        @code{.cpp}
        "weapon 0" to "weapon 13"
        "automap"
        "changeammotype"
        "runwalktoggle"
        "menu_up"
        "menu_down"
        "menu_left"
        "menu_right"
        "*menu_select"
        "menu_back"
        "menu_cancel"
        "menu_activate"
        @endcode
     * @param first if is false returns a string of all the bound keys separated by the ; character.
     * @param sort sorts binds by keyboard, mouse, and controller binds. depending on if controller or keyboard is active.
     */
	kStr GetCommandBind(const kStr&in command, const bool first = true, const bool sort = true);
	bool IsJoystickActive(); ///< if true the players last input was from a controller.
	kStr GetInputImagePath(const kStr&in bindName);
	bool InputImageExists(const kStr&in path);
	void SetCursorHotPos(int x, int y); ///< change the mouses cursors click point (default is 0, 0)
	void SetModBindings(const bool show = true); ///< Shows custom mod bindings in menu Bindings > Actions
	kStr PlayerName(); ///< Returns "Player" if could not get name
	void MarkActorPersistentBit(const int actorIndex, const bool clear = false, const int hubID = -1, const int mapNum = 0); ///< an invalid hub or map uses current maps persistent data.
	const bool IsActorPersistentMarked(const int actorIndex, const int hubID = -1, const int mapNum = 0); ///< an invalid hub or map uses current maps persistent data.
	const bool GetPreventOpenPauseMenu();
	void SetPreventOpenPauseMenu(const bool value);
	void ShowPauseMenu(); ///< Should always check if(PlayLoop.CanOpenPauseMenu())
	void OverrideSkyHeight(const float height); ///< Set to 0 to stop overriding
	const int BossDamageScaler(const int difficulty, const int damage);
	int PurgeUnusedModels(); ///< Returns number of models freed
	void CenterMouse();
	kVec3 GetWorldSunLightColor();
	kVec3 GetWorldSunAmbientColor();
	kVec3 GetWorldSunDirection();
	void SetWorldSunLightColor(const float r, const float g, const float b);
	void SetWorldSunAmbientColor(const float r, const float g, const float b);
	void SetWorldSunDirection(const float x, const float y, const float z);
	bool IsWorkshop(); ///< Returns true if game was run through the steam workshop (ran with command arg -workshop)
	void OverridePerPolyCollision(const int value); ///< 0=none, 1=force disable, 2=force enable
	void DisableLegalText(); ///< Removes the text at the bottom of the title screen
	void OverrideFogType(const int value); ///< 0=none, 1=force Radial, 2=force Plane
    void ClearInterpolationOnGameObjects(); ///< Clears Interpolation on all gameobjects and the camera if it's active
    void ShowDummyMenu(void); ///< Actors OnMenuTick function will now be processed. Call ClearDummyMenu to close the dummy menu.
    void ClearDummyMenu(bool bClearAll = false);
    void ToggleCursor(bool b = false);
    void OpenBindingsMenu();
    void OpenOptionsMenu(); ///< saves config file when exiting this menu
    void OpenHeadBobbingMenu();
    void OpenActionBindingsMenu();
    void OpenWeaponBindingsMenu();
    void OpenMenuBindingsMenu();
    void OpenAutomapBindingsMenu();
    void OpenLevelKeysMenu();
    void OpenHUDOptionsMenu();
    void OpenGameplayMenu();
    void OpenGraphicsMenu();
    void OpenAudioMenu();
    bool EnemiesAlwaysDropItems();  ///< Returns the gameplay menu option value
    void OverrideRespawningEnemies(const int value);  ///< Set: Game.OverrideRespawningEnemies();  Get: GameVariables.GetInt("OverrideRespawningEnemies", result);  0=none, 1=force disable, 2=force enable
    void PlayMusicID(const int musicID, const int fadeTimeMS = 500, const bool loop = true);
    bool MusicIsFading();
    bool IsRunningMapScript(const int scriptID);
    kStr GetMapNameFromID(const int mapID); ///< Finds the name of the map with the mapID
    const float GetMaxZDrawDistance();  ///< Returns GetExtraZFar + the max z-draw distance from the active map def.
    bool IsCheatActive(const int cheatBits); ///< EnumCheatFlags. Returns true if cheats are active
    void SetWaterReflectionAlpha(const float alpha);            ///< Default is 1.0f
    void EnableWaterReflectionViewPoint(const bool enable);
    void SetWaterReflectionViewPoint(const kVec3 &in point);
    void NextSoundVolumeScale(const float volume);  ///< The next play sound will scale the volume by this much
    void NextSoundPitchScale(const float pitch);   ///< The next play sound will scale the pitch by this much
    kDictMem @GetActorDef(const kStr &in name); ///< Returns the Actors Def by name
    kDictMem @GetActorDef(const int type);   ///< Returns the Actors Def by it's type
    void GetActorInBounds(const kVec3 &in min, const kVec3 &in max);    ///< The array of actors is stored in Game.GetActorResult. (KD-Tree search). Each actors bounds is calculated as MAX(radius, height) + position.
    void GetFxInBounds(const kVec3 &in min, const kVec3 &in max);   ///< The array of Fx is stored in Game.GetFxResult. (KD-Tree search). Each Fx bounds is calculated as MAX(radius, height) + position.
    void GetSectorInBounds(const kVec3 &in min, const kVec3 &in max);   ///< The array of sectors is stored in Game.GetSectorResult. (KD-Tree search)
    uint GetActorResultsLength();   ///< Use after calling Game.GetActorInBounds
    uint GetFxResultsLength();  ///< Use after calling Game.GetFxInBounds
    uint GetSectorResultsLength();  ///< Use after calling Game.GetSectorInBounds
    kActor @GetActorResult(const uint index); ///< Use after calling Game.GetActorInBounds. Do not use at any other point!
    kFx @GetFxResult(const uint index); ///< Use after calling Game.GetFxInBounds. Do not use at any other point!
    int @GetSectorResult(const uint index); ///< Use after calling Game.GetSectorInBounds. Do not use at any other point!
    void NextSpawnFxSetResults(); ///< On the next call to SpawnFx or any other function that calls SpawnFx (such as SpawnProjectile and FireProjectile), all the Fx that were spawned will be stored in Game.GetFxResult. Do not make nested calls to this!
    kStr GetFxFile(const int fxID); ///< Returns the file path to the Fx by ID value as defined in defs/fileLookup.txt
};

/**
 * @class kFxIterator
 * @brief The way to iterate through all Fx in the map. Example code:
 * @code{.cpp}
 *  kFxIterator it;
 *  kFx @fx;
 *  while((@fx = it.Get()) !is null)
 *  {
 *      // Do something with fx
 *  }
 * @endcode
 */
class kFxIterator
{
public:
	kFxIterator();
	kFx@ Get(); ///< Returns the next Fx in the iterator
	void Reset(); ///< Resets the iterator back to the first Fx
};

class kPlayer
{
public:
	const uint16 Buttons() const; ///< returns EnumPlayerButtons
	uint ButtonHeldTime(const int btn); ///< btn type is EnumInputActions
	kPuppet@ Actor();
	void ConsumeAmmo(const int ammo, const bool preferredAmmo = true);
	void ConsumeAltAmmo(const int ammo);
	const int GetAmmo(const int weaponID) const;
	const int GetAltAmmo(const int weaponID) const;
	const bool HasAmmo(const int weaponID, const bool checkAlt = true) const; ///< if checkAlt is false only checks primary ammo
	const bool HasAltAmmo(const int weaponID) const;
	const bool HasAltAmmo() const;
	const bool HasWeapon(const int weaponID) const;
	bool& UseAltAmmo();
	const int CurrentWeapon() const;
	bool GiveWeapon(const int weaponID, const int ammo, const bool switchNewWeapon = true); ///< returns true if gave ammo else returns false because already has full primary ammo. if switchNewWeapon is false it will not auto switch to the weapon.
	bool RemoveWeapon(const int weapon);
	void Lock();
	void Unlock();
	int16& Armor();
	void Victory(const int warpActorID = - 1, const int mapID = - 1);
	const bool Locked() const;
	const int Lives() const;
	void SetLives(const int amount);
	const int LifeForces();
	void SetLifeForces(const int amount);
	bool& Backpack();
	bool& RunWalkToggle(); ///< if true walking is enabled. (saves)
	bool& NoLandClearVel(); ///< if true, when doing a hard landing you will not lose your velocity (saves)
    bool &NoWeaponSwitchOnWaterLand(); ///< will not auto switch weapon when entering/exiting water. (saves)
	bool GiveAmmo(const int weapon, const int amount, const bool altAmmo); ///< set amount to negative values to take ammo
	const int CurrentCheckPoint(); ///< returns warpTID
	const int CurrentCheckPointMap();
	void SetCheckPoint(const int warpTID, const int map);
	const kVec3 GetButtonAngles() const;
	const kVec3 GetButtonMovement() const;
	const bool WeaponUsingAltAmmo(const int weapon) const;
	const bool SetWeaponUseAltAmmo(const int weapon, const bool bToggle);
	const bool WeaponAllowUnderwater(const int weapon) const;
	void ChangeWeapon(const int weapon);
	const int PendingWeapon() const;
	void CycleNextWeapon(const bool bCheckAmmo = false);
	void CyclePrevWeapon(const bool bCheckAmmo = false);
	kWeapon@ GetWeaponActor(const int weapon);
	int16& MaxHealth(); ///< should be >= MaxExtraHealth and ExtraHealth
	int16& MaxExtraHealth(); ///< should be <= MaxHealth
	int16& ExtraHealth(); ///< should be <= MaxExtraHealth
	bool GiveHealth(const int amount, const bool bMortalWound); ///< Takes into account extra health, and max health values. 0 is full health, negative amounts give extra health. if bMortalWound is true which is for 2 and ultra health then health goes up to maxExtraHealth.
	void CancelSpiritualTime(float blendTime = 1.0f); ///< if in spirit mode then will set gamespeed back to 1.0f using the passed in blendTime
	void SetSpiritualTime(const float time, const float blend); ///< time = time until cancels the effect. Should SetGameSpeed after calling this.
	const float GetSpiritualTime() const;
	const int GetWeaponGroup(const int weapon);

    /**
     * @brief Binds this weapon to another weapons index. Example: you made a new pistol weapon at index 14 and want to group it with default pistol that has the index 2.
     * then set your new pistols(14) group to 2 and whenever the user presses the key assigned to the original pistol 2 it will cycle between them. instead of the user having to cycle to the new weapon with next/prev weapon inputs. The group can also be set in weaponInfo.txt def file with the key "group"
     */
	void SetWeaponGroup(const int weapon, const int group);
    bool &SilentCheckPoints(void); ///< if true won't show checkpoint message or play sound when on a checkpoint area. Gets set back to false when level starts.
    float &LookSensScale(); ///< Scales mouse/controller/gyro sensitivity (default = 1.0f)
};

namespace Math
{
	float Sin(float f); ///< Returns the sine of angle f in radians
	float Cos(float f); ///< Returns the cosine of angle f in radians
	float Tan(float f); ///< Returns the tangent of angle f in radians.
	float ATan2(float y, float x); ///< Returns the angle in radians whose Tan is y/x
	float Fabs(float f); ///< Returns the absolute value of f
	float ACos(float f); ///< Returns the arc-cosine of f - the angle in radians whose cosine is f
	float Sqrt(float f); ///< Returns square root of f
	int Abs(int i); ///< Returns the absolute value of i.
	float Ceil(float f); ///< Returns the smallest integer greater to or equal to f
	float Floor(float f); ///< Returns the largest integer smaller to or equal to f
	float Log(float f); ///< Returns the natural (base e) logarithm of a specified number
	float Pow(float x, float y); ///< Returns f raised to power p
	float Deg2Rad(float degs); ///< Degrees-to-radians conversion
	float Rad2Deg(float rads); ///< Radians-to-Degrees conversion
	float InvSqrt(float f); ///< Returns inverse square root of f
	float IncMax(const float val, const float inc, const float dest); ///< returns val +(or minus) inc and never goes above or below dest value
	int SysRand(); ///< Range 0..32767
	int Rand(); ///< Range 0..32767
	uint8 RandByte(); ///< Range 0..255
	int RandMax(const int max); ///< Range 0..max-1
	float NLerp(const float a, const float b, const float t); ///< Calculates the linear parameter t that produces the interpolant value within the range [a, b]
	float Accelerate(const float val, const float accel, const float max); ///< return val that increases by accel in a weird way to the max value.
	float RandFloat(); ///< Range 0..1
	float RandCFloat(); ///< Range -1..1
	float RandRange(const float min, const float max); ///< Returns a random float number between and min [inclusive] and max [inclusive]
	int Clamp(const int i, const int min, const int max); ///< Returns clamped value between min and max
	float Clampf(const float f, const float min, const float max); ///< Returns clamped value between min and max
	float Lerp(float start, const float end, const float time); ///< Linearly interpolates between start and end by time.
	float CosTween(const float t); ///< return (0.5f - (Cos(t * pi) * 0.5f));
	float CosArc(const float t); ///< return (-((Cos(Deg2Rad(360.0f * t)) - 1.0f) * 0.5f));
	float SmoothStep(const float from, const float to, const float t); ///< Interpolates between min and max with smoothing at the limits.
	float HermiteBlend(const float a, const float b, const float t);
	float Min(const float a, const float b); ///< Returns the smallest of the two values
	float Max(const float a, const float b); ///< Returns the largest of the two values
	const int f2i(const float f); ///< IEEE 754 float to int
	const float i2f(const int i); ///< int to IEEE 754 float
	const float pi = 3.1415927f;
	const float tau = 6.2831855f; ///< pi * 2
	const kVec3 vecZero(0.0f, 0.0f, 0.0f);
}

namespace kexColors ///< Not used (garbage included automatically from kexengine)
{
	const kColor white;         ///< 255, 255, 255, 255
	const kColor gray;          ///< 127, 127, 127, 255
	const kColor black;         ///< 0,     0,   0, 255
	const kColor red;           ///< 255,   0,   0, 255
	const kColor green;         ///< 0,   255,   0, 255
	const kColor blue;          ///< 0,     0, 255, 255
	const kColor yellow;        ///< 255, 255,   0, 255
	const kColor orange;        ///< 255, 127,   0, 255
	const kColor cyan;          ///< 0,   255, 255, 255
	const kColor magenta;       ///< 255,   0, 255, 255
	const kColor transparent;   ///<   0,   0,   0,   0
	const kColor tab20blue;
	const kColor tab20blue2;
	const kColor tab20orange;
	const kColor tab20orange2;
	const kColor tab20green;
	const kColor tab20green2;
	const kColor tab20red;
	const kColor tab20red2;
	const kColor tab20purple;
	const kColor tab20purple2;
	const kColor tab20brown;
	const kColor tab20brown2;
	const kColor tab20pink;
	const kColor tab20pink2;
	const kColor tab20grey;
	const kColor tab20grey2;
	const kColor tab20olive;
	const kColor tab20olive2;
	const kColor tab20cyan;
	const kColor tab20cyan2;
}

/**
 * @brief
 * @param s the string you want to split
 * @param sep the separators you want to use to split the string
    @code{.cpp}
        kStr myString = "Hello,World!";
        kStrSplit(myString, ",");
        for(uint i = 0; i < kStrSplitLength(); i++)
        {
            kStr stringPart = kStrSplitGet(i);
            Sys.Print("SplitStrings[" + i + "] len=" + stringPart.Length() + ": " + stringPart);
        }
        kStrSplitClear();
    @endcode
 */
void kStrSplit(const kStr &in s, const kStr &in sep);
kStr kStrSplitGet(const int index); ///< returns the string at index
uint kStrSplitLength(); ///< returns the amount of strings that were split
void kStrSplitClear(); ///< clear the list of split strings after your done. Not required to call because it gets cleared when you call kStrSplit but if you don't want those strings still hanging around you can clear them now.
kColor kexColor_FromHSL(float hue, float sat, float lit); ///< Not used. (garbage from kexengine)
kColor kexColor_Random(); ///< Not used. (garbage from kexengine)
kColor kexColor_Tab20(uint i); ///< Not used. (garbage from kexengine)
kColor kexColor_Tab20Dark(uint i); ///< Not used. (garbage from kexengine)
kColor kexColor_Tab20Light(uint i); ///< Not used. (garbage from kexengine)
kColor kexColor_ViridisScale(float v); ///< Not used. (garbage from kexengine)
kColor kexColor_LerpRGB(const kColor&in from, const kColor&in to, float time); ///< Not used. (garbage from kexengine)
int kexRandInt(); ///< Range -2147483648..2147483647
uint kexRandUInt() ///< Range 0..4294967295
void delay(const float time); ///< used in map scripts to delay execution of script
const float GAME_FRAME_TIME = 0.25f;
const float GAME_DELTA_TIME = 0.016666668f;
const float GAME_FRAME_UNIT = 4.0f;
const float GAME_SECONDS = 0.06666667f;
const float GAME_SCALE = 10.24f;
kSys Sys;
kDict GameVariables;
kDict GameModFileData; ///< Use with Game.SaveModFile, Game.LoadModFile, and Game.LoadModDataFile
kGame Game;
kActorFactory ActorFactory;
kPlayLoop PlayLoop;
kPlayer Player;
kCamera Camera;
kWorld World;
kCModel CModel;
