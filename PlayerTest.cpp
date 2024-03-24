#include "pch.h"
#include <Windows.h>
#include "..//Project OOP/source/headers/Player.h"

namespace PlayerTest
{
	sf::RenderWindow WWin;
	std::vector<sf::String> vecTileMap = { "AAAAA",
										  "A   A",
										  "A   A",
										  "AAAAA" };

	std::vector<sf::String> vecTileMap1 = { "AAAAA",
										   "A   A",
										   "Ao DA",
										   "AAAAA" };

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

	TEST(Collision, Falling)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);

		stick.getStick().setPosition(sf::Vector2f(100, 50));
		stick.Update(sf::seconds(0.5)); // stepy 0
		stick.Update(sf::seconds(0.5)); // stepy 0.015

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 50.015));

		stick.Update(sf::seconds(0.5)); // stepy 0.03

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 50.044999998));

		stick.Update(sf::seconds(0.5)); // stepy 0.045

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 50.089996));

		stick.Update(sf::seconds(0.5)); // stepy 0.06

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 50.149996));

		for (int i = 0; i < 1000; i++) stick.Update(sf::seconds(0.5)); // falling to colise with block A

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 90)); // height of two blocks 100 minus height of player 60

		for (int i = 0; i < 1000; i++) stick.Update(sf::seconds(0.5)); // falling to colise with block A

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 90)); // height of two blocks 100 minus height of player 60
	}

	TEST(Collision, Jumping)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		stick.getStick().setPosition(sf::Vector2f(100, 90));

		keybd_event('W', 0, 0, 0);

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx -2.4 + 0.015

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 87.615));

		stick.Update(sf::seconds(0.5)); // stepx -2.4 + 0.03

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 85.244995));

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx -2.4 + 0.045 

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 82.88999));

		for (int i = 0; i < 30; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5));
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 51.799995));

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5));

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 52.039997));

		for (int i = 0; i < 100; i++)
			stick.Update(sf::seconds(0.5));

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 90)); // width of block

		keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(Collision, Left)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		stick.getStick().setPosition(sf::Vector2f(100, 90));

		keybd_event('A', 0, 0, 0);

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx 0
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(90, 90));

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(80, 90));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(50, 90));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(50, 90)); // width of block

		keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(Collision, Right)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		stick.getStick().setPosition(sf::Vector2f(100, 90));

		keybd_event('D', 0, 0, 0);

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx 0
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(110, 90));

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(120, 90));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(146, 90));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(146, 90)); // width of block plus stick

		keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(Collision, Point)
	{
		Player stick = Player(WWin, vecTileMap1, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		stick.getStick().setPosition(sf::Vector2f(100, 90));

		ASSERT_EQ(stick.getPoints(), 0);

		keybd_event('A', 0, 0, 0);

		for (int i = 0; i < 30; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(50, 90));
		ASSERT_EQ(stick.getPoints(), 1);

		keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(Collision, Door)
	{
		Player stick = Player(WWin, vecTileMap1, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		stick.getStick().setPosition(sf::Vector2f(100, 90));

		ASSERT_EQ(stick.getDoorOpened(), false);

		keybd_event('D', 0, 0, 0);

		for (int i = 0; i < 30; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(146, 90));
		ASSERT_EQ(stick.getDoorOpened(), true);

		keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
	}
}