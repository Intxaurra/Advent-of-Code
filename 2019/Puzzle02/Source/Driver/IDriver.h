#ifndef DRIVER_IDRIVER_H_
#define DRIVER_IDRIVER_H_

#include <fstream>
#include <string>

class IDriver
{
public:
	IDriver() = delete;
	IDriver(const std::string& inputFilePath, const std::string& answerFilePath);
	virtual ~IDriver() = default;

	bool Execute();

protected:
	virtual bool ReadInputInternal(std::ifstream& inputFile) const = 0;
	virtual bool ExecuteInternal() = 0;
	virtual bool WriteAnswerInternal(std::ofstream& answerFile) const = 0;

private:
	bool ReadInput() const;
	bool WriteAnswer() const;

private:
	std::string m_InputFilePath;
	std::string m_AnswerFilePath;
};

#endif	// DRIVER_IDRIVER_H_