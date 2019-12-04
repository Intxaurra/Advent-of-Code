#ifndef FUEL_H_
#define FUEL_H_

class Fuel
{
public:
	Fuel() = delete;
	Fuel(const unsigned fuel);
	virtual ~Fuel() = default;

	unsigned GetFuel() const { return m_Fuel; }
	void SetFuel(const unsigned fuel) { m_Fuel = fuel; }

private:
	unsigned m_Fuel;
};

#endif	// FUEL_H_