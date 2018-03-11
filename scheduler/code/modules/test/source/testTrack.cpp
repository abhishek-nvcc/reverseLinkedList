#define CATCH_INC

#define TALK_INC
#define TRACK_INC

#include "dependency.h"
#include "..\include\testCommonDefinitions.h"

#define NUM_OF_TALKS_IN_TRACK_WITHOUT_ADDING_ANY_TALK (0)
#define DURATION_MORNING_SESSION_01 (300)
#define DURATION_EVENING_SESSION_01 (200)
#define NUM_OF_TALKS_ADDED_IS_SEVEN (7)
#define NUM_OF_TALKS_ADDED_IS_ZERO (0)
#define NUM_OF_TALKS_ADDED_IS_FOUR (4)

#ifdef RUN_TRACK_TESTS
SCENARIO("test creation of a track object")
{
	sessionData mrngSession, evngSession;

	mrngSession.durationLeft = DURATION_MORNING_SESSION_01;
	mrngSession.startTime = MORNING_SESSION_START_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_START_TIME_MIN;
	mrngSession.endTime = MORNING_SESSION_END_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_END_TIME_MIN;

	evngSession.durationLeft = DURATION_EVENING_SESSION_01;
	evngSession.startTime = EVENING_SESSION_START_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + EVENING_SESSION_START_TIME_MIN;
	evngSession.endTime = EVENING_SESSION_END_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + EVENING_SESSION_END_TIME_MIN;

	GIVEN("a track")
	{
		track* pTrack = new track(mrngSession, evngSession);
		WHEN("do not add any talks to any session of the track")
		{
			THEN("check the number of talks in any session is 0")
			{
				REQUIRE(NUM_OF_TALKS_IN_TRACK_WITHOUT_ADDING_ANY_TALK == pTrack->getNumOfTalksInSession(SESSION::MORNING_SESSION));
				REQUIRE(NUM_OF_TALKS_IN_TRACK_WITHOUT_ADDING_ANY_TALK == pTrack->getNumOfTalksInSession(SESSION::EVENING_SESSION));
			}
		}
	}

	GIVEN("a track")
	{
		track* pTrack = new track(mrngSession, evngSession);
		WHEN("add talks to only to morning session of the track")
		{
			talk* pTalk_00 = new talk("learn how to read sanskrit", 12, 12 * LIGHTNING_TO_MINUTES_CONVERTER, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_01 = new talk("learn how to read hindi", 45, 45, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("learn how to read marathi", 80, 80, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("learn how to read bengali", 5, 5, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_04 = new talk("learn how to read malayali", 12, 12, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_05 = new talk("learn how to read punjabi", 45, 45, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_06 = new talk("learn how to read sindhi", 10, 10, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_07 = new talk("learn how to read kanada", 5, 5, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_08 = new talk("learn how to read tamil", 200, 200, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_09 = new talk("learn how to read telugu", 250, 250, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_10 = new talk("learn how to read tamil", 12, 10, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_11 = new talk("learn how to read telugu", 10, 10, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_12 = new talk("learn how to read telugu", 55, 5, TALK_DURATION_UNIT_MINUTES);
			
			bool bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::MORNING_SESSION, pTalk_00);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_01);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_02);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_03);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_04);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::MORNING_SESSION, pTalk_05);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_06);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_07);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_08);
			REQUIRE(false == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::MORNING_SESSION, pTalk_09);
			REQUIRE(false == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::EVENING_SESSION, pTalk_10);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::MORNING_SESSION, pTalk_11);
			REQUIRE(true == bTalkAddedSuccessfully);
			bTalkAddedSuccessfully = pTrack->addTalkToSession(SESSION::MORNING_SESSION, pTalk_12);
			REQUIRE(true == bTalkAddedSuccessfully);

			THEN("check the number of talks in morning session is non-zero, and evening track is 0")
			{
				REQUIRE(NUM_OF_TALKS_ADDED_IS_FOUR == pTrack->getNumOfTalksInSession(SESSION::MORNING_SESSION));
				REQUIRE(NUM_OF_TALKS_ADDED_IS_SEVEN == pTrack->getNumOfTalksInSession(SESSION::EVENING_SESSION));
			}
		}
	}
}
#endif
