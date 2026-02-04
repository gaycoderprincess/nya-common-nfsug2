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

class Car {
public:
	Car* pNext; // +0
	uint8_t _4[0x8];
	const char* sCarTypeName; // +C
	RideInfo* pRideInfo; // +10
	DriverInfo* pDriverInfo; // +14
	uint8_t _18[0x10];
	MovementMode nMovementMode; // +28
	ControlMode nControlMode; // +2C
	uint8_t _30[0x4];
	CarMover* pMover; // +34
	uint8_t _38[0x93C];
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

	// inlined
	void StopBlinking() {
		nResetStartTime = 0;
	}
};
static_assert(offsetof(Car, pDriverInfo) == 0x14);
static_assert(offsetof(Car, nMovementMode) == 0x28);
static_assert(offsetof(Car, nResetStartTime) == 0x974);

auto& PlayerCarType = *(int*)0x8021B0;

auto GetCarByDriverNumber = (Car*(*)(int))0x5F0ED0;

class World {
public:
	Car* pCarTable; // +0
	int nNumCars; // +4

	static inline auto IsWorldPaused = (bool(__thiscall*)(World*))0x5EA320;
};
auto& pCurrentWorld = *(World**)0x890080;