#include "pch.h"
#include "..//Project OOP/source/headers/Gameplay.h"

namespace GameplayTest
{
	TEST(CreateGameplay, CreateGameplay)
	{
		sf::RenderWindow WWin;
		GameSound gameSound;
		Gameplay gameplay(WWin, gameSound);
	}

	TEST(LevelMenu, LevelMenu)
	{
		sf::RenderWindow WWin;
		GameSound gameSound;
		Gameplay gameplay(WWin, gameSound);

		gameplay.LevelMenu();
	}
}