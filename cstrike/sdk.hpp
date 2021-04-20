#ifndef CS_SDK_HPP
#define CS_SDK_HPP

#include "SDL2/SDL.h"
typedef int qboolean;
typedef unsigned int string_t;
typedef float vec3_t[3];
typedef int int32;
typedef int EOFFSET;
typedef float vec_t;
typedef unsigned int uint32;
typedef unsigned int _size_t;
#define size_t _size_t
typedef unsigned char byte;
#ifdef _WIN32
#include <Windows.h>
#else
#define FALSE 0
#define TRUE (!FALSE)
#define MAX_PATH PATH_MAX
typedef uint32 ULONG;
typedef unsigned char BYTE;
typedef int BOOL;
typedef void *HWND;
#endif

typedef enum _fieldtypes {FIELD_FLOAT, FIELD_STRING, FIELD_ENTITY, FIELD_CLASSPTR, FIELD_EHANDLE, FIELD_EVARS, FIELD_EDICT, FIELD_VECTOR, FIELD_POSITION_VECTOR, FIELD_POINTER, FIELD_INTEGER, FIELD_FUNCTION, FIELD_BOOLEAN, FIELD_SHORT, FIELD_CHARACTER, FIELD_TIME, FIELD_MODELNAME, FIELD_SOUNDNAME, FIELD_TYPECOUNT} FIELDTYPE;
typedef enum {USE_OFF, USE_ON, USE_SET, USE_TOGGLE} USE_TYPE;
typedef enum {TS_AT_TOP, TS_AT_BOTTOM, TS_GOING_UP, TS_GOING_DOWN} TOGGLE_STATE;
typedef enum {ACT_RESET, ACT_IDLE, ACT_GUARD, ACT_WALK, ACT_RUN, ACT_FLY, ACT_SWIM, ACT_HOP, ACT_LEAP, ACT_FALL, ACT_LAND, ACT_STRAFE_LEFT, ACT_STRAFE_RIGHT, ACT_ROLL_LEFT, ACT_ROLL_RIGHT, ACT_TURN_LEFT, ACT_TURN_RIGHT, ACT_CROUCH, ACT_CROUCHIDLE, ACT_STAND, ACT_USE, ACT_SIGNAL1, ACT_SIGNAL2, ACT_SIGNAL3, ACT_TWITCH, ACT_COWER, ACT_SMALL_FLINCH, ACT_BIG_FLINCH, ACT_RANGE_ATTACK1, ACT_RANGE_ATTACK2, ACT_MELEE_ATTACK1, ACT_MELEE_ATTACK2, ACT_RELOAD, ACT_ARM, ACT_DISARM, ACT_EAT, ACT_DIESIMPLE, ACT_DIEBACKWARD, ACT_DIEFORWARD, ACT_DIEVIOLENT, ACT_BARNACLE_HIT, ACT_BARNACLE_PULL, ACT_BARNACLE_CHOMP, ACT_BARNACLE_CHEW, ACT_SLEEP, ACT_INSPECT_FLOOR, ACT_INSPECT_WALL, ACT_IDLE_ANGRY, ACT_WALK_HURT, ACT_RUN_HURT, ACT_HOVER, ACT_GLIDE, ACT_FLY_LEFT, ACT_FLY_RIGHT, ACT_DETECT_SCENT, ACT_SNIFF, ACT_BITE, ACT_THREAT_DISPLAY, ACT_FEAR_DISPLAY, ACT_EXCITED, ACT_SPECIAL_ATTACK1, ACT_SPECIAL_ATTACK2, ACT_COMBAT_IDLE, ACT_WALK_SCARED, ACT_RUN_SCARED, ACT_VICTORY_DANCE, ACT_DIE_HEADSHOT, ACT_DIE_CHESTSHOT, ACT_DIE_GUTSHOT, ACT_DIE_BACKSHOT, ACT_FLINCH_HEAD, ACT_FLINCH_CHEST, ACT_FLINCH_STOMACH, ACT_FLINCH_LEFTARM, ACT_FLINCH_RIGHTARM, ACT_FLINCH_LEFTLEG, ACT_FLINCH_RIGHTLEG, ACT_FLINCH, ACT_LARGE_FLINCH, ACT_HOLDBOMB, ACT_IDLE_FIDGET, ACT_IDLE_SCARED, ACT_IDLE_SCARED_FIDGET, ACT_FOLLOW_IDLE, ACT_FOLLOW_IDLE_FIDGET, ACT_FOLLOW_IDLE_SCARED, ACT_FOLLOW_IDLE_SCARED_FIDGET, ACT_CROUCH_IDLE, ACT_CROUCH_IDLE_FIDGET, ACT_CROUCH_IDLE_SCARED, ACT_CROUCH_IDLE_SCARED_FIDGET, ACT_CROUCH_WALK, ACT_CROUCH_WALK_SCARED, ACT_CROUCH_DIE, ACT_WALK_BACK, ACT_IDLE_SNEAKY, ACT_IDLE_SNEAKY_FIDGET, ACT_WALK_SNEAKY, ACT_WAVE, ACT_YES, ACT_NO} Activity;
typedef enum {MONSTERSTATE_NONE, MONSTERSTATE_IDLE, MONSTERSTATE_COMBAT, MONSTERSTATE_ALERT, MONSTERSTATE_HUNT, MONSTERSTATE_PRONE, MONSTERSTATE_SCRIPT, MONSTERSTATE_PLAYDEAD, MONSTERSTATE_DEAD} MONSTERSTATE;
enum TeamName {UNASSIGNED, TERRORIST, CT, SPECTATOR};
enum JoinState {JOINED, SHOWLTEXT, READINGLTEXT, SHOWTEAMSELECT, PICKINGTEAM, GETINTOGAME};
enum ModelName {MODEL_UNASSIGNED, MODEL_URBAN, MODEL_TERROR, MODEL_LEET, MODEL_ARCTIC, MODEL_GSG9, MODEL_GIGN, MODEL_SAS, MODEL_GUERILLA, MODEL_VIP, MODEL_MILITIA, MODEL_SPETSNAZ};
enum _Menu {Menu_OFF, Menu_ChooseTeam, Menu_IGChooseTeam, Menu_ChooseAppearance, Menu_Buy, Menu_BuyPistol, Menu_BuyRifle, Menu_BuyMachineGun, Menu_BuyShotgun, Menu_BuySubMachineGun, Menu_BuyItem, Menu_Radio1, Menu_Radio2, Menu_Radio3, Menu_ClientBuy};
typedef enum {PLAYER_IDLE, PLAYER_WALK, PLAYER_JUMP, PLAYER_SUPERJUMP, PLAYER_DIE, PLAYER_ATTACK1, PLAYER_ATTACK2, PLAYER_FLINCH, PLAYER_LARGE_FLINCH, PLAYER_RELOAD, PLAYER_HOLDBOMB} PLAYER_ANIM;
enum AutoBuyClassType {AUTOBUYCLASS_PRIMARY = 1, AUTOBUYCLASS_SECONDARY, AUTOBUYCLASS_AMMO = 4, AUTOBUYCLASS_ARMOR = 8, AUTOBUYCLASS_DEFUSER = 16, AUTOBUYCLASS_PISTOL = 32, AUTOBUYCLASS_SMG = 64, AUTOBUYCLASS_RIFLE = 128, AUTOBUYCLASS_SNIPERRIFLE = 256, AUTOBUYCLASS_SHOTGUN = 512, AUTOBUYCLASS_MACHINEGUN = 1024, AUTOBUYCLASS_GRENADE = 2048, AUTOBUYCLASS_NIGHTVISION = 4096, AUTOBUYCLASS_SHIELD = 8192};
typedef enum {mod_brush, mod_sprite, mod_alias, mod_studio} modtype_t;
typedef enum {ST_SYNC, ST_RAND} synctype_t;

