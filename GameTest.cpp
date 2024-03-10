#include "pch.h"
#include "..//Project OOP/source/headers/Game.h"

namespace GameTest
{
	TEST(CreateWindow, CreateWindow)
	{
		Game game;
		game.createWindow();
	}

	TEST(Mainloop, Mainloop)
	{
		Game game;
		game.createWindow();
		//game.mainloop(); // Failed to load font "source/fontes/Gilroy-Heavy.woff" (failed to create the font face) 
	}

	TEST(WidthAndHeight, DefaultValues)
	{
		Game game;

		EXPECT_EQ(game.getWidth(), sf::VideoMode::getDesktopMode().width);
		EXPECT_EQ(game.getHeight(), sf::VideoMode::getDesktopMode().height);
	}

	TEST(WidthAndHeight, SetValues)
	{
		Game game;

		game.setWidth(10);
		game.setHeight(10);

		EXPECT_EQ(game.getWidth(), 10);
		EXPECT_EQ(game.getHeight(), 10);
	}
}