#ifndef DRIVER_DRIVERFIRSTHALF_H_
#define DRIVER_DRIVERFIRSTHALF_H_

#include "Driver/IDriver.h"

class DriverFirstHalf final : public IDriver
{
public:
	DriverFirstHalf() = delete;
	DriverFirstHalf(const std::string& inputFilePath, const std::string& answerFilePath);
	virtual ~DriverFirstHalf() = default;

protected:
	virtual bool ReadInputInternal(std::ifstream& inputFile) const;
	virtual bool ExecuteInternal();
	virtual bool WriteAnswerInternal(std::ofstream& answerFile) const;

private:
	// TODO: Add your data here

};

#endif	// DRIVER_DRIVERFIRSTHALF_H_