typedef void CSquadMonster;
typedef void CWeaponBox;

class CBasePlayer;
class EHANDLE;
struct edict_s;
struct edict_t;
struct link_s;
struct link_t;
struct entvars_s;
struct CBaseEntity;
struct TYPEDESCRIPTION;
struct KeyValueData_s;
class CSave;
class CSaveRestoreBuffer;
struct saverestore_s;
struct ENTITYTABLE;
struct LEVELLIST;
class Vector;
class Vector2D;
struct TraceResult;
class CRestore;
struct HEADER;
class CBaseMonster;
class CBaseToggle;
class CBaseAnimating;
class CBaseDelay;
struct MonsterEvent_t;
class CBasePlayerItem;
struct ItemInfo;
struct AmmoInfo;
class CHintMessageQueue;
class CHintMessage;
template <typename T>
class CUtlVector;
template <typename T>
class CUtlMemory;
class CUnifiedSignals;
struct RebuyStruct;
struct AutoBuyInfoStruct;
class IGame;
class CGame;
struct color24;
struct entity_state_s;
struct entity_state_t;
struct position_history_t;
struct mouth_t;
struct latchedvars_t;
struct model_s;
struct dmodel_t;
struct mplane_s;
struct mplane_t;
struct mnode_s;
struct efrag_s;
struct glpoly_s;
struct glpoly_t;
struct texture_s;
struct texture_t;
struct mtexinfo_t;
struct decal_s;
struct decal_t;
struct msurface_s;
struct msurface_t;
struct mleaf_s;
struct mleaf_t;
struct mvertex_t;
struct medge_t;
struct mnode_s;
struct mnode_t;
struct dclipnode_t;
struct hull_s;
struct cache_user_s;
struct cache_user_t;
struct model_s;
struct colorVec;
struct cl_entity_s;

typedef struct entvars_s {
    string_t classname;
    string_t globalname;
    vec3_t origin;
    vec3_t oldorigin;
    vec3_t velocity;
    vec3_t basevelocity;
    vec3_t clbasevelocity;
    vec3_t movedir;
    vec3_t angles;
    vec3_t avelocity;
    vec3_t punchangle;
    vec3_t v_angle;
    vec3_t endpos;
    vec3_t startpos;
    float impacttime;
    float starttime;
    int fixangle;
    float idealpitch;
    float pitch_speed;
    float ideal_yaw;
    float yaw_speed;
    int modelindex;
    string_t model;
    int viewmodel;
    int weaponmodel;
    vec3_t absmin;
    vec3_t absmax;
    vec3_t mins;
    vec3_t maxs;
    vec3_t size;
    float ltime;
    float nextthink;
    int movetype;
    int solid;
    int skin;
    int body;
    int effects;
    float gravity;
    float friction;
    int light_level;
    int sequence;
    int gaitsequence;
    float frame;
    float animtime;
    float framerate;
    unsigned char controller[4];
    unsigned char blending[2];
    float scale;
    int rendermode;
    float renderamt;
    vec3_t rendercolor;
    int renderfx;
    float health;
    float frags;
    int weapons;
    float takedamage;
    int deadflag;
    vec3_t view_ofs;
    int button;
    int impulse;
    edict_t *chain;
    edict_t *dmg_inflictor;
    edict_t *enemy;
    edict_t *aiment;
    edict_t *owner;
    edict_t *groundentity;
    int spawnflags;
    int flags;
    int colormap;
    int team;
    float max_health;
    float teleport_time;
    float armortype;
    float armorvalue;
    int waterlevel;
    int watertype;
    string_t target;
    string_t targetname;
    string_t netname;
    string_t message;
    float dmg_take;
    float dmg_save;
    float dmg;
    float dmgtime;
    string_t noise;
    string_t noise1;
    string_t noise2;
    string_t noise3;
    float speed;
    float air_finished;
    float pain_finished;
    float radsuit_finished;
    edict_t *pContainingEntity;
    int playerclass;
    float maxspeed;
    float fov;
    int weaponanim;
    int pushmsec;
    int bInDuck;
    int flTimeStepSound;
    int flSwimTime;
    int flDuckTime;
    int iStepLeft;
    float flFallVelocity;
    int gamestate;
    int oldbuttons;
    int groupinfo;
    int iuser1;
    int iuser2;
    int iuser3;
    int iuser4;
    float fuser1;
    float fuser2;
    float fuser3;
    float fuser4;
    vec3_t vuser1;
    vec3_t vuser2;
    vec3_t vuser3;
    vec3_t vuser4;
    edict_t *euser1;
    edict_t *euser2;
    edict_t *euser3;
    edict_t *euser4;
} entvars_t;

struct link_s {
    link_s *prev;
    link_s *next;
};

struct link_t : public link_s {};

struct edict_s {
    qboolean free;
    int serialnumber;
    link_t area;
    int headnode;
    int num_leafs;
    short leafnums[48];
    float freetime;
    void *pvPrivateData;
    entvars_t v;
};

struct edict_t : public edict_s {};

class EHANDLE {
  private:
    edict_t *m_pent;
    int m_serialnumber;

  public:
    edict_t * Get(void);
    edict_t * Set(edict_t *);
    operator int(void);
    operator CBaseEntity*(void);
    CBaseEntity * operator=(CBaseEntity *);
    CBaseEntity * operator->(void);
};

struct TYPEDESCRIPTION {
    FIELDTYPE fieldType;
    char *fieldName;
    int fieldOffset;
    short fieldSize;
    short flags;
};

typedef struct KeyValueData_s {
    char *szClassName;
    char *szKeyName;
    char *szValue;
    int32 fHandled;
} KeyValueData;

struct ENTITYTABLE {
    int id;
    edict_t *pent;
    int location;
    int size;
    int flags;
    string_t classname;
};

struct LEVELLIST {
    char mapName[32];
    char landmarkName[32];
    edict_t *pentLandmark;
    vec3_t vecLandmarkOrigin;
};

typedef struct saverestore_s {
    char *pBaseData;
    char *pCurrentData;
    int size;
    int bufferSize;
    int tokenSize;
    int tokenCount;
    char **pTokens;
    int currentIndex;
    int tableCount;
    int connectionCount;
    ENTITYTABLE *pTable;
    LEVELLIST levelList[16];
    int fUseLandmark;
    char szLandmarkName[20];
    vec3_t vecLandmarkOffset;
    float time;
    char szCurrentMapName[32];
} SAVERESTOREDATA;

class CSaveRestoreBuffer {
  protected:
    SAVERESTOREDATA *m_pdata;

  public:
    CSaveRestoreBuffer(void);
    CSaveRestoreBuffer(SAVERESTOREDATA *);
    ~CSaveRestoreBuffer();
    int EntityIndex(entvars_t *);
    int EntityIndex(edict_t *);
    int EntityIndex(EOFFSET);
    int EntityIndex(CBaseEntity *);
    int EntityFlags(int, int);
    int EntityFlagsSet(int, int);
    edict_t * EntityFromIndex(int);
    unsigned short TokenHash(const char *);
  protected:
    void BufferRewind(int);
    unsigned int HashString(const char *);
};

