class RideInfo {
public:
	int CarType; // +0

	static inline auto Init = (void(__thiscall*)(RideInfo*, int, int, int, int))0x610270;
	static inline auto SetStockParts = (void(__thiscall*)(RideInfo*, int))0x637040;
	static inline auto SetCompositeNameHash = (void(__thiscall*)(RideInfo*, int))0x61C280;
	static inline auto FillWithPreset = (void(__thiscall*)(RideInfo*, uint32_t))0x637270;
};