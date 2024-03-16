#include "pch.h"
#include "..//Project OOP/source/headers/AssetManager.h"

namespace AssetManagerTest
{
	TEST(OnlyOneAssetManager, OnlyOneAssetManager)
	{
		//AssetManager a;
		//ASSERT_DEATH(AssetManager b, "stcInstance == nullptr");
	}
	
	TEST(GetFiles, GetTexture) 
	{
		AssetManager::GetTexture("../Project OOP/source/images/plat.png");
	}
}