class Vector2D {
  public:
    vec_t x;
    vec_t y;

    Vector2D(void);
    Vector2D(float, float);
    Vector2D operator+(const Vector2D &) const;
    Vector2D operator-(const Vector2D &) const;
    Vector2D operator*(float) const;
    Vector2D operator/(float) const;
    float Length(void) const;
    float LengthSquared(void) const;
    Vector2D Normalize(void) const;
    bool IsLengthLessThan(float) const;
    bool IsLengthGreaterThan(float) const;
    float NormalizeInPlace(void);
    bool IsZero(float);
};

class Vector {
  public:
    vec_t x;
    vec_t y;
    vec_t z;

    Vector(void);
    Vector(float, float, float);
    Vector(const Vector &);
    Vector(float *);
    Vector operator-(void) const;
    Vector operator-(const Vector &) const;
    int operator==(const Vector &) const;
    int operator!=(const Vector &) const;
    Vector operator+(const Vector &) const;
    Vector operator*(float) const;
    Vector operator/(float) const;
    void CopyToArray(float *) const;
    float Length(void) const;
    float LengthSquared(void) const;
    operator float*(void);
    operator float const*(void) const;
    Vector Normalize(void) const;
    Vector2D Make2D(void) const;
    float Length2D(void) const;
    bool IsLengthLessThan(float) const;
    bool IsLengthGreaterThan(float) const;
    float NormalizeInPlace(void);
    bool IsZero(float);
};

class CSave : public CSaveRestoreBuffer {
  public:
    CSave(SAVERESTOREDATA *);
    void WriteShort(const char *, const short *, int);
    void WriteInt(const char *, const int *, int);
    void WriteFloat(const char *, const float *, int);
    void WriteTime(const char *, const float *, int);
    void WriteData(const char *, int, const char *);
    void WriteString(const char *, const char *);
    void WriteString(const char *, const int *, int);
    void WriteVector(const char *, const Vector &);
    void WriteVector(const char *, const float *, int);
    void WritePositionVector(const char *, const Vector &);
    void WritePositionVector(const char *, const float *, int);
    void WriteFunction(const char *, void **, int);
    int WriteEntVars(const char *, entvars_t *);
    int WriteFields(const char *, void *, TYPEDESCRIPTION *, int);
  private:
    int DataEmpty(const char *, int);
    void BufferField(const char *, int, const char *);
    void BufferString(char *, int);
    void BufferData(const char *, int);
    void BufferHeader(const char *, int);
};

struct TraceResult {
    int fAllSolid;
    int fStartSolid;
    int fInOpen;
    int fInWater;
    float flFraction;
    Vector vecEndPos;
    float flPlaneDist;
    Vector vecPlaneNormal;
    edict_t *pHit;
    int iHitgroup;
};

struct HEADER {
    unsigned short size;
    unsigned short token;
    char *pData;
};

class CRestore : public CSaveRestoreBuffer {
  private:
    int m_global;
    BOOL m_precache;

  public:
    CRestore(SAVERESTOREDATA *);
    int ReadEntVars(const char *, entvars_t *);
    int ReadFields(const char *, void *, TYPEDESCRIPTION *, int);
    int ReadField(void *, TYPEDESCRIPTION *, int, int, int, char *, void *);
    int ReadInt(void);
    short ReadShort(void);
    int ReadNamedInt(const char *);
    char * ReadNamedString(const char *);
    int Empty(void);
    void SetGlobalMode(int);
    void PrecacheMode(BOOL);
  private:
    char * BufferPointer(void);
    void BufferReadBytes(char *, int);
    void BufferSkipBytes(int);
    int BufferSkipZString(void);
    int BufferCheckZString(const char *);
    void BufferReadHeader(HEADER *);
};

struct MonsterEvent_t {
    int event;
    char *options;
};

struct ItemInfo {
    int iSlot;
    int iPosition;
    const char *pszAmmo1;
    int iMaxAmmo1;
    const char *pszAmmo2;
    int iMaxAmmo2;
    const char *pszName;
    int iMaxClip;
    int iId;
    int iFlags;
    int iWeight;
};

struct AmmoInfo {
    const char *pszName;
    int iId;
};

struct CBaseEntity {
  public:
    entvars_t *pev;
    CBaseEntity *m_pGoalEnt;
    CBaseEntity *m_pLink;
    static TYPEDESCRIPTION m_SaveData[];
    void (CBaseEntity::*m_pfnThink)(CBaseEntity * const);
    void (CBaseEntity::*m_pfnTouch)(CBaseEntity * const, CBaseEntity *);
    void (CBaseEntity::*m_pfnUse)(CBaseEntity * const, CBaseEntity *, CBaseEntity *, USE_TYPE, float);
    void (CBaseEntity::*m_pfnBlocked)(CBaseEntity * const, CBaseEntity *);
    int *current_ammo;
    float currentammo;
    int maxammo_buckshot;
    int ammo_buckshot;
    int maxammo_9mm;
    int ammo_9mm;
    int maxammo_556nato;
    int ammo_556nato;
    int maxammo_556natobox;
    int ammo_556natobox;
    int maxammo_762nato;
    int ammo_762nato;
    int maxammo_45acp;
    int ammo_45acp;
    int maxammo_50ae;
    int ammo_50ae;
    int maxammo_338mag;
    int ammo_338mag;
    int maxammo_57mm;
    int ammo_57mm;
    int maxammo_357sig;
    int ammo_357sig;
    float m_flStartThrow;
    float m_flReleaseThrow;
    int m_iSwing;
    bool has_disconnected;

