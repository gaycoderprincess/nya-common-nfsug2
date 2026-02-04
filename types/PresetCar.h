class PresetCar : public bTNode<PresetCar> {
public:
	char CarTypeName[32];
	char PresetName[32];
	int PhysicsLevel; // +48
	uint32_t PartNameHashes[170]; // +4C
	uint8_t PerformanceParts[68]; // +2F4
};
static_assert(sizeof(PresetCar) == 0x338);
static_assert(offsetof(PresetCar, PhysicsLevel) == 0x48);
static_assert(offsetof(PresetCar, PartNameHashes) == 0x4C);
static_assert(offsetof(PresetCar, PerformanceParts) == 0x2F4);
auto& PresetCarList = *(bList<PresetCar>*)0x8A31E4;

auto FindFEPresetCar = (PresetCar*(__cdecl*)(uint32_t))0x61C460;