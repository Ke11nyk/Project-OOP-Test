#include "pch.h"
#include "..//Project OOP/source/headers/Animator.h"

namespace AnimatorTest
{
	TEST(CreateAnimation, CreateAnimation)
	{
		sf::Sprite SStickSprite; ///< Sprite of the player
		Animator StickAnim = Animator(SStickSprite);  ///< Animation of the player
		sf::String StrTexture = "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png"; ///< Texture of the player
		sf::Vector2i iSpriteSize = sf::Vector2i(54, 60);
 
		auto& idleForwardStatic = StickAnim.CreateAnimation("idleForwardStatic", StrTexture, sf::seconds(0.5), true);
		idleForwardStatic.AddFrames(sf::Vector2i(0, 0), iSpriteSize, 1, 1);
	}

	TEST(SwitchAnimation, SwitchAnimation)
	{
		sf::Sprite SStickSprite; ///< Sprite of the player
		Animator StickAnim = Animator(SStickSprite);  ///< Animation of the player
		sf::String StrTexture = "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png"; ///< Texture of the player

		StickAnim.CreateAnimation("idleForwardStatic", StrTexture, sf::seconds(0.5), true);

		ASSERT_EQ(StickAnim.SwitchAnimation("idleBack"), false);
		ASSERT_EQ(StickAnim.SwitchAnimation("idleForwardStatic"), true);
	}

	TEST(GetCurrentAnimationName, GetCurrentAnimationName)
	{
		sf::Sprite SStickSprite; ///< Sprite of the player
		Animator StickAnim = Animator(SStickSprite);  ///< Animation of the player
		sf::String StrTexture = "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png"; ///< Texture of the player

		ASSERT_EQ(StickAnim.GetCurrentAnimationName(), "");

		StickAnim.CreateAnimation("idleForwardStatic", StrTexture, sf::seconds(0.5), true);
		StickAnim.CreateAnimation("idleForward", StrTexture, sf::seconds(0.5), true);

		ASSERT_EQ(StickAnim.GetCurrentAnimationName(), "idleForwardStatic");

		StickAnim.SwitchAnimation("idleForward");

		ASSERT_EQ(StickAnim.GetCurrentAnimationName(), "idleForward");
	}

	TEST(UpdateAndRestart, UpdateAndRestart)
	{
		sf::Sprite SStickSprite; ///< Sprite of the player
		Animator StickAnim = Animator(SStickSprite);  ///< Animation of the player
		sf::String StrTexture = "D:/Uni materials/2 course/OOP/Project OOP/source/images/figure.png"; ///< Texture of the player
		float fTime = 0.5;
		sf::Vector2i iSpriteSize = sf::Vector2i(54, 60);

		auto& idleForwardStatic = StickAnim.CreateAnimation("idleForwardStatic", StrTexture, sf::seconds(fTime), false);
		idleForwardStatic.AddFrames(sf::Vector2i(0, 0), iSpriteSize, 1, 1);

		ASSERT_EQ(StickAnim.getEndAnim(), false);

		StickAnim.Update(sf::seconds(fTime));

		ASSERT_EQ(StickAnim.getEndAnim(), true);

		StickAnim.Restart();
		
		ASSERT_EQ(StickAnim.getEndAnim(), false);
	}
}