class CarTypeInfo {
public:
	char CarTypeName[32];
	char BaseModelName[32];
	char GeometryFilename[32];
	uint8_t _60[0x70];
	uint32_t TypeHash; // +D0
	uint8_t _D4[0x76C];
	int Type; // +840
	uint8_t _844[0x4C];
};
static_assert(sizeof(CarTypeInfo) == 0x890);
static_assert(offsetof(CarTypeInfo, TypeHash) == 0xD0);
static_assert(offsetof(CarTypeInfo, Type) == 0x840);

auto& CarTypeInfoArray = *(CarTypeInfo**)0x8A1CCC;

auto GetCarTypeInfoFromHash = (CarTypeInfo*(*)(uint32_t))0x610130;