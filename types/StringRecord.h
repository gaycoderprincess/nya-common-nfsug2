struct StringRecord {
	uint32_t Hash;
	const char* PackedString;
};

auto& NumStringRecords = *(uint32_t*)0x8383D0;
auto& RecordTable = *(StringRecord**)0x8383D8;
auto GetLocalizedString = (const char*(*)(uint32_t stringLabel))0x4FFA80;
auto SearchForString = (const char*(__fastcall*)(void*, uint32_t))0x4FF9D0;
auto CalcTrackNameHash = (uint32_t(*)(int, bool reverse))0x516280;