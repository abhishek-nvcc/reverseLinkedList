#define CATCH_INC

#define TALK_INC

#include "dependency.h"
#include "..\include\testCommonDefinitions.h"

#define TALK_DURATION  (120)

#ifdef RUN_TALK_TESTS
SCENARIO("test creation of a talk object")
{
	GIVEN("title, duration, and type of duration")
	{
		std::string title = "Let us learn how to write tests";
		std::string durationType = TALK_DURATION_UNIT_MINUTES;
		int duration = TALK_DURATION;
		WHEN("talk object is created")
		{
			int strCmpErr = strcmp(durationType.c_str(), TALK_DURATION_UNIT_LIGHTNING);
			int talkDurationMultiplier = ((0 == strCmpErr) ? LIGHTNING_TO_MINUTES_CONVERTER : 1);
			talk* pTalk = new talk(title, duration, duration*talkDurationMultiplier, durationType);
			THEN("talk object should be created successfully")
			{
				REQUIRE(nullptr != pTalk);
				REQUIRE(TALK_DURATION == pTalk->getDuration());
				REQUIRE(TALK_DURATION_UNIT_MINUTES == pTalk->getDurationUnit());
			}
		}
	}
	
	GIVEN("title, duration, and type of duration")
	{
		std::string title = "Let us learn how to write tests";
		std::string durationType = TALK_DURATION_UNIT_LIGHTNING;
		int duration = TALK_DURATION;
		WHEN("talk object is created")
		{
			int strCmpErr = strcmp(durationType.c_str(), TALK_DURATION_UNIT_LIGHTNING);
			int talkDurationMultiplier = ((0 == strCmpErr) ? LIGHTNING_TO_MINUTES_CONVERTER : 1);
			talk* pTalk = new talk(title, duration, duration*talkDurationMultiplier, durationType);
			THEN("talk object should be created successfully")
			{
				REQUIRE(nullptr != pTalk);
				REQUIRE(TALK_DURATION == pTalk->getDuration());
				REQUIRE(TALK_DURATION_UNIT_LIGHTNING == pTalk->getDurationUnit());
			}
		}
	}
}
#endif
