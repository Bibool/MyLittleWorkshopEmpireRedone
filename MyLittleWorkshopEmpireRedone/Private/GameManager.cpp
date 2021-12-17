#include "../Public/GameManager.h"
			
#include "../Public/InputManager.h"
#include "../Public/MessageManager.h"
#include "../Public/JobManager.h"
#include "../Public/ToolManager.h"
#include "../Public/Player.h"
#include "../Public/MalfunctionManager.h"
#include "../Public/config.h"
#include "../Public/debug.h"

GameManager* g_GameManager = nullptr;

GameManager::GameManager()
{
	g_GameManager = this;

	m_pcInputManager = new InputManager();
	m_pcMessageManager = new MessageManager();
	m_pcToolManager = new ToolManager();
	m_pcPlayer = new Player();
	m_pcMalfunctionManager = new MalfunctionManager();
	m_pcJobManager = new JobManager();

	m_pcPlayer->Init();
	m_pcMalfunctionManager->Init();
	m_pcJobManager->Init();
}

InputManager* GameManager::GetInputManager()
{
	return m_pcInputManager;
}

MessageManager* GameManager::GetMessageManager()
{
	return m_pcMessageManager;
}

JobManager* GameManager::GetJobManager()
{
	return m_pcJobManager;
}

ToolManager* GameManager::GetToolManager()
{
	return m_pcToolManager;
}

Player* GameManager::GetPlayer()
{
	return m_pcPlayer;
}

MalfunctionManager* GameManager::GetMalfunctionManager()
{
	return m_pcMalfunctionManager;
}

GameManager::~GameManager()
{
	// Clean up our pointers
	SafeDelete( m_pcJobManager );
	SafeDelete( m_pcMalfunctionManager );
	SafeDelete( m_pcPlayer );
	SafeDelete( m_pcToolManager );
	SafeDelete( m_pcMessageManager );
	SafeDelete( m_pcInputManager );
}