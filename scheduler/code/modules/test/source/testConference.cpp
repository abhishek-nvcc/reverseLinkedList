#define CATCH_CONFIG_MAIN

#define CATCH_INC
#define CONFERENCE_INC

#include "dependency.h"
#include "..\include\testCommonDefinitions.h"

#define NUM_OF_TALK_ITEMS_FOR_INPUTFILE (19)

#define NUM_OF_TALKS_IN_MORNING_SESSION_OF_FIRST_TRACK (3)
#define NUM_OF_TALKS_IN_EVENING_SESSION_OF_FIRST_TRACK (5)
#define NUM_OF_TALKS_IN_MORNING_SESSION_OF_SECOND_TRACK (4)
#define NUM_OF_TALKS_IN_EVENING_SESSION_OF_SECOND_TRACK (7)

#ifdef RUN_CONFERENCE_TESTS
SCENARIO("Read from an input file and populate the conference object", "[conference]")
{
	sessionData mrngSession, evngSession;

	mrngSession.durationLeft = DURATION_MORNING_SESSION;
	mrngSession.startTime = MORNING_SESSION_START_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_START_TIME_MIN;
	mrngSession.endTime = MORNING_SESSION_END_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_END_TIME_MIN;

	evngSession.durationLeft = DURATION_EVENING_SESSION;
	evngSession.startTime = EVENING_SESSION_START_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + EVENING_SESSION_START_TIME_MIN;
	evngSession.endTime = EVENING_SESSION_END_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + EVENING_SESSION_END_TIME_MIN;

	std::string testDataEnvVarName = "TEST_INPUT_FILE";
	size_t sz = 0;
	char* testDataFileName = nullptr;
	errno_t err = _dupenv_s(&testDataFileName, &sz, testDataEnvVarName.c_str());

	conference *pConf = new conference(testDataFileName, mrngSession, evngSession);

	GIVEN("Create a conference object")
	{
		
		size_t numOfTalks = pConf->totalNumOfTalks();

		std::cout << numOfTalks << std::endl;
		REQUIRE(NUM_OF_TALK_ITEMS_FOR_INPUTFILE == numOfTalks);
	}

	GIVEN("Test adding of talks to sessions in tracks")
	{
		WHEN("a conference object is created from input file")
		{
			THEN("check that the conference are initialized properly")
			{
				size_t numOfTalks = pConf->totalNumOfTalks();
				std::cout << numOfTalks << std::endl;
				REQUIRE(NUM_OF_TALK_ITEMS_FOR_INPUTFILE == numOfTalks);

				int numOfTalksInSession_01 = pConf->getNumOfTalksInSession(TRACK::FIRST_TRACK, SESSION::MORNING_SESSION);
				REQUIRE(NUM_OF_TALKS_IN_MORNING_SESSION_OF_FIRST_TRACK == numOfTalksInSession_01);

				int numOfTalksInSession_02 = pConf->getNumOfTalksInSession(TRACK::FIRST_TRACK, SESSION::EVENING_SESSION);
				REQUIRE(NUM_OF_TALKS_IN_EVENING_SESSION_OF_FIRST_TRACK == numOfTalksInSession_02);

				int numOfTalksInSession_03 = pConf->getNumOfTalksInSession(TRACK::SECOND_TRACK, SESSION::MORNING_SESSION);
				REQUIRE(NUM_OF_TALKS_IN_MORNING_SESSION_OF_SECOND_TRACK == numOfTalksInSession_03);

				int numOfTalksInSession_04 = pConf->getNumOfTalksInSession(TRACK::SECOND_TRACK, SESSION::EVENING_SESSION);
				REQUIRE(NUM_OF_TALKS_IN_EVENING_SESSION_OF_SECOND_TRACK == numOfTalksInSession_04);

				REQUIRE((numOfTalksInSession_01 + numOfTalksInSession_02 + numOfTalksInSession_03 + numOfTalksInSession_04) == 
					numOfTalks);
			}
		}
	}

	GIVEN("1) path of file to write to, 2) track, 3) session id, 4) starting time hour, 5) starting time minute, 6) time meridiem string, 7) header string, 8) footer string")
	{
		WHEN("test")
		{
			std::string testOutputFileEnvVarName = "TEST_OUTPUT_FILE";
			size_t sz = 0;
			char* testOutputFileName = nullptr;
			errno_t err = _dupenv_s(&testOutputFileName, &sz, testOutputFileEnvVarName.c_str());
			pConf->writeToFile(testOutputFileName);

			std::string testOutputSampleFileEnvVarName = "TEST_OUTPUT_SAMPLE_FILE";
			sz = 0;
			char* testOutputSampleFileName = nullptr;
			err = _dupenv_s(&testOutputSampleFileName, &sz, testOutputSampleFileEnvVarName.c_str());

			THEN("test")
			{
				std::ifstream outputFileStream(testOutputFileName);
				std::ifstream outputSampleFileStream(testOutputSampleFileName);

				std::cout << testOutputSampleFileName << std::endl;
				std::cout << testOutputFileName << std::endl;

				std::istreambuf_iterator<char> outFileIter(outputFileStream);
				std::istreambuf_iterator<char> sampleOutFileIter(outputSampleFileStream);

				std::istreambuf_iterator<char> endIter;

				bool bFilesIdentical = false;

				while (outFileIter != endIter && sampleOutFileIter != endIter)
				{
					if (*outFileIter != *sampleOutFileIter)
					{
						bFilesIdentical = false;
						break;
					}
					++outFileIter;
					++sampleOutFileIter;
				}
				bFilesIdentical = ((outFileIter == endIter) && (sampleOutFileIter == endIter));

				REQUIRE(true == bFilesIdentical);
			}
		}
	}
}
#endif
