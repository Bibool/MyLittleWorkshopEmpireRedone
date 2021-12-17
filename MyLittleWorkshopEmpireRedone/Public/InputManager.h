#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include <string>

class GameManager;

class InputManager
{
public:
	InputManager();
	~InputManager();

	int  HandleInput		( const std::string& input );

private:
	bool CharCompare	( const char input, const char inKey ) const;
	bool IsSingleChar	( const std::string input ) const;

	static constexpr int EXIT = 0;
	static constexpr int CONTINUE = 1;
};

#endif