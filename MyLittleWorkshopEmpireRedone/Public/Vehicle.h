#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include "VehicleType.h"

#include <list>

class Malfunction;

class Vehicle
{
public:
	Vehicle();
	Vehicle( const char* name, const EVehicleType& eType );
	~Vehicle();

	void AddMalfunction( Malfunction* newMalfunction );
	std::list<Malfunction*> GetMalfunctions() const;
	const char* GetName() const;

private:
	std::list<Malfunction*> m_apcMalfunctions;
	const char* m_pszName;
	EVehicleType m_eType;
};

#endif