    virtual void Spawn(void);
    virtual void Precache(void);
    virtual void Restart(void);
    virtual void KeyValue(KeyValueData *);
    virtual int Save(CSave &);
    virtual int Restore(CRestore &);
    virtual int ObjectCaps(void);
    virtual void Activate(void);
    virtual void SetObjectCollisionBox(void);
    virtual int Classify(void);
    virtual void DeathNotice(entvars_t *);
    virtual void TraceAttack(entvars_t *, float, Vector, TraceResult *, int);
    virtual int TakeDamage(entvars_t *, entvars_t *, float, int);
    virtual int TakeHealth(float, int);
    virtual void Killed(entvars_t *, int);
    virtual int BloodColor(void);
    virtual void TraceBleed(float, Vector, TraceResult *, int);
    virtual BOOL IsTriggered(CBaseEntity *);
    virtual CBaseMonster * MyMonsterPointer(void);
    virtual CSquadMonster * MySquadMonsterPointer(void);
    virtual int GetToggleState(void);
    virtual void AddPoints(int, BOOL);
    virtual void AddPointsToTeam(int, BOOL);
    virtual BOOL AddPlayerItem(CBasePlayerItem *);
    virtual BOOL RemovePlayerItem(CBasePlayerItem *);
    virtual int GiveAmmo(int, char *, int);
    virtual float GetDelay(void);
    virtual int IsMoving(void);
    virtual void OverrideReset(void);
    virtual int DamageDecal(int);
    virtual void SetToggleState(int);
    virtual void StartSneaking(void);
    virtual void StopSneaking(void);
    virtual BOOL OnControls(entvars_t *);
    virtual BOOL IsSneaking(void);
    virtual BOOL IsAlive(void);
    virtual BOOL IsBSPModel(void);
    virtual BOOL ReflectGauss(void);
    virtual BOOL HasTarget(string_t);
    virtual BOOL IsInWorld(void);
    virtual BOOL IsPlayer(void);
    virtual BOOL IsNetClient(void);
    virtual const char * TeamID(void);
    virtual CBaseEntity * GetNextTarget(void);
    virtual void Think(void);
    virtual void Touch(CBaseEntity *);
    virtual void Use(CBaseEntity *, CBaseEntity *, USE_TYPE, float);
    virtual void Blocked(CBaseEntity *);
    /* static void * operator new(size_t, entvars_t *); */ /* -fpermissive */
    void UpdateOnRemove(void);
    void SUB_Remove(void);
    void SUB_DoNothing(void);
    void SUB_StartFadeOut(void);
    void SUB_FadeOut(void);
    void SUB_CallUseToggle(void);
    int ShouldToggle(USE_TYPE, BOOL);
    void FireBullets(ULONG, Vector, Vector, Vector, float, int, int, int, entvars_t *);
    Vector FireBullets3(Vector, Vector, float, float, int, int, int, float, entvars_t *, bool, int);
    virtual CBaseEntity * Respawn(void);
    void SUB_UseTargets(CBaseEntity *, USE_TYPE, float);
    int Intersects(CBaseEntity *);
    void MakeDormant(void);
    int IsDormant(void);
    BOOL IsLockedByMaster(void);
    static CBaseEntity * Instance(edict_t *);
    static CBaseEntity * Instance(entvars_t *);
    static CBaseEntity * Instance(int);
    CBaseMonster * GetMonsterPointer(entvars_t *);
    CBaseMonster * GetMonsterPointer(edict_t *);
    virtual void UpdateOwner(void);
    static CBaseEntity * Create(char *, const Vector &, const Vector &, edict_t *);
    virtual BOOL FBecomeProne(void);
    edict_t * edict(void);
    EOFFSET eoffset(void);
    int entindex(void);
    virtual Vector Center(void);
    virtual Vector EyePosition(void);
    virtual Vector EarPosition(void);
    virtual Vector BodyTarget(const Vector &);
    virtual int Illumination(void);
    virtual BOOL FVisible(CBaseEntity *);
    virtual BOOL FVisible(const Vector &);
};

class CBaseDelay : public CBaseEntity {
  public:
    float m_flDelay;
    int m_iszKillTarget;
    static TYPEDESCRIPTION m_SaveData[];

    virtual void KeyValue(KeyValueData_s *);
    virtual int Save(CSave &);
    virtual int Restore(CRestore &);
    void SUB_UseTargets(CBaseEntity *, USE_TYPE, float);
    void DelayThink(void);
};

class CBaseAnimating : public CBaseDelay {
  public:
    static TYPEDESCRIPTION m_SaveData[];
    float m_flFrameRate;
    float m_flGroundSpeed;
    float m_flLastEventCheck;
    BOOL m_fSequenceFinished;
    BOOL m_fSequenceLoops;

    virtual int Save(CSave &);
    virtual int Restore(CRestore &);
    float StudioFrameAdvance(float);
    BOOL GetSequenceFlags(void);
    int LookupActivity(int);
    int LookupActivityHeaviest(int);
    int LookupSequence(const char *);
    void ResetSequenceInfo(void);
    void DispatchAnimEvents(float);
    virtual void HandleAnimEvent(MonsterEvent_t *);
    float SetBoneController(int, float);
    void InitBoneControllers(void);
    float SetBlending(int, float);
    void GetBonePosition(int, Vector &, Vector &);
    void GetAutomovement(Vector &, Vector &, float);
    int FindTransition(int, int, int *);
    void GetAttachment(int, Vector &, Vector &);
    void SetBodygroup(int, int);
    int GetBodygroup(int);
    int ExtractBbox(int, float *, float *);
    void SetSequenceBox(void);
};

class CBaseToggle : public CBaseAnimating {
  public:
    TOGGLE_STATE m_toggle_state;
    float m_flActivateFinished;
    float m_flMoveDistance;
    float m_flWait;
    float m_flLip;
    float m_flTWidth;
    float m_flTLength;
    Vector m_vecPosition1;
    Vector m_vecPosition2;
    Vector m_vecAngle1;
    Vector m_vecAngle2;
    int m_cTriggersLeft;
    float m_flHeight;
    EHANDLE m_hActivator;
    void (CBaseToggle::*m_pfnCallWhenMoveDone)(CBaseToggle * const);
    Vector m_vecFinalDest;
    Vector m_vecFinalAngle;
    int m_bitsDamageInflict;
    static TYPEDESCRIPTION m_SaveData[];
    string_t m_sMaster;

    virtual void KeyValue(KeyValueData_s *);
    virtual int Save(CSave &);
    virtual int Restore(CRestore &);
    virtual int GetToggleState(void);
    virtual float GetDelay(void);
    void LinearMove(Vector, float);
    void LinearMoveDone(void);
    void AngularMove(Vector, float);
    void AngularMoveDone(void);
    BOOL IsLockedByMaster(void);
    static float AxisValue(int, const Vector &);
    static void AxisDir(entvars_t *);
    static float AxisDelta(int, const Vector &, const Vector &);
};

class CBaseMonster : public CBaseToggle {
  public:
    Activity m_Activity;
    Activity m_IdealActivity;
    int m_LastHitGroup;
    int m_bitsDamageType;
    unsigned char m_rgbTimeBasedDamage[8];
    MONSTERSTATE m_MonsterState;
    MONSTERSTATE m_IdealMonsterState;
    int m_afConditions;
    int m_afMemory;
    float m_flNextAttack;
    EHANDLE m_hEnemy;
    EHANDLE m_hTargetEnt;
    float m_flFieldOfView;
    int m_bloodColor;
    Vector m_HackedGunPos;
    Vector m_vecEnemyLKP;

    virtual void KeyValue(KeyValueData *);
    void MakeIdealYaw(Vector);
    virtual float ChangeYaw(int);
    virtual BOOL HasHumanGibs(void);
    virtual BOOL HasAlienGibs(void);
    virtual void FadeMonster(void);
    virtual void GibMonster(void);
    virtual Activity GetDeathActivity(void);
    Activity GetSmallFlinchActivity(void);
    virtual void BecomeDead(void);
    BOOL ShouldGibMonster(int);
    void CallGibMonster(void);
    virtual BOOL ShouldFadeOnDeath(void);
    BOOL FCheckAITrigger(void);
    virtual int IRelationship(CBaseEntity *);
    virtual int TakeHealth(float, int);
    virtual int TakeDamage(entvars_t *, entvars_t *, float, int);
    int DeadTakeDamage(entvars_t *, entvars_t *, float, int);
    float DamageForce(float);
    virtual void Killed(entvars_t *, int);
    virtual void PainSound(void);
    virtual void ResetMaxSpeed(void);
    void RadiusDamage(entvars_t *, entvars_t *, float, int, int);
    void RadiusDamage(Vector, entvars_t *, entvars_t *, float, int, int);
    void RadiusDamage2(Vector, entvars_t *, entvars_t *, float, int, int);
    void SetConditions(int);
    void ClearConditions(int);
    BOOL HasConditions(int);
    BOOL HasAllConditions(int);
    void Remember(int);
    void Forget(int);
    BOOL HasMemory(int);
    BOOL HasAllMemories(int);
    void StopAnimation(void);
    virtual void ReportAIState(void);
    virtual void MonsterInitDead(void);
    void CorpseFallThink(void);
    virtual void Look(int);
    virtual CBaseEntity * BestVisibleEnemy(void);
    CBaseEntity * CheckTraceHullAttack(float, int, int);
    virtual BOOL FInViewCone(CBaseEntity *);
    virtual BOOL FInViewCone(Vector *);
    virtual void TraceAttack(entvars_t *, float, Vector, TraceResult *, int);
    void MakeDamageBloodDecal(int, float, TraceResult *, const Vector &);
    virtual BOOL IsAlive(void);
    virtual int BloodColor(void);
    void MonsterUse(CBaseEntity *, CBaseEntity *, USE_TYPE, float);
    void BloodSplat(Vector &, Vector &, int, int);
};

