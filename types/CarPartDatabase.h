enum CAR_SLOT_ID {
	CARSLOTID_BASE = 0,
	CARSLOTID_FRONT_BUMPER = 1,
	CARSLOTID_REAR_BUMPER = 2,
	CARSLOTID_LEFT_SIDE_MIRROR = 3,
	CARSLOTID_RIGHT_SIDE_MIRROR = 4,
	CARSLOTID_BODY = 5,
	CARSLOTID_WIDE_BODY = 6,
	CARSLOTID_ROOF = 7,
	CARSLOTID_TOP = 8,
	CARSLOTID_HOOD = 9,
	CARSLOTID_TRUNK = 10,
	CARSLOTID_SKIRT = 11,
	CARSLOTID_SPOILER = 12,
	CARSLOTID_ENGINE = 13,
	CARSLOTID_HEADLIGHT = 14,
	CARSLOTID_BRAKELIGHT = 15,
	CARSLOTID_DOOR_LEFT = 17,
	CARSLOTID_DOOR_RIGHT = 18,
	CARSLOTID_DOOR_PANEL_LEFT = 19,
	CARSLOTID_DOOR_PANEL_RIGHT = 20,
	CARSLOTID_DOOR_SILL_LEFT = 21,
	CARSLOTID_DOOR_SILL_RIGHT = 22,
	CARSLOTID_FENDER = 23,
	CARSLOTID_QUARTER = 24,
	CARSLOTID_HOOD_UNDER = 25,
	CARSLOTID_TRUNK_UNDER = 26,
	CARSLOTID_EXHAUST = 16,
	CARSLOTID_BRAKE = 27,
	CARSLOTID_WHEEL = 28,
	CARSLOTID_SPINNER = 29,
	CARSLOTID_WING_MIRROR = 30,
	CARSLOTID_LICENSE_PLATE = 31,
	CARSLOTID_DAMAGE_FRONT = 32,
	CARSLOTID_DAMAGE_REAR = 33,
	CARSLOTID_DAMAGE_LEFT = 34,
	CARSLOTID_DAMAGE_RIGHT = 35,
	CARSLOTID_DAMAGE_TOP = 36,
	CARSLOTID_DECAL_HOOD = 37,
	CARSLOTID_DECAL_FRONT_WINDOW = 38,
	CARSLOTID_DECAL_REAR_WINDOW = 39,
	CARSLOTID_DECAL_LEFT_DOOR = 40,
	CARSLOTID_DECAL_RIGHT_DOOR = 41,
	CARSLOTID_DECAL_LEFT_QUARTER = 42,
	CARSLOTID_DECAL_RIGHT_QUARTER = 43,
	CARSLOTID_WIDEBODY_DECAL_LEFT_DOOR = 44,
	CARSLOTID_WIDEBODY_DECAL_RIGHT_DOOR = 45,
	CARSLOTID_WIDEBODY_DECAL_LEFT_QUARTER = 46,
	CARSLOTID_WIDEBODY_DECAL_RIGHT_QUARTER = 47,
	CARSLOTID_PAINT = 48,
	CARSLOTID_VINYL_PAINT = 49,
	CARSLOTID_VINYL = 50,
	CARSLOTID_CARBON_FIBRE = 51,
	CARSLOTID_DECAL_TEXTURE = 52,
	CARSLOTID_WINDOW_TINT = 53,
	CARSLOTID_NEON = 54,
	CARSLOTID_CABIN_NEON_FRAME = 55,
	CARSLOTID_HEADLIGHT_BULB = 56,
	CARSLOTID_DOOR_STYLE = 57,
	CARSLOTID_HYDRAULICS = 58,
	CARSLOTID_NOS_PURGE = 59,
	CARSLOTID_TRUNK_AUDIO = 60,
	CARSLOTID_TRUNK_AUDIO_COMP_SMALL = 61,
	CARSLOTID_TRUNK_AUDIO_COMP_MEDIUM = 62,
	CARSLOTID_TRUNK_AUDIO_COMP_LARGE = 63,
	CARSLOTID_CUSTOM_HUD = 64,
	CARSLOTID_CUSTOM_HUD_PAINT = 65,
	CARSLOTID_CV = 66,
	CARSLOTID_WHEEL_MANUFACTURER = 67,
	CARSLOTID_MISC = 68,
	CARSLOTID_NUM = 170,
};

class CarPartIDNameMap {
public:
	int CarPartID;
	const char* Name;
};
auto CarPartIDNames = (CarPartIDNameMap*)0x803338;
auto CarSlotIDNames = (CarPartIDNameMap*)0x802DE8;

class CarPart {
public:
	unsigned short PartNameHashBot;
	unsigned short PartNameHashTop;
	char PartID;
	unsigned char GroupNumber_UpgradeLevel;
	char BaseModelNameHashSelector;
	unsigned char CarTypeNameHashIndex;
	unsigned short NameOffset;
	unsigned short AttributeTableOffset;
	unsigned short ModelNameHashTableOffset;

	inline uint32_t GetPartNameHash() {
		return *(uint32_t*)&PartNameHashBot;
	}
};
static_assert(sizeof(CarPart) == 0xE);

class CarPartAttributeTable;
class CarPartAttribute;
class CarPartModelTable;
class CarPartPack : public bTNode<CarPartPack> {
public:
	unsigned int Version;
	const char* StringTable;
	unsigned int StringTableSize;
	CarPartAttributeTable* AttributeTableTable;
	unsigned int NumAttributeTables;
	CarPartAttribute* AttributesTable;
	unsigned int NumAttributes;
	unsigned int* TypeNameTable;
	unsigned int NumTypeNames;
	CarPartModelTable* ModelTable;
	unsigned int NumModelTables;
	CarPart* PartsTable;
	unsigned int NumParts;
};
static_assert(sizeof(CarPartPack) == 0x3C);
static_assert(offsetof(CarPartPack, PartsTable) == 0x34);
static_assert(offsetof(CarPartPack, NumParts) == 0x38);

class CarPartDatabase : public bTList<CarPartDatabase> {
public:
	bTList<CarPartPack> CarPartPackList;

	// inlined
	CarPart* GetCarPartByIndex(int index) {
		if (index < 0) return nullptr;
		auto node = CarPartPackList.HeadNode.Next;
		while (node != &CarPartPackList.HeadNode) {
			if (node->NumParts < index) {
				return &node->PartsTable[index];
			}
			index -= node->NumParts;
			node = node->Next;
		}
		return nullptr;
	}
};
auto& CarPartDB = *(CarPartDatabase*)0x8A2B68;