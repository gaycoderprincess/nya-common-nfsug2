enum eTrackDirection {
	eDIRECTION_FORWARD = 0,
	eDIRECTION_BACKWARD = 1,
	NUM_TRACK_DIRECTIONS = 2,
};

enum eTrafficDensity {
	eTRAFFICDENSITY_OFF = 0,
	eTRAFFICDENSITY_LOW = 1,
	eTRAFFICDENSITY_MEDIUM = 2,
	eTRAFFICDENSITY_HIGH = 3,
	NUM_TRAFFIC_DENSITIES = 4,
};

enum RaceTypes {
	RACE_TYPE_NONE = 0,
	RACE_TYPE_SINGLE_RACE = 1,
	RACE_TYPE_TIME_TRIAL = 2,
	RACE_TYPE_LAP_KNOCKOUT = 3,
	RACE_TYPE_RACE_KNOCKOUT = 4,
	RACE_TYPE_TOURNAMENT = 5,
	RACE_TYPE_CAR_SHOW = 6,
	RACE_TYPE_GET_AWAY = 7,
};

enum eHandlingMode {
	HANDLING_MODE_CLASSIC = 0,
	HANDLING_MODE_EXTREME = 1,
};

enum eOpponentStrength {
	eOPPONENTSTRENGTH_LOW = 0,
	eOPPONENTSTRENGTH_MEDIUM = 1,
	eOPPONENTSTRENGTH_HIGH = 2,
	NUM_OPPONENT_STRENGTHS = 3,
};

enum eAIDifficultyModifier {
	eAI_DIFFICULTY_MODIFIER_EASY = 0,
	eAI_DIFFICULTY_MODIFIER_SOMEWHAT_EASY = 1,
	eAI_DIFFICULTY_MODIFIER_NORMAL = 2,
	NUM_AI_DIFFICULTY_MODIFIERS = 3,
};

class Timer {
public:
	int PackedTime;
};

enum DriverTypeEnum {
	DRIVER_TYPE_NONE,
	DRIVER_TYPE_PLAYER,
	DRIVER_TYPE_AI_RACER,
	DRIVER_TYPE_TRAFFIC_CAR,
	DRIVER_TYPE_COP,
	DRIVER_TYPE_SUPER_COP,
	DRIVER_TYPE_DUNNO,
};

class DriverInfo {
public:
	uint8_t _0[0x4];
	DriverTypeEnum nDriverType; // +4
	uint8_t _8[0x904];
	char sPlayerName[16]; // +90C
	uint8_t _91C[0x24];
};
static_assert(sizeof(DriverInfo) == 0x940);

class RaceParameters {
public:
	int TrackNumber; // +0
	eTrackDirection TrackDirection; // +4
	eTrafficDensity TrafficDensity; // +8
	bool AIDemoMode; // +C
	bool ReplayDemoMode; // +D
	RaceTypes RaceType; // +10
	int Point2Point; // +14
	float RollingStartSpeed; // +18
	int NumLapsInRace; // +1C
	int NumPlayerCars; // +20
	int NumAICars; // +24
	int NumOnlinePlayerCars; // +28
	int NumOnlineAICars; // +2C
	signed char PlayerStartPosition[2]; // +30
	bool DamageEnabled; // +32
	int FinishLineNumber; // +34
	bool bDragRaceFlag; // +38
	bool bDriftRaceFlag; // +39
	float _3C;
	bool _40;
	bool bURLRaceFlag; // +41
	bool bBurnoutFlag; // +42
	bool bShortRaceFlag; // +43
	bool bOnlineRace; // +44
	bool bCarShowFlag; // +45
	bool bCarTuningFlag; // +46
	bool _47;
	int PlayerJoyports[2]; // +48
	float DriftOpponentScoreMultiplier; // +50
	eOpponentStrength OpponentStrength; // +54
	int Boost; // +58
	float BoostScale[2]; // +5C
	eAIDifficultyModifier AIDifficultyModifier; // +64
	int PlayerDriverNumber[2]; // +68
	DriverInfo* DriverInfos; // +70
	int NumDriverInfo; // +74
	Timer TimeTrialTime; // +78
	uint8_t _7C[0x4];

	static inline auto InitWithDefaults = (void(*)())0x5ED5F0;
};
static_assert(sizeof(RaceParameters) == 0x80);
static_assert(offsetof(RaceParameters, NumLapsInRace) == (0x89E7BC - 0x89E7A0));
static_assert(offsetof(RaceParameters, PlayerStartPosition) == (0x89E7D0 - 0x89E7A0));
static_assert(offsetof(RaceParameters, DamageEnabled) == (0x89E7D2 - 0x89E7A0));
static_assert(offsetof(RaceParameters, bDragRaceFlag) == (0x89E7D8 - 0x89E7A0));
static_assert(offsetof(RaceParameters, bURLRaceFlag) == (0x89E7E1 - 0x89E7A0));
static_assert(offsetof(RaceParameters, bShortRaceFlag) == (0x89E7E3 - 0x89E7A0));
static_assert(offsetof(RaceParameters, PlayerJoyports[0]) == (0x89E7E8 - 0x89E7A0));
static_assert(offsetof(RaceParameters, Boost) == (0x89E7F8 - 0x89E7A0));
static_assert(offsetof(RaceParameters, BoostScale[0]) == (0x89E7FC - 0x89E7A0));
static_assert(offsetof(RaceParameters, PlayerDriverNumber[0]) == (0x89E808 - 0x89E7A0));
static_assert(offsetof(RaceParameters, TimeTrialTime) == (0x89E818 - 0x89E7A0));

auto& TheRaceParameters = *(RaceParameters*)0x89E7A0;