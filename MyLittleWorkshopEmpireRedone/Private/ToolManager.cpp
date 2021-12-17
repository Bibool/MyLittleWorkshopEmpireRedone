#include "../Public/ToolManager.h"

#include "../Public/config.h"
#include "../Public/debug.h"
#include "../Public/Tool.h"

ToolManager::ToolManager()
{
	InitTools();
}

ToolManager::~ToolManager()
{
	for ( Tool* tool : m_apcTools )
	{
		SafeDelete( tool );
	}
}

const std::array<Tool*, Tools::MaxTools>& ToolManager::GetTools() const
{
	return m_apcTools;
}

Tool* ToolManager::FindTool( const char* inName ) const
{
	for ( Tool* tool : m_apcTools )
	{
		if ( tool->GetName() == inName )
		{
			return tool;
		}
	}

	return nullptr;
}

void ToolManager::InitTools()
{
	for ( int i = 0; i != Tools::MaxTools; ++i )
	{
		m_apcTools.at( i ) = new Tool( Tools::ToolsName[i], Tools::ToolsPrice[i] );
	}	
}