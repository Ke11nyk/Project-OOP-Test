#include "pch.h"
#include "..//Project OOP/source/headers/GameMenu.h"

namespace GameMenuTest
{
	sf::RenderWindow WWin;
	TEST(CreateMenu, CreateMenu)
	{
		std::vector<sf::String> vecNameMenu{ "Test1", "Test2", "Test3", "Test4" };
		GameMenu myMenu(WWin, 950, 350, 100, 120, vecNameMenu);
	}

	std::vector<sf::String> vecNameMenu{ "Test1", "Test2", "Test3", "Test4" };
	GameMenu myMenu(WWin, 950, 350, 100, 120, vecNameMenu);

	TEST(DrawMenu, DrawMenu)
	{
		myMenu.setColorTextMenu(sf::Color::White, sf::Color::Red, sf::Color::Black);
		myMenu.AlignMenu(2);
		myMenu.Draw();
	}

	TEST(MoveMenu, MoveUp)
	{
		myMenu.MoveUp();
		ASSERT_EQ(3, myMenu.getSelectedMenuNumber());
	}

	TEST(MoveMenu, MoveDown)
	{
		myMenu.MoveDown();
		ASSERT_EQ(0, myMenu.getSelectedMenuNumber());
	}
}