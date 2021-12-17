#include "../Public/Vehicle.h"

#include "../Public/debug.h"
#include "../Public/Malfunction.h"

Vehicle::Vehicle()
	: m_pszName( "" )
{}

Vehicle::Vehicle( const char* name )
	: m_pszName ( name )
{}

Vehicle::~Vehicle()
{
	for (Malfunction* malfunction : m_apcMalfunctions)
	{
		SafeDelete( malfunction );
	}
}

void Vehicle::AddMalfunction( Malfunction* newMalfunction )
{
	m_apcMalfunctions.push_back( newMalfunction );
}

std::list<Malfunction*> Vehicle::GetMalfunctions() const
{
	return m_apcMalfunctions;
}

const char* Vehicle::GetName() const
{
	return m_pszName;
}
