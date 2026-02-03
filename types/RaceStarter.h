class RaceStarter {
public:
	static inline auto SetupSprint = (void(*)())0x53F150;
	static inline auto SetupDragRace = (void(*)())0x53F690;
	static inline auto SetupDriftRace = (void(*)())0x53F830;
	static inline auto SetupURL = (void(*)())0x53FA40;
	static inline auto SetupShortTrack = (void(*)())0x53F370;
	static inline auto SetupOutrun = (void(*)(bool))0x526830;
	static inline auto SetupFreeRun = (void(*)())0x53F580;
	static inline auto SetupBurnout = (void(*)())0x526720;
	static inline auto StartSkipFERace = (void(*)())0x53FEB0;
};