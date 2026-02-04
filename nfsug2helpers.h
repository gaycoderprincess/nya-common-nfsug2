namespace NyaHelpers {
	PresetCar CreatePresetCar(FECarConfig* record, const char* presetName) {
		auto typeInfo = GetCarTypeInfoFromHash(record->PresetCar.CarTypeHash);

		PresetCar car;
		strcpy_s(car.CarTypeName, 32, typeInfo->CarTypeName);
		strcpy_s(car.PresetName, 32, presetName);
		car.PhysicsLevel = 3; // todo

		for (int i = 0; i < CARSLOTID_NUM; i++) {
			auto part = CarPartDB.GetCarPartByIndex(record->PresetCar.InstalledPartIndices[i]);
			car.PartNameHashes[i] = part ? part->GetPartNameHash() : 0;
		}
		return car;
	}
}