class CBasePlayerItem : public CBaseAnimating {
  public:
    static TYPEDESCRIPTION m_SaveData[];
    static ItemInfo ItemInfoArray[32];
    static AmmoInfo AmmoInfoArray[32];
    CBasePlayer *m_pPlayer;
    CBasePlayerItem *m_pNext;
    int m_iId;

    virtual void SetObjectCollisionBox(void);
    virtual int Save(CSave &);
    virtual int Restore(CRestore &);
    virtual int AddToPlayer(CBasePlayer *);
    virtual int AddDuplicate(CBasePlayerItem *);
    void DestroyItem(void);
    void DefaultTouch(CBaseEntity *);
    void FallThink(void);
    void Materialize(void);
    void AttemptToMaterialize(void);
    virtual CBaseEntity * Respawn(void);
    void FallInit(void);
    void CheckRespawn(void);
    virtual int GetItemInfo(ItemInfo *);
    virtual BOOL CanDeploy(void);
    virtual BOOL CanDrop(void);
    virtual BOOL Deploy(void);
    virtual BOOL IsWeapon(void);
    virtual BOOL CanHolster(void);
    virtual void Holster(int);
    virtual void UpdateItemInfo(void);
    virtual void ItemPreFrame(void);
    virtual void ItemPostFrame(void);
    virtual void Drop(void);
    virtual void Kill(void);
    virtual void AttachToPlayer(CBasePlayer *);
    virtual int PrimaryAmmoIndex(void);
    virtual int SecondaryAmmoIndex(void);
    virtual int UpdateClientData(CBasePlayer *);
    virtual CBasePlayerItem * GetWeaponPtr(void);
    virtual float GetMaxSpeed(void);
    virtual int iItemSlot(void);
    int iItemPosition(void);
    const char * pszAmmo1(void);
    int iMaxAmmo1(void);
    const char * pszAmmo2(void);
    int iMaxAmmo2(void);
    const char * pszName(void);
    int iMaxClip(void);
    int iWeight(void);
    int iFlags(void);
};

template <typename T>
class CUtlMemory {
  private:
    T **m_pMemory;
    int m_NumAllocated;
    int m_GrowSize;

  public:
    CUtlMemory(int, int);
    CUtlMemory(T **, int);
    ~CUtlMemory();
    T *& operator[](int);
    T * const& operator[](int) const;
    bool IsIdxValid(int) const;
    T ** Base(void);
    T * const * Base(void) const;
    int NumAllocated(void) const;
    void Grow(int);
    void EnsureCapacity(int);
    void Purge(void);
    bool IsExternallyAllocated(void) const;
    void SetGrowSize(int);
};

template <typename T>
class CUtlVector {
  private:
    CUtlMemory<T*> m_Memory;
    int m_Size;
    T **m_pElements;

  public:
    CUtlVector(int, int);
    CUtlVector(T **, int);
  protected:
    CUtlVector(const CUtlVector<T*> &);
  public:
    ~CUtlVector();
    T *& operator[](int);
    T * const& operator[](int) const;
    T *& Element(int);
    T * const& Element(int) const;
    T ** Base(void);
    T * const * Base(void) const;
    int Count(void) const;
    int Size(void) const;
    bool IsValidIndex(int) const;
    int AddToHead(void);
    int AddToHead(T * const&);
    int AddToTail(void);
    int AddToTail(T * const&);
    int InsertBefore(int);
    int InsertBefore(int, T * const&);
    int InsertAfter(int);
    int InsertAfter(int, T * const&);
    int AddMultipleToHead(int);
    int AddMultipleToTail(int);
    int InsertMultipleBefore(int, int);
    int InsertMultipleAfter(int, int);
    void SetSize(int);
    void CopyArray(T * const *, int);
    int AddVectorToTail(const CUtlVector<T*> &);
    int Find(T * const&);
    bool HasElement(T * const&);
    void EnsureCapacity(int);
    void FastRemove(int);
    void Remove(int);
    void FindAndRemove(T * const&);
    void RemoveMultiple(int, int);
    void RemoveAll(void);
    void Purge(void);
    void PurgeAndDeleteElements(void);
    void SetGrowSize(int);
  private:
    void GrowVector(int);
    void ShiftElementsRight(int, int);
    void ShiftElementsLeft(int, int);
    void ResetDbgInfo(void);
};

class CHintMessage {
  private:
    const char *m_hintString;
    bool m_isHint;
    CUtlVector<char*> m_args;
    float m_duration;

  public:
    CHintMessage(const char *, bool, CUtlVector<char const*> *, float);
    ~CHintMessage();
    float GetDuration(void) const;
    void Send(CBaseEntity &);
};

class CHintMessageQueue {
  private:
    float m_tmMessageEnd;
    CUtlVector<CHintMessage*> m_messages;

  public:
    void Reset(void);
    void Update(CBaseEntity &);
    bool AddMessage(const char *, float, bool, CUtlVector<char const*> *);
    bool IsEmpty(void);
};

class CUnifiedSignals {
  private:
    int m_flSignal;
    int m_flState;

  public:
    CUnifiedSignals(void);
    int Update(void);
    void Signal(int);
    int GetState(void);
};

struct RebuyStruct {
    int m_primaryWeapon;
    int m_primaryAmmo;
    int m_secondaryWeapon;
    int m_secondaryAmmo;
    int m_heGrenade;
    int m_flashbang;
    int m_smokeGrenade;
    int m_defuser;
    int m_nightVision;
    int m_armor;
};

struct AutoBuyInfoStruct {
    AutoBuyClassType m_class;
    char *m_command;
    char *m_classname;
};

