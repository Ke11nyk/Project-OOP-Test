#include "pch.h"
#include "..//Project OOP/source/headers/Player.h"

namespace PlayerTest
{
	AssetManager a;
	sf::RenderWindow WWin;
	std::vector<sf::String> vecTileMap = {"aaaa", "aaaa", "aaaa"};

	TEST(Name2, Name2)
	{
		Player stick = Player(WWin, vecTileMap, "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png", 3);
	}
}