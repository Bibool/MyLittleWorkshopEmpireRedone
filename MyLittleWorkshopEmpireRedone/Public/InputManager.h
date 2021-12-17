#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <string>

class GameManager;

class InputManager
{
public:
	InputManager() = default;
	~InputManager() = default;

	int  HandleInput		( const std::string& input ) const;

private:
	static bool CharCompare	( const char input, const char inKey );
	static bool IsSingleChar	( const std::string& input );

	static constexpr int EXIT = 0;
	static constexpr int CONTINUE = 1;
};

#endif