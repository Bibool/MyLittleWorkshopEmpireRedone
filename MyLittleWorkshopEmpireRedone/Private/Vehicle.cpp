#include "../Public/Vehicle.h"

#include "../Public/debug.h"

Vehicle::Vehicle()
	: m_pszName( "" )
	, m_eType(EVehicleType::CompactCar)
{}

Vehicle::Vehicle( const char* name, const EVehicleType& eType )
	: m_pszName ( name )
	, m_eType ( eType )
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
