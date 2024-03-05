#include "pch.h"
#include "..//Project OOP/source/headers/SettingsValues.h"

namespace SettingsValuesTest
{
	TEST(DefaultValues, DefaultValues)
	{
		SettingsValues settings;

		EXPECT_EQ(settings.getLanguage(), 0);
		EXPECT_EQ(settings.getSkin(), 0);
		EXPECT_EQ(settings.getWidth(), 1920);
		EXPECT_EQ(settings.getHeight(), 1080);
		EXPECT_EQ(settings.getSettingTitle(), 573);
		EXPECT_EQ(settings.getTitle(), 469.5);
		EXPECT_EQ(settings.getFullscreen(), 0);
	}

	TEST(SetValues, Language)
	{
		SettingsValues settings;

		settings.setLanguage(1);

		EXPECT_EQ(settings.getLanguage(), 1);
	}

	TEST(SetValues, Skin)
	{
		SettingsValues settings;

		settings.setSkin(1);

		EXPECT_EQ(settings.getSkin(), 1);
	}

	TEST(SetValues, Width)
	{
		SettingsValues settings;

		settings.setWidth(1280);

		EXPECT_EQ(settings.getWidth(), 1280);
	}

	TEST(SetValues, Height)
	{
		SettingsValues settings;

		settings.setHeight(970);

		EXPECT_EQ(settings.getHeight(), 970);
	}

	TEST(SetValues, SettingTitle)
	{
		SettingsValues settings;

		settings.setSettingTitle(600);

		EXPECT_EQ(settings.getSettingTitle(), 600);
	}

	TEST(SetValues, Title)
	{
		SettingsValues settings;

		settings.setTitle(600);

		EXPECT_EQ(settings.getTitle(), 600);
	}

	TEST(SetValues, Fullscreen)
	{
		SettingsValues settings;

		settings.setFullscreen(true);

		EXPECT_EQ(settings.getFullscreen(), 1);
	}
}