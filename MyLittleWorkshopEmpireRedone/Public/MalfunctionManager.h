#ifndef _MALFUNCTIONMANAGER_H_
#define	_MALFUNCTIONMANAGER_H_

#include "config.h"
#include <array>

class GameManager;
class Malfunction;

class MalfunctionManager
{
public:
	MalfunctionManager();
	~MalfunctionManager();

	const std::array<Malfunction*, Malfunctions::MaxMalfunctions>& GetMalfunctions() const;
	void Init();

private:
	void GenerateMalfunctions();

	std::array<Malfunction*, Malfunctions::MaxMalfunctions> m_apcMalfunctions;
};

#endif