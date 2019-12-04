#ifndef MODULE_H_
#define MODULE_H_

class Module
{
public:
	Module() = delete;
	Module(const unsigned mass);
	virtual ~Module() = default;

	unsigned GetMass() const { return m_Mass; }
	void SetMass(const unsigned mass) { m_Mass = mass; }

private:
	unsigned m_Mass;
};

#endif	// MODULE_H_