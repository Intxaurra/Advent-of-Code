#include "Driver/IDriver.h"

IDriver::IDriver(const std::string& inputFilePath, const std::string& answerFilePath)
	: m_InputFilePath(inputFilePath)
	, m_AnswerFilePath(answerFilePath)
{
}

bool IDriver::Execute()
{
	bool success = false;

	if (ReadInput())
	{
		if (ExecuteInternal())
		{
			success = WriteAnswer();
		}
	}

	return success;
}

bool IDriver::ReadInput() const
{
	bool success = false;

	std::ifstream inputFile(m_InputFilePath);

	if (inputFile.is_open())
	{
		success = ReadInputInternal(inputFile);
		inputFile.close();
	}

	return success;
}

bool IDriver::WriteAnswer() const
{
	bool success = false;

	std::ofstream answerFile(m_AnswerFilePath);

	if (answerFile.is_open())
	{
		success = WriteAnswerInternal(answerFile);
		answerFile.close();
	}

	return success;
}