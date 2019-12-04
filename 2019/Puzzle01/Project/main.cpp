#include "Source/Spacecraft.h"

#include <fstream>
#include <sstream>

unsigned GetTotalFuelRequired(const Spacecraft& spacecraft)
{
	const std::vector<Fuel>& fuelPerModuleArray = spacecraft.GetFuelPerModuleArray();

	unsigned totalFuelRequired = 0u;
	for (const Fuel& fuelRequired : fuelPerModuleArray)
	{
		totalFuelRequired += fuelRequired.GetFuel();
	}

	return totalFuelRequired;
}

void WriteAnswer(const std::string& filePath, const unsigned answer)
{
	std::ofstream answerFile(filePath);

	if (answerFile.is_open())
	{
		answerFile << answer;
		answerFile.close();
	}
}

int main(void)
{
	const std::string inputFilePath = "../Input/Input.txt";
	const std::string answerFirstHalfFilePath = "../Answer/AnswerFirstHalf.txt";
	const std::string answerSecondHalfFilePath = "../Answer/AnswerSecondHalf.txt";

	// First half: fuel doesn't consume more fuel
	Spacecraft spacecraftFirstHalf(Spacecraft::FuelConsumptionMode::FuelNeedsNoFuel);
	spacecraftFirstHalf.LoadModules(inputFilePath);

	WriteAnswer(answerFirstHalfFilePath, GetTotalFuelRequired(spacecraftFirstHalf));

	// Second half: fuel consumes more fuel recursively
	Spacecraft spacecraftSecondHalf(Spacecraft::FuelConsumptionMode::FuelConsumesMoreFuel);
	spacecraftSecondHalf.LoadModules(inputFilePath);

	WriteAnswer(answerSecondHalfFilePath, GetTotalFuelRequired(spacecraftSecondHalf));

	return 0;
}