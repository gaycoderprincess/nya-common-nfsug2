enum GameFlowState {
	GAMEFLOW_STATE_NONE = 0,
	GAMEFLOW_STATE_LOADING_FRONTEND = 1,
	GAMEFLOW_STATE_UNLOADING_FRONTEND = 2,
	GAMEFLOW_STATE_IN_FRONTEND = 3,
	GAMEFLOW_STATE_LOADING_REGION = 4,
	GAMEFLOW_STATE_LOADING_TRACK = 5,
	GAMEFLOW_STATE_RACING = 6,
	GAMEFLOW_STATE_UNLOADING_TRACK = 7,
	GAMEFLOW_STATE_UNLOADING_REGION = 8,
	GAMEFLOW_STATE_EXIT_DEMO_DISC = 9,
};

class GameFlowManager {
public:
	void(*pSingleFunction)(int);
	int SingleFunctionParam;
	const char* pSingleFunctionName;
	void(*pLoopingFunction)();
	const char* pLoopingFunctionName;
	bool WaitingForCallback;
	const char* pCallbackName;
	int CallbackPhase;
	GameFlowState CurrentGameFlowState;

	static inline auto UnloadFrontend = (void(__thiscall*)(GameFlowManager*))0x578320;
	static inline auto LoadTrack = (void(__thiscall*)(GameFlowManager*))0x581020;
};
auto& TheGameFlowManager = *(GameFlowManager*)0x865480;