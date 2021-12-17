#ifndef TOOLMANAGER_H
#define TOOLMANAGER_H

#include "config.h"

#include <array>

class Tool;

class ToolManager
{
public:
	ToolManager();
	~ToolManager();

	const std::array<Tool*, 6>& GetTools() const;
	Tool* FindTool( const char* inName ) const;
	
private:
	void InitTools();
	std::array<Tool*, Tools::MaxTools> m_apcTools{};
};

#endif