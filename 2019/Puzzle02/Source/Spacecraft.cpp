#include "Spacecraft.h"

#include <fstream>
#include <sstream>

Spacecraft::Spacecraft(const FuelConsumptionMode fuelConsumptionMode)
	: m_FuelConsumptionMode(fuelConsumptionMode)
{
}

void Spacecraft::LoadModules(const std::string& fileName)
{
	std::vector<unsigned> moduleMassArray;
	GetModuleMassValuesFromFile(fileName, moduleMassArray);

	if (!moduleMassArray.empty())
	{
		const unsigned numOfNewModules = moduleMassArray.size();
		m_ModuleArray.reserve(numOfNewModules);
		m_FuelPerModuleArray.reserve(numOfNewModules);

		for (const unsigned moduleMass : moduleMassArray)
		{
			const Module newModule(moduleMass);
			m_ModuleArray.push_back(newModule);

			const Fuel requiredFuel = CalculateRequiredFuel(newModule);
			m_FuelPerModuleArray.push_back(requiredFuel);
		}
	}
}

void Spacecraft::GetModuleMassValuesFromFile(const std::string& fileName, std::vector<unsigned>& moduleMassArray) const
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		while (!file.eof())
		{
			unsigned moduleMass = 0u;
			file >> moduleMass;

			moduleMassArray.push_back(moduleMass);
		}

		file.close();
	}
}

Fuel Spacecraft::CalculateRequiredFuel(const Module& module) const
{
	// Formula for fuel cost: floor(mass / 3) - 2

	unsigned totalRequiredFuel = 0u;

	unsigned currentMass = module.GetMass();
	const bool doesFuelRequireMoreFuel = m_FuelConsumptionMode != FuelConsumptionMode::FuelNeedsNoFuel;

	do
	{
		// Integer division automatically rounds down our value
		constexpr unsigned divisor = 3u;
		unsigned currentRequiredFuel = currentMass / divisor;

		// Avoid overflow
		constexpr unsigned substractor = 2u;
		if (currentRequiredFuel >= substractor)
			currentRequiredFuel -= substractor;
		else
			currentRequiredFuel = 0u;

		totalRequiredFuel += currentRequiredFuel;

		if (doesFuelRequireMoreFuel)
			currentMass = currentRequiredFuel;
		else
			currentMass = 0u;
	}
	while (currentMass > 0u);
	

	return Fuel(totalRequiredFuel);
}