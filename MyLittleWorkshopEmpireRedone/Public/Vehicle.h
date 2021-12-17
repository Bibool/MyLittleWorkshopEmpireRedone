#ifndef VEHICLE_H
#define VEHICLE_H

#include <list>

class Malfunction;

class Vehicle
{
public:
	Vehicle();
	Vehicle( const char* name );
	~Vehicle();

	void AddMalfunction( Malfunction* newMalfunction );
	std::list<Malfunction*> GetMalfunctions() const;
	const char* GetName() const;

private:
	std::list<Malfunction*> m_apcMalfunctions;
	const char*				m_pszName;
};

#endif