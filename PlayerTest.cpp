#include "pch.h"
#include <Windows.h>
#include "..//Project OOP/source/headers/Player.h"

namespace PlayerTest
{
	sf::RenderWindow WWin;
	std::vector<sf::String> vecTileMap = {"A   A", 
										  "A   A", 
										  "AAAAA"};

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

		stick.getStick().setPosition(sf::Vector2f(100, 0));
		stick.Update(sf::seconds(0.5)); // stepy 0
		stick.Update(sf::seconds(0.5)); // stepy 0.015

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 0.015));

		stick.Update(sf::seconds(0.5)); // stepy 0.03

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 0.044999998));

		stick.Update(sf::seconds(0.5)); // stepy 0.045

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 0.089999998));

		stick.Update(sf::seconds(0.5)); // stepy 0.06

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 0.149999998));

		for(int i = 0; i < 1000; i++) stick.Update(sf::seconds(0.5)); // falling to colise with block A

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 40)); // height of two blocks 100 minus height of player 60

		for (int i = 0; i < 1000; i++) stick.Update(sf::seconds(0.5)); // falling to colise with block A

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(100, 40)); // height of two blocks 100 minus height of player 60
	}

	TEST(Collision, Left)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		stick.getStick().setPosition(sf::Vector2f(100, 40));

		keybd_event('A', 0, 0, 0);

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx 0
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(90, 40));

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(80, 40));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(50, 40));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(50, 40)); // width of block

		keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
	}

	TEST(Collision, Right)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
		sf::Event EEvent;
		WWin.pollEvent(EEvent);

		stick.getStick().setPosition(sf::Vector2f(100, 40));

		keybd_event('D', 0, 0, 0);

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx 0
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(110, 40));

		stick.Keys(EEvent);
		stick.Update(sf::seconds(0.5)); // stepx -10

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(120, 40));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(146, 40));

		for (int i = 0; i < 3; i++)
		{
			stick.Keys(EEvent);
			stick.Update(sf::seconds(0.5)); // stepx -10
		}

		ASSERT_EQ(stick.getStick().getPosition(), sf::Vector2f(146, 40)); // width of block plus stick

		keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
	}
}