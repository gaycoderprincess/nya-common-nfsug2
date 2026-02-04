class PresetCar : public bTNode<PresetCar> {
public:
	char CarTypeName[32];
	char PresetName[32];
	int PhysicsLevel; // +48
	uint8_t _4C[0x2EC];
};
static_assert(sizeof(PresetCar) == 0x338);
static_assert(offsetof(PresetCar, PhysicsLevel) == 0x48);
auto& PresetCarList = *(bList<PresetCar>*)0x8A31E4;

auto FindFEPresetCar = (PresetCar*(__cdecl*)(uint32_t))0x61C460;