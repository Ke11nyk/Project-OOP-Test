#include "pch.h"
#include "..//Project OOP/source/headers/Animator.h"

namespace AnimatorTest
{
	TEST(OnlyOneAssetManager, OnlyOneAssetManager)
	{
		sf::Sprite SStickSprite; ///< Sprite of the player
		Animator StickAnim = Animator(SStickSprite);  ///< Animation of the player
		sf::String StrTexture; ///< Texture of the player
		float fTime = 0.5;
		sf::Vector2i iSpriteSize = sf::Vector2i(54, 60);

		//auto& idleForwardStatic = StickAnim.CreateAnimation("idleForwardStatic", StrTexture, sf::seconds(fTime), true);
		//idleForwardStatic.AddFrames(sf::Vector2i(0, 0), iSpriteSize, 1, 1);
	}
}