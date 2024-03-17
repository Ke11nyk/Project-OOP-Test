#include "pch.h"
#include "..//Project OOP/source/headers/Player.h"

namespace PlayerTest
{
	sf::RenderWindow WWin;
	std::vector<sf::String> vecTileMap = {"aaaa", "aaaa", "aaaa"};

	TEST(CreatePlayer, CreatePlayer)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
	}
}