class CBasePlayer : public CBaseMonster {
  public:
	enum MusicState {SILENT, CALM, INTENSE}; /* Warning */
    int random_seed;
    unsigned short m_usPlayerBleed;
    EHANDLE m_hObserverTarget;
    float m_flNextObserverInput;
    int m_iObserverWeapon;
    int m_iObserverC4State;
    bool m_bObserverHasDefuser;
    int m_iObserverLastMode;
    float m_flFlinchTime;
    float m_flAnimTime;
    bool m_bHighDamage;
    float m_flVelocityModifier;
    int m_iLastZoom;
    bool m_bResumeZoom;
    float m_flEjectBrass;
    int m_iKevlar;
    bool m_bNotKilled;
    TeamName m_iTeam;
    int m_iAccount;
    bool m_bHasPrimary;
    float m_flDeathThrowTime;
    int m_iThrowDirection;
    float m_flLastTalk;
    bool m_bJustConnected;
    bool m_bContextHelp;
    JoinState m_iJoiningState;
    CBaseEntity *m_pIntroCamera;
    float m_fIntroCamTime;
    float m_fLastMovement;
    bool m_bMissionBriefing;
    bool m_bTeamChanged;
    ModelName m_iModelName;
    int m_iTeamKills;
    int m_iIgnoreGlobalChat;
    bool m_bHasNightVision;
    bool m_bNightVisionOn;
    Vector m_vRecentPath[20];
    float m_flIdleCheckTime;
    float m_flRadioTime;
    int m_iRadioMessages;
    bool m_bIgnoreRadio;
    bool m_bHasC4;
    bool m_bHasDefuser;
    bool m_bKilledByBomb;
    Vector m_vBlastVector;
    bool m_bKilledByGrenade;
    CHintMessageQueue m_hintMessageQueue;
    int32 m_flDisplayHistory;
    _Menu m_iMenu;
    int m_iChaseTarget;
    CBaseEntity *m_pChaseTarget;
    float m_fCamSwitch;
    bool m_bEscaped;
    bool m_bIsVIP;
    float m_tmNextRadarUpdate;
    Vector m_vLastOrigin;
    int m_iCurrentKickVote;
    float m_flNextVoteTime;
    bool m_bJustKilledTeammate;
    int m_iHostagesKilled;
    int m_iMapVote;
    bool m_bCanShoot;
    float m_flLastFired;
    float m_flLastAttackedTeammate;
    bool m_bHeadshotKilled;
    bool m_bPunishedForTK;
    bool m_bReceivesNoMoneyNextRound;
    int m_iTimeCheckAllowed;
    bool m_bHasChangedName;
    char m_szNewName[32];
    bool m_bIsDefusing;
    float m_tmHandleSignals;
    CUnifiedSignals m_signals;
    edict_t *m_pentCurBombTarget;
    int m_iPlayerSound;
    int m_iTargetVolume;
    int m_iWeaponVolume;
    int m_iExtraSoundTypes;
    int m_iWeaponFlash;
    float m_flStopExtraSoundTime;
    float m_flFlashLightTime;
    int m_iFlashBattery;
    int m_afButtonLast;
    int m_afButtonPressed;
    int m_afButtonReleased;
    edict_t *m_pentSndLast;
    float m_flSndRoomtype;
    float m_flSndRange;
    float m_flFallVelocity;
    int m_rgItems[4];
    int m_fNewAmmo;
    unsigned int m_afPhysicsFlags;
    float m_fNextSuicideTime;
    float m_flTimeStepSound;
    float m_flTimeWeaponIdle;
    float m_flSwimTime;
    float m_flDuckTime;
    float m_flWallJumpTime;
    float m_flSuitUpdate;
    int m_rgSuitPlayList[4];
    int m_iSuitPlayNext;
    int m_rgiSuitNoRepeat[32];
    float m_rgflSuitNoRepeatTime[32];
    int m_lastDamageAmount;
    float m_tbdPrev;
    float m_flgeigerRange;
    float m_flgeigerDelay;
    int m_igeigerRangePrev;
    int m_iStepLeft;
    char m_szTextureName[17];
    char m_chTextureType;
    int m_idrowndmg;
    int m_idrownrestored;
    int m_bitsHUDDamage;
    BOOL m_fInitHUD;
    BOOL m_fGameHUDInitialized;
    int m_iTrain;
    BOOL m_fWeapon;
    EHANDLE m_pTank;
    float m_fDeadTime;
    BOOL m_fNoPlayerSound;
    BOOL m_fLongJump;
    float m_tSneaking;
    int m_iUpdateTime;
    int m_iClientHealth;
    int m_iClientBattery;
    int m_iHideHUD;
    int m_iClientHideHUD;
    int m_iFOV;
    int m_iClientFOV;
    int m_iNumSpawns;
    CBaseEntity *m_pObserver;
    CBasePlayerItem *m_rgpPlayerItems[6];
    CBasePlayerItem *m_pActiveItem;
    CBasePlayerItem *m_pClientActiveItem;
    CBasePlayerItem *m_pLastItem;
    int m_rgAmmo[32];
    int m_rgAmmoLast[32];
    Vector m_vecAutoAim;
    BOOL m_fOnTarget;
    int m_iDeaths;
    int m_izSBarState[4];
    float m_flNextSBarUpdateTime;
    float m_flStatusBarDisappearDelay;
    char m_SbarString0[128];
    int m_lastx;
    int m_lasty;
    int m_nCustomSprayFrames;
    float m_flNextDecalTime;
    char m_szTeamName[16];
  protected:
    int m_modelIndexPlayer;
  public:
    static TYPEDESCRIPTION m_playerSaveData[];
    char m_szAnimExtention[32];
    int m_iGaitsequence;
    float m_flGaitframe;
    float m_flGaityaw;
    Vector m_prevgaitorigin;
    float m_flPitch;
    float m_flYaw;
    float m_flGaitMovement;
    int m_iAutoWepSwitch;
    bool m_bVGUIMenus;
    bool m_bShowHints;
    bool m_bShieldDrawn;
    bool m_bOwnsShield;
    bool m_bWasFollowing;
    float m_flNextFollowTime;
    float m_flYawModifier;
    float m_blindUntilTime;
    float m_blindStartTime;
    float m_blindHoldTime;
    float m_blindFadeTime;
    int m_blindAlpha;
    float m_allowAutoFollowTime;
    char m_autoBuyString[256];
    char *m_rebuyString;
    RebuyStruct m_rebuyStruct;
    bool m_bIsInRebuy;
  protected:
    float m_flLastUpdateTime;
    char m_lastLocation[32];
  public:
    float m_progressStart;
    float m_progressEnd;
  protected:
    bool m_bObserverAutoDirector;
  public:
    bool m_canSwitchObserverModes;
    float m_heartBeatTime;
    float m_intenseTimestamp;
    float m_silentTimestamp;
    CBasePlayer::MusicState m_musicState;
    float m_flLastCommandTime[8];
    int m_iLastAccount;
    int m_iLastClientHealth;
    float m_tmNextAccountHealthUpdate;

