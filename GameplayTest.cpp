#include "pch.h"
#include "..//Project OOP/source/headers/Gameplay.h"

namespace GameplayTest
{
	TEST(CreateGameplay, CreateGameplay)
	{
		sf::RenderWindow WWin;
		Gameplay gameplay(WWin);
	}

	TEST(LevelMenu, LevelMenu)
	{
		sf::RenderWindow WWin;
		Gameplay gameplay(WWin);

		gameplay.LevelMenu();
	}
}