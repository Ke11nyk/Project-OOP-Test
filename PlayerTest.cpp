#include "pch.h"
#include <Windows.h>
#include "..//Project OOP/source/headers/Player.h"

namespace PlayerTest
{
	sf::RenderWindow WWin;
	std::vector<sf::String> vecTileMap = {"    ", "    ", "aaaa"};

	TEST(MovePlayer, MoveLeft)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		keybd_event('A', 0, 0, 0);
		
		ASSERT_EQ(sf::Keyboard::isKeyPressed(sf::Keyboard::A), true);

		stick.Keys(EEvent);

		ASSERT_EQ(stick.getStepx(), -10.0f);

		keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(MovePlayer, MoveRight)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		keybd_event('D', 0, 0, 0);

		ASSERT_EQ(sf::Keyboard::isKeyPressed(sf::Keyboard::D), true);

		stick.Keys(EEvent);

		ASSERT_EQ(stick.getStepx(), 10.0f);

		keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(MovePlayer, MoveUp)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		keybd_event('W', 0, 0, 0);

		ASSERT_EQ(sf::Keyboard::isKeyPressed(sf::Keyboard::W), true);

		stick.Keys(EEvent);

		ASSERT_EQ(stick.getStepy(), -2.4f);

		keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(Collision, Collision)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);

		stick.getStick().setPosition(sf::Vector2f(0, 0));
		stick.Update(sf::seconds(0.5));
		stick.Update(sf::seconds(0.5));

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(0, 0.015));

		stick.Update(sf::seconds(0.5));
		stick.Update(sf::seconds(0.5));

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(0, 0.045));

	}
}