    void SpawnClientSideCorpse(void);
    void Observer_FindNextPlayer(bool, const char *);
    CBaseEntity * Observer_IsValidTarget(int, bool);
    void Observer_HandleButtons(void);
    void Observer_SetMode(int);
    void Observer_CheckTarget(void);
    void Observer_CheckProperties(void);
    int IsObserver(void);
    void PlantC4(void);
    void Radio(const char *, const char *, short, bool);
    CBasePlayer * GetNextRadioRecipient(CBasePlayer *);
    void SmartRadio(void);
    void ThrowWeapon(char *);
    void ThrowPrimary(void);
    void AddAccount(int, bool);
    void Disappear(void);
    void MakeVIP(void);
    bool CanPlayerBuy(bool);
    void SwitchTeam(void);
    void TabulateAmmo(void);
    virtual void Spawn(void);
    void Pain(int, bool);
    virtual void Jump(void);
    virtual void Duck(void);
    virtual void PreThink(void);
    virtual void PostThink(void);
    virtual Vector GetGunPosition(void);
    virtual int TakeHealth(float, int);
    virtual void TraceAttack(entvars_t *, float, Vector, TraceResult *, int);
    virtual int TakeDamage(entvars_t *, entvars_t *, float, int);
    virtual void Killed(entvars_t *, int);
    virtual Vector BodyTarget(const Vector &);
    virtual void StartSneaking(void);
    virtual void StopSneaking(void);
    virtual BOOL IsSneaking(void);
    virtual BOOL IsAlive(void);
    virtual BOOL ShouldFadeOnDeath(void);
    virtual BOOL IsPlayer(void);
    virtual BOOL IsBot(void);
    BOOL IsBombGuy(void);
    bool IsLookingAtPosition(const Vector *, float) const;
    virtual BOOL IsNetClient(void);
    virtual const char * TeamID(void);
    virtual int Save(CSave &);
    virtual int Restore(CRestore &);
    void Reset(void);
    void SetScoreboardAttributes(CBasePlayer *);
    void RenewItems(void);
    void PackDeadPlayerItems(void);
    void GiveDefaultItems(void);
    void RemoveAllItems(BOOL);
    void SetBombIcon(BOOL);
    void SetProgressBarTime(int);
    void SetProgressBarTime2(int, float);
    void SetPlayerModel(BOOL);
    void SetNewPlayerModel(const char *);
    BOOL SwitchWeapon(CBasePlayerItem *);
  protected:
    void CheckPowerups(entvars_t *);
  public:
    bool CanAffordPrimary(void);
    bool CanAffordPrimaryAmmo(void);
    bool CanAffordSecondaryAmmo(void);
    bool CanAffordArmor(void);
    bool CanAffordDefuseKit(void);
    bool CanAffordGrenade(void);
    bool NeedsPrimaryAmmo(void);
    bool NeedsSecondaryAmmo(void);
    bool NeedsArmor(void);
    bool NeedsDefuseKit(void);
    bool NeedsGrenade(void);
    virtual void UpdateClientData(void);
    virtual int ObjectCaps(void);
    virtual void Precache(void);
    BOOL IsOnLadder(void);
    BOOL FlashlightIsOn(void);
    void FlashlightTurnOn(void);
    void FlashlightTurnOff(void);
    void UpdatePlayerSound(void);
    void DeathSound(void);
    virtual int Classify(void);
    void SetAnimation(PLAYER_ANIM);
    void SetWeaponAnimType(const char *);
    virtual void ImpulseCommands(void);
    void CheatImpulseCommands(int);
    virtual void RoundRespawn(void);
    void StartDeathCam(void);
    void StartObserver(Vector, Vector);
    virtual void AddPoints(int, BOOL);
    virtual void AddPointsToTeam(int, BOOL);
    void HandleSignals(void);
    virtual BOOL AddPlayerItem(CBasePlayerItem *);
    virtual BOOL RemovePlayerItem(CBasePlayerItem *);
    void DropPlayerItem(const char *);
    BOOL HasPlayerItem(CBasePlayerItem *);
    BOOL HasNamedPlayerItem(const char *);
    BOOL HasWeapons(void);
    void SelectPrevItem(int);
    void SelectNextItem(int);
    void SelectLastItem(void);
    void SelectItem(const char *);
    void ItemPreFrame(void);
    void ItemPostFrame(void);
    void GiveNamedItem(const char *);
    void EnableControl(BOOL);
    virtual void ResetMaxSpeed(void);
    bool HintMessage(const char *, BOOL, BOOL);
    virtual int GiveAmmo(int, char *, int);
    void SendAmmoUpdate(void);
    void SendFOV(int);
    void WaterMove(void);
    void PlayerDeathThink(void);
    void PlayerUse(void);
    void HostageUsed(void);
    void JoiningThink(void);
    void RemoveLevelText(void);
    void MenuPrint(CBasePlayer *, const char *);
    void ResetMenu(void);
    void SyncRoundTimer(void);
    void CheckSuitUpdate(void);
    void SetSuitUpdate(char *, int, int);
    void UpdateGeigerCounter(void);
    void CheckTimeBasedDamage(void);
    virtual BOOL FBecomeProne(void);
    void BarnacleVictimBitten(entvars_t *);
    void BarnacleVictimReleased(void);
    static int GetAmmoIndex(const char *);
    int AmmoInventory(int);
    virtual int Illumination(void);
    void ResetAutoaim(void);
    virtual Vector GetAutoaimVector(float);
    Vector AutoaimDeflection(Vector &, float, float);
    void ForceClientDllUpdate(void);
    void DeathMessage(entvars_t *);
    void SetCustomDecalFrames(int);
    int GetCustomDecalFrames(void);
    void InitStatusBar(void);
    void UpdateStatusBar(void);
    void StudioEstimateGait(void);
    void StudioPlayerBlend(int *, float *);
    void CalculatePitchBlend(void);
    void CalculateYawBlend(void);
    void StudioProcessGait(void);
    void SendHostagePos(void);
    void SendHostageIcons(void);
    void ResetStamina(void);
    BOOL IsArmored(int);
    BOOL ShouldDoLargeFlinch(int, int);
    void SetPrefsFromUserinfo(char *);
    void SendWeatherInfo(void);
    void UpdateShieldCrosshair(bool);
    bool HasShield(void);
    bool IsProtectedByShield(void);
    void RemoveShield(void);
    void DropShield(bool);
    void GiveShield(bool);
    bool IsHittingShield(const Vector &, TraceResult *);
    bool IsReloading(void);
    bool IsBlind(void) const;
    virtual void Blind(float, float, float, int);
    virtual void OnTouchingWeapon(CWeaponBox *);
    bool IsAutoFollowAllowed(void) const;
    void InhibitAutoFollow(float);
    void AllowAutoFollow(void);
    void ClearAutoBuyData(void);
    void AddAutoBuyData(const char *);
    void AutoBuy(void);
  protected:
    void ClientCommand(const char *, const char *, const char *, const char *);
    void PrioritizeAutoBuyString(char *, const char *);
  public:
    const char * PickPrimaryCareerTaskWeapon(void);
    const char * PickSecondaryCareerTaskWeapon(void);
    const char * PickFlashKillWeaponString(void);
    const char * PickGrenadeKillWeaponString(void);
    bool ShouldExecuteAutoBuyCommand(const AutoBuyInfoStruct *, bool, bool);
    void PostAutoBuyCommandProcessing(const AutoBuyInfoStruct *, bool &, bool &);
    void ParseAutoBuyString(const char *, bool &, bool &);
    AutoBuyInfoStruct * GetAutoBuyCommandInfo(const char *);
    void InitRebuyData(const char *);
    void BuildRebuyStruct(void);
    void Rebuy(void);
    void RebuyPrimaryWeapon(void);
    void RebuyPrimaryAmmo(void);
    void RebuySecondaryWeapon(void);
    void RebuySecondaryAmmo(void);
    void RebuyHEGrenade(void);
    void RebuyFlashbang(void);
    void RebuySmokeGrenade(void);
    void RebuyDefuser(void);
    void RebuyNightVision(void);
    void RebuyArmor(void);
    void UpdateLocation(bool);
    void SetObserverAutoDirector(bool);
    bool IsObservingPlayer(CBasePlayer *);
    bool CanSwitchObserverModes(void) const;
    void Intense(void);
};

class IGame {
  public:
    ~IGame();
    virtual bool Init(void *);
    virtual bool Shutdown(void);
    virtual bool CreateGameWindow(void);
    virtual void SleepUntilInput(int);
    virtual HWND GetMainWindow(void);
    virtual HWND * GetMainWindowAddress(void);
    virtual void SetWindowXY(int, int);
    virtual void SetWindowSize(int, int);
    virtual void GetWindowRect(int *, int *, int *, int *);
    virtual bool IsActiveApp(void);
    virtual bool IsMultiplayer(void);
    virtual void PlayStartupVideos(void);
    virtual void PlayAVIAndWait(const char *);
    virtual void SetCursorVisible(bool);
};

class CGame : public IGame {
  private:
    bool m_bActiveApp;
    SDL_Window *m_hSDLWindow;
    SDL_GLContext m_hSDLGLContext;
    bool m_bExpectSyntheticMouseMotion;
    int m_nMouseTargetX;
    int m_nMouseTargetY;
    int m_nWarpDelta;
    bool m_bCursorVisible;
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    bool m_bMultiplayer;

  public:
    CGame(void);
    ~CGame();
    virtual bool Init(void *);
    virtual bool Shutdown(void);
    virtual bool CreateGameWindow(void);
    virtual void SleepUntilInput(int);
    virtual HWND GetMainWindow(void);
    virtual HWND * GetMainWindowAddress(void);
    virtual void SetWindowXY(int, int);
    virtual void SetWindowSize(int, int);
    virtual void GetWindowRect(int *, int *, int *, int *);
    virtual bool IsActiveApp(void);
    virtual bool IsMultiplayer(void);
    virtual void PlayStartupVideos(void);
    virtual void PlayAVIAndWait(const char *);
    void AppActivate(bool);
    virtual void SetCursorVisible(bool);
  private:
    void SetActiveApp(bool);
};

struct color24 {
    byte r;
    byte g;
    byte b;
};

struct entity_state_s {
    int entityType;
    int number;
    float msg_time;
    int messagenum;
    vec3_t origin;
    vec3_t angles;
    int modelindex;
    int sequence;
    float frame;
    int colormap;
    short skin;
    short solid;
    int effects;
    float scale;
    byte eflags;
    int rendermode;
    int renderamt;
    color24 rendercolor;
    int renderfx;
    int movetype;
    float animtime;
    float framerate;
    int body;
    byte controller[4];
    byte blending[4];
    vec3_t velocity;
    vec3_t mins;
    vec3_t maxs;
    int aiment;
    int owner;
    float friction;
    float gravity;
    int team;
    int playerclass;
    int health;
    qboolean spectator;
    int weaponmodel;
    int gaitsequence;
    vec3_t basevelocity;
    int usehull;
    int oldbuttons;
    int onground;
    int iStepLeft;
    float flFallVelocity;
    float fov;
    int weaponanim;
    vec3_t startpos;
    vec3_t endpos;
    float impacttime;
    float starttime;
    int iuser1;
    int iuser2;
    int iuser3;
    int iuser4;
    float fuser1;
    float fuser2;
    float fuser3;
    float fuser4;
    vec3_t vuser1;
    vec3_t vuser2;
    vec3_t vuser3;
    vec3_t vuser4;
};

struct entity_state_t : public entity_state_s {};

struct position_history_t {
    float animtime;
    vec3_t origin;
    vec3_t angles;
};

struct mouth_t {
    byte mouthopen;
    byte sndcount;
    int sndavg;
};

struct latchedvars_t {
    float prevanimtime;
    float sequencetime;
    unsigned char prevseqblending[2];
    vec3_t prevorigin;
    vec3_t prevangles;
    int prevsequence;
    float prevframe;
    unsigned char prevcontroller[4];
    unsigned char prevblending[2];
};

struct dmodel_t {
    float mins[3];
    float maxs[3];
    float origin[3];
    int headnode[4];
    int visleafs;
    int firstface;
    int numfaces;
};

struct mplane_s {
    vec3_t normal;
    float dist;
    byte type;
    byte signbits;
    byte pad[2];
};

struct mplane_t : public mplane_s {};

struct mnode_s {
    int contents;
    int visframe;
    float minmaxs[6];
    mnode_s *parent;
    mplane_t *plane;
    mnode_s *children[2];
    unsigned short firstsurface;
    unsigned short numsurfaces;
};

struct efrag_s {
    mleaf_s *leaf;
    efrag_s *leafnext;
    cl_entity_s *entity;
    efrag_s *entnext;
};

struct glpoly_s {
    glpoly_s *next;
    glpoly_s *chain;
    int numverts;
    int flags;
    float verts[4][7];
};

struct glpoly_t : public glpoly_s {};

struct texture_s {
    char name[16];
    unsigned int width;
    unsigned int height;
    int gl_texturenum;
    msurface_s *texturechain;
    int anim_total;
    int anim_min;
    int anim_max;
    texture_s *anim_next;
    texture_s *alternate_anims;
    unsigned int offsets[4];
    byte *pPal;
};

struct texture_t : public texture_s {};

struct mtexinfo_t {
    float vecs[2][4];
    float mipadjust;
    texture_t *texture;
    int flags;
};

struct decal_s {
    decal_s *pnext;
    msurface_s *psurface;
    float dx;
    float dy;
    float scale;
    short texture;
    short flags;
    short entityIndex;
};

struct decal_t : public decal_s {};

struct msurface_s {
    int visframe;
    mplane_t *plane;
    int flags;
    int firstedge;
    int numedges;
    short texturemins[2];
    short extents[2];
    int light_s;
    int light_t;
    glpoly_t *polys;
    msurface_s *texturechain;
    mtexinfo_t *texinfo;
    int dlightframe;
    int dlightbits;
    int lightmaptexturenum;
    byte styles[4];
    int cached_light[4];
    qboolean cached_dlight;
    color24 *samples;
    decal_t *pdecals;
};

struct msurface_t : public msurface_s {};

struct mleaf_s {
    int contents;
    int visframe;
    float minmaxs[6];
    mnode_s *parent;
    byte *compressed_vis;
    efrag_s *efrags;
    msurface_t **firstmarksurface;
    int nummarksurfaces;
    int key;
    byte ambient_sound_level[4];
};

struct mleaf_t : public mleaf_s {};

struct mvertex_t {
    vec3_t position;
};

struct medge_t {
    unsigned short v[2];
    unsigned int cachededgeoffset;
};

struct mnode_t : public mnode_s {};

struct dclipnode_t {
    int planenum;
    short children[2];
};

struct hull_s {
    dclipnode_t *clipnodes;
    mplane_t *planes;
    int firstclipnode;
    int lastclipnode;
    vec3_t clip_mins;
    vec3_t clip_maxs;
};

struct cache_user_s {
    void *data;
};

struct cache_user_t : public cache_user_s {};

struct model_s {
    char name[64];
    qboolean needload;
    modtype_t type;
    int numframes;
    synctype_t synctype;
    int flags;
    vec3_t mins;
    vec3_t maxs;
    float radius;
    int firstmodelsurface;
    int nummodelsurfaces;
    int numsubmodels;
    dmodel_t *submodels;
    int numplanes;
    mplane_t *planes;
    int numleafs;
    mleaf_t *leafs;
    int numvertexes;
    mvertex_t *vertexes;
    int numedges;
    medge_t *edges;
    int numnodes;
    mnode_t *nodes;
    int numtexinfo;
    mtexinfo_t *texinfo;
    int numsurfaces;
    msurface_t *surfaces;
    int numsurfedges;
    int *surfedges;
    int numclipnodes;
    dclipnode_t *clipnodes;
    int nummarksurfaces;
    msurface_t **marksurfaces;
    hull_s hulls[4];
    int numtextures;
    texture_t **textures;
    byte *visdata;
    color24 *lightdata;
    char *entities;
    cache_user_t cache;
};

struct colorVec {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
};

struct cl_entity_s {
    int index;
    qboolean player;
    entity_state_t baseline;
    entity_state_t prevstate;
    entity_state_t curstate;
    int current_position;
    position_history_t ph[64];
    mouth_t mouth;
    latchedvars_t latched;
    float lastmove;
    vec3_t origin;
    vec3_t angles;
    vec_t attachment[4][3];
    int trivial_accept;
    model_s *model;
    efrag_s *efrag;
    mnode_s *topnode;
    float syncbase;
    int visframe;
    colorVec cvFloorColor;
};

#endif
