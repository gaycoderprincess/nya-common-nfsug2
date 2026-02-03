class PresetCar : public bTNode<PresetCar> {
public:
	char CarTypeName[32];
	char PresetName[32];
	uint8_t _48[0x2F0];
};
static_assert(sizeof(PresetCar) == 0x338);
auto& PresetCarList = *(bList<PresetCar>*)0x8A31E4;

auto FindFEPresetCar = (PresetCar*(__cdecl*)(uint32_t))0x61C460;