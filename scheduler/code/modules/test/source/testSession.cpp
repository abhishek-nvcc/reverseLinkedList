#define CATCH_INC
#define SESSION_INC
#define TALK_INC

#include "dependency.h"
#include "..\include\testCommonDefinitions.h"

#define TOTAL_DURATION_OF_SESSION_01 (120)

#ifdef RUN_SESSION_TESTS
SCENARIO("Create session and test adding of talk items")
{
	sessionData sessionDataObj;

	sessionDataObj.durationLeft = TOTAL_DURATION_OF_SESSION_01;
	sessionDataObj.startTime = MORNING_SESSION_START_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_START_TIME_MIN;
	sessionDataObj.endTime = MORNING_SESSION_END_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_END_TIME_MIN;

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("talk is created whose length is less than the duration of the session")
		{
			talk* pTalk = new talk("Learn how to write tests", 40, 40, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk);
			THEN("talk should be added successfully only once")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk);
				REQUIRE(false == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("talk is created whose length is less than the duration of the session")
		{
			talk* pTalk = new talk("Learn how to write tests", 40, 40, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk);
			THEN("talk should be added successfully")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("talk is created whose length is equal to the duration of the session")
		{
			talk* pTalk = new talk("Learn how to write tests", TOTAL_DURATION_OF_SESSION_01, TOTAL_DURATION_OF_SESSION_01, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk);
			THEN("talk should be added successfully")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("talk is created whose length is greater than the duration of the session")
		{
			talk* pTalk = new talk("Learn how to write tests", 140, 140, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk);
			THEN("talk should not be added successfully")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk);
				REQUIRE(false == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is less than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 20, 20, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 90, 90, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			THEN("all the talks should be added successfully")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is equal to the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 20, 20, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 90, 20, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 10, 10, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("all the talks should be added successfully")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is greater than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 20, 20, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 90, 90, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 40, 40, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("the first 2 talks would get added, and the last one will not get added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(false == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is greater than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 90, 90, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 60, 60, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 30, 30, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("the first talks would get added, and the last 2 will not get added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is greater than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 140, 140, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 60, 60, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 30, 30, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("the first talks would get added, and the last 2 will not get added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is greater than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 150, 150, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 140, 150, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 40, 150, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("the first talks would get added, and the last 2 will not get added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is greater than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 150, 150, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 90, 90, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 40, 40, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("the first talks would get added, and the last 2 will not get added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(false == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is greater than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 100, 100, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 90, 90, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 30, 30, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("the first talks would get added, and the last 2 will not get added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(false == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("a couple of talks are created the sum of whose length is greater than the duration of the session")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 150, 150, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 190, 190, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_03 = new talk("Learn how to write tests", 140, 140, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			REQUIRE(nullptr != pTalk_03);
			THEN("the first talks would get added, and the last 2 will not get added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(false == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_03);
				REQUIRE(false == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("create talk whose length is in minute, and another whose length is in lightning")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 40, 40, TALK_DURATION_UNIT_MINUTES);
			talk* pTalk_02 = new talk("Learn how to write tests", 12, 60, TALK_DURATION_UNIT_LIGHTNING);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			THEN("talks should be added successfully")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(true == bTalkAddedSuccessfully);
			}
		}
	}

	GIVEN("A session object")
	{
		session* pSession = new session(sessionDataObj);
		REQUIRE(nullptr != pSession);
		WHEN("create talk whose length is in minute, and another whose length is in lightning")
		{
			talk* pTalk_01 = new talk("Learn how to write tests", 20, 100, TALK_DURATION_UNIT_LIGHTNING);
			talk* pTalk_02 = new talk("Learn how to write tests", 40, 40, TALK_DURATION_UNIT_MINUTES);
			REQUIRE(nullptr != pTalk_01);
			REQUIRE(nullptr != pTalk_02);
			THEN("second talk will not be added")
			{
				bool bTalkAddedSuccessfully = pSession->addTalk(pTalk_01);
				REQUIRE(true == bTalkAddedSuccessfully);
				bTalkAddedSuccessfully = pSession->addTalk(pTalk_02);
				REQUIRE(false == bTalkAddedSuccessfully);
			}
		}
	}
}
#endif
