#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

class Player;
class InputManager;
class MalfunctionManager;
class MessageManager;
class JobManager;
class ToolManager;

class GameManager;
extern GameManager* g_GameManager;

class GameManager
{
public:
	GameManager();
	~GameManager();

	InputManager*		GetInputManager();
	MessageManager*		GetMessageManager();
	JobManager*			GetJobManager();
	ToolManager*		GetToolManager();
	Player*				GetPlayer();
	MalfunctionManager* GetMalfunctionManager();

private:
	InputManager*		m_pcInputManager;
	MessageManager*		m_pcMessageManager;
	JobManager*			m_pcJobManager;
	ToolManager*		m_pcToolManager;
	Player*				m_pcPlayer;
	MalfunctionManager* m_pcMalfunctionManager;
};

#endif