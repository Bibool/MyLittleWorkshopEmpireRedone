#ifndef _TOOLMANAGER_H_
#define _TOOLMANAGER_H_

#include <array>

class Tool;

class ToolManager
{
public:
	ToolManager();
	~ToolManager();

	const std::array<Tool*, 6>& GetTools() const;
	Tool* FindTool( const char* inName );
	
private:
	void InitTools();
	std::array<Tool*, 6> m_apcTools;
};

#endif