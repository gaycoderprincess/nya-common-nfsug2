class DriftScore {
public:
	uint8_t _0[0x8];
	int DriverNumber; // +8
	int CarClass; // +C
	float fScore; // +10
	uint8_t _14[0x4];
	const char* sPlayerName; // +18
	uint8_t _1C[0x4];
};
static_assert(sizeof(DriftScore) == 0x20);

class DriftManager {
public:
	static inline auto GetLeaderBoardScore = (DriftScore*(*)(int))0x56DD50;
};