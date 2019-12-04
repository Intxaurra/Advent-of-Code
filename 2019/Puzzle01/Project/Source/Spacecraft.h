#ifndef SPACECRAFT_H_
#define SPACECRAFT_H_

#include "Fuel.h"
#include "Module.h"

#include <string>
#include <vector>

class Spacecraft
{
public:
	enum class FuelConsumptionMode : unsigned char
	{
		FuelNeedsNoFuel,
		FuelConsumesMoreFuel
	};

	Spacecraft() = delete;
	Spacecraft(const FuelConsumptionMode fuelConsumptionMode);
	virtual ~Spacecraft() = default;

	void LoadModules(const std::string& fileName);

	FuelConsumptionMode GetFuelConsumptionMode() const { return m_FuelConsumptionMode; }
	const std::vector<Module>& GetModuleArray() const { return m_ModuleArray; }
	const std::vector<Fuel>& GetFuelPerModuleArray() const { return m_FuelPerModuleArray; }

private:
	void GetModuleMassValuesFromFile(const std::string& fileName, std::vector<unsigned>& moduleMassArray) const;
	Fuel CalculateRequiredFuel(const Module& module) const;

private:
	FuelConsumptionMode m_FuelConsumptionMode;
	std::vector<Module> m_ModuleArray;
	std::vector<Fuel> m_FuelPerModuleArray;
};

#endif	// SPACECRAFT_H_