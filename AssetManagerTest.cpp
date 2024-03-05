#include "pch.h"
#include "..//Project OOP/source/headers/AssetManager.h"

namespace AssetManagerTest
{
	TEST(OnlyOneAssetManager, OnlyOneAssetManager)
	{
		AssetManager a;
		ASSERT_DEATH(AssetManager b, "stcInstance == nullptr");
	}
	
	TEST(GetFiles, GetTexture) 
	{
		//sf::Texture texture, texture1;
		//texture.loadFromFile("..//Project OOP/source/images/plat.png");
		//texture1 = AssetManager::GetTexture("..//Project OOP/source/images/plat.png");
		//
		////EXPECT_EQ(texture.getSize(), texture1.getSize());
		//ASSERT_DEATH(AssetManager::GetTexture("..//Project OOP/source/images/plat.png"), "stcInstance == nullptr");
	}
}