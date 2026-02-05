enum MovementMode {
	NO_MOVEMENT,
	PHYSICS_MOVEMENT,
	TRAFFIC_MOVEMENT,
	MELLOW_MOVEMENT,
	BELT_MOVEMENT,
	NIS_MOVEMENT,
};

enum ControlMode {
	NO_CONTROLLER,
	REAL_CONTROLLER,
	DRAG_CONTROLLER,
	RACECAR_CONTROLLER,
	TRAFFIC_CONTROLLER,
	ONLINE_CONTROLLER,
};

class RigidBodyState {
public:
	bVector3 vPosition; // +0
	bMatrix4 mMatrix; // +10
	bVector3 vVelocity; // +50
	bVector3 vAngularVelocity; // +60
	float _70;
};
static_assert(sizeof(RigidBodyState) == 0x74);
static_assert(offsetof(RigidBodyState, vPosition) == 0);

class RigidBodyInfo;
class RigidBody {
public:
	uint8_t _4[0x8];
	char sName[8]; // +C
	RigidBodyInfo* pInfo; // +14
	uint8_t _18[0x8];
	RigidBodyState State; // +20

	virtual void _vf0();
};
static_assert(offsetof(RigidBody, State) == 0x20);
//static_assert(offsetof(RigidBody, fGravity) == 0x160);

class ReplaySnapshot;
class CarMover {
public:
	uint8_t _4[0x8];
	char sName[8]; // +C

	virtual void _vf0();
	virtual void Move(float);
	virtual void DoSnapshot(ReplaySnapshot*);
	virtual RigidBody* GetRigidBody();
	virtual bool RequiresTopology();
	virtual void* GetDampState();
	virtual bVector3* GetLastAccumulatedForce();
	virtual bVector3* GetLastAccumulatedTorque();
};
static_assert(offsetof(CarMover, sName) == 0xC);

class CarDriver {
public:
	uint8_t _0[0x1E0];
	int16_t nSteering; // +1E0
	uint8_t _1E2[0x2A];
	float fThrottle; // +20C
	float fEBrake; // +210
	float fBrake; // +214
	uint8_t _218[0x8];
};
static_assert(sizeof(CarDriver) == 0x220);
static_assert(offsetof(CarDriver, nSteering) == 0x1E0);
static_assert(offsetof(CarDriver, fThrottle) == 0x20C);
static_assert(offsetof(CarDriver, fEBrake) == 0x210);
static_assert(offsetof(CarDriver, fBrake) == 0x214);

typedef int eGPSState;
class Car;
class TrackRoutePoint;
class Signpost;
class PathfindingNode;
class CarController {
public:
	Car* pCar; // +4
	CarDriver* pDriver; // +8

	virtual void _vf0();
	virtual void DebugDisplay();
	virtual void DoSnapshot(ReplaySnapshot*);
	virtual void Think(float);
	virtual void TopologyLoadedHasChanged(bool);
	virtual void RaceStageHasChanged(int, int);
	virtual void SetCurrentRoutePoint(TrackRoutePoint*);
	virtual int GetCurrentDrivingLineNumber();
	virtual void SetCurrentDrivingLineNumber(int);
	virtual void* GetFuturePoints();
	virtual void KeepFuturePointsBehindMe();
	virtual float GetAmountOutOfBounds();
	virtual void FindWhereIAm(bool);
	virtual void JustReset();
	virtual void SetToPhysicsMode(Car*, bool);
	virtual void ForceBoost(float);
	virtual void ReleaseBoost();
	virtual bool MustTakeSignpost(Signpost*);
	virtual bool JustCrossedSignpost(Signpost*);
	virtual void SetGPSState(eGPSState, PathfindingNode*);
	virtual bool WantToBeInRealPhysics();
	virtual bool WantToTakeSignpost(Signpost*);
	virtual void DealWithTakingFutureSignpost(Signpost*);
	virtual bool WantToCacheSignpostDecision(Signpost*);
	virtual float GetLookaheadTime();
	virtual bool GetSignpostDecisionFromPathfinding(Signpost*, bool);
};

class CarState {
public:
	uint8_t _0[0x420];
	float fNitrous; // +420
	uint8_t _424[0x6C];

	static inline auto IsNitrousAvailable = (bool(__thiscall*)(CarState*))0x59FAA0;
	static inline auto StartNitrous = (void(__thiscall*)(CarState*))0x59FAF0;
	static inline auto StopNitrous = (void(__thiscall*)(CarState*))0x592500;
	static inline auto IsNitrousOn = (int(__thiscall*)(CarState*))0x59FA30;
};
static_assert(sizeof(CarState) == 0x490);
static_assert(offsetof(CarState, fNitrous) == 0x420);

class Car : public bNode<Car> {
public:
	uint8_t _8[0x4];
	const char* sCarTypeName; // +C
	RideInfo* pRideInfo; // +10
	DriverInfo* pDriverInfo; // +14
	uint8_t _18[0xC];
	ControlMode nControlMode; // +24
	MovementMode nMovementMode; // +28
	CarController* pController; // +2C
	uint8_t _30[0x4];
	CarMover* pMover; // +34
	uint8_t _38[0x8];
	CarState State; // +40
	uint8_t _4D0[0x494];
	bool bIsTotaled; // +964
	uint8_t _965[0xF];
	uint32_t nResetStartTime; // +974
	float fResetDuration; // +978

	static inline auto ResetToPosition = (void(__thiscall*)(Car*, bVector3*, float, uint16_t, bool))0x5FBD60;
	static inline auto CheckForLoadedTopology = (void(__thiscall*)(Car*))0x5F6CD0;
	static inline auto PutFlatOnTrack = (void(__thiscall*)(Car*))0x5F5010;
	static inline auto StartBlinking = (void(__thiscall*)(Car*, float))0x5EBF70;
	static inline auto IsBlinking = (bool(__thiscall*)(Car*))0x5EBFA0;
	static inline auto IsBlinkingInView = (bool(__thiscall*)(Car*))0x5EBFF0;
	static inline auto SetMovementMode = (void(__thiscall*)(Car*, MovementMode))0x5F46A0;
	static inline auto SetControlMode = (void(__thiscall*)(Car*, ControlMode))0x5EBA30;
	static inline auto IsEngineBlown = (bool(__thiscall*)(Car*))0x5ECE00;

	// inlined
	void StopBlinking() {
		nResetStartTime = 0;
	}
};
static_assert(offsetof(Car, pDriverInfo) == 0x14);
static_assert(offsetof(Car, nMovementMode) == 0x28);
static_assert(offsetof(Car, pController) == 0x2C);
static_assert(offsetof(Car, pMover) == 0x34);
static_assert(offsetof(Car, State) == 0x40);
static_assert(offsetof(Car, bIsTotaled) == 0x964);
static_assert(offsetof(Car, nResetStartTime) == 0x974);

auto& PlayerCarType = *(int*)0x8021B0;

auto GetCarByDriverNumber = (Car*(*)(int))0x5F0ED0;

class World {
public:
	bTList<Car> CarTable; // +0

	static inline auto IsWorldPaused = (bool(__thiscall*)(World*))0x5EA320;
};
auto& pCurrentWorld = *(World**)0x890080;