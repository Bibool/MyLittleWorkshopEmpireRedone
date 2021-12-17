#ifndef JOBMANAGER_H
#define JOBMANAGER_H

#include "VehicleType.h"

#include <list>

class GameManager;
class Malfunction;
class Vehicle;

class JobManager
{
public:
	JobManager();
	~JobManager();

	const std::list<Vehicle*>& GetVehicles() const;
	Malfunction**	GetJobs();
	void			Init();
	void			SelectJob( int atIndex );

private:
	void			GeneratorJobs();
	const char*		GetVehicleName( const EVehicleType& vehicleType );
	Malfunction*	GetMalfunction( const EVehicleType& vehicleType );
	int				GetNumMalfunctionForVehicle( const EVehicleType& vehicleType ) const;
	void			CleanUp();
	void			CheckIfAllJobsFinished();

	std::list<Vehicle*>		m_apcCurrentVehicles;
	std::list<const char*>	m_apszNames;
	std::list<Malfunction*> m_apcMalfunctionsFound;
	int						m_iNameIndex;
	int						m_iMalfunctionIndex;
	int						m_iJobsCompleted;
	Malfunction*			m_apcJobs[10];
};

#endif