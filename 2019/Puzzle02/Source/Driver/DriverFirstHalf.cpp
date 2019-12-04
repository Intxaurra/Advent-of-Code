#include "Driver/DriverFirstHalf.h"

DriverFirstHalf::DriverFirstHalf(const std::string& inputFilePath, const std::string& answerFilePath)
	: IDriver(inputFilePath, answerFilePath)
{
}

bool DriverFirstHalf::ReadInputInternal(std::ifstream& inputFile) const
{
	// TODO: Read your input data
	return false;
}

bool DriverFirstHalf::ExecuteInternal()
{
	// TODO: Solve the problem
	return false;
}

bool DriverFirstHalf::WriteAnswerInternal(std::ofstream& answerFile) const
{
	// TODO: Write your answer
	return false;
}