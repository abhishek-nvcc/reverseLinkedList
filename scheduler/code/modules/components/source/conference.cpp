#define CONFERENCE_INC
#define GOOGLELOGGER_INC

#include "..\include\dependency.h"

conference::conference(const std::string& inputFileLocation, const sessionData& morningSession, const sessionData& eveningSession)
{
	LOG(INFO) << __FUNCTION__;
	clearTracks();
	clearGlobalListOfTalks();
	try
	{
		initListOfTalks(inputFileLocation);
		initListOfTracks(morningSession, eveningSession);
	}
	catch (std::invalid_argument&)
	{
		clearTracks();
		clearGlobalListOfTalks();
		MessageBox(nullptr, TEXT("ERROR_INVALID_DURATION_TYPE_USED_TO_CREATE_TALK"), TEXT("Message"), MB_OK);
		ExitProcess(WM_CLOSE);
	}
}

conference::~conference()
{
	LOG(INFO) << __FUNCTION__;
	clearTracks();
	clearGlobalListOfTalks();
}

void conference::clearGlobalListOfTalks()
{
	LOG(INFO) << __FUNCTION__;
	if (0 < _globalListOfTalks.size())
	{
		std::vector<talk*>::iterator iter = _globalListOfTalks.begin();
		std::vector<talk*>::iterator endIter = _globalListOfTalks.end();

		for (; iter != endIter; ++iter)
		{
			delete(*(iter));
			*(iter) = nullptr;
		}

		_globalListOfTalks.clear();
	}
}

void conference::clearTracks()
{
	LOG(INFO) << __FUNCTION__;
	if (0 < _listOfTracks.size())
	{
		if (nullptr != _listOfTracks.at(TRACK::FIRST_TRACK))
		{
			delete(_listOfTracks.at(TRACK::FIRST_TRACK));
			_listOfTracks.at(TRACK::FIRST_TRACK) = nullptr;
		}
		if (nullptr != _listOfTracks.at(TRACK::SECOND_TRACK))
		{
			delete(_listOfTracks.at(TRACK::SECOND_TRACK));
			_listOfTracks.at(TRACK::SECOND_TRACK) = nullptr;
		}
	}

	_listOfTracks.clear();
}

void conference::initListOfTracks(const sessionData& morningSession, const sessionData& eveningSession)
{
	LOG(INFO) << __FUNCTION__;
	track* pTrack_01 = new track(morningSession, eveningSession);
	track* pTrack_02 = new track(morningSession, eveningSession);
	assert(nullptr != pTrack_01 && nullptr != pTrack_02);
	_listOfTracks.push_back(pTrack_01);
	_listOfTracks.push_back(pTrack_02);

	std::vector<talk*>::iterator iter = _globalListOfTalks.begin();
	std::vector<talk*>::iterator endIter = _globalListOfTalks.end();

	bool bTalkAddedSuccessfully = false;

	for (; iter != endIter; ++iter)
	{
		talk* pTalkToAdd = *(iter);
		bTalkAddedSuccessfully = _listOfTracks.at(TRACK::FIRST_TRACK)->addTalkToSession(SESSION::MORNING_SESSION, pTalkToAdd);
		if (!bTalkAddedSuccessfully)
		{
			bTalkAddedSuccessfully = _listOfTracks.at(TRACK::FIRST_TRACK)->addTalkToSession(SESSION::EVENING_SESSION, pTalkToAdd);
			if (!bTalkAddedSuccessfully)
			{
				bTalkAddedSuccessfully = _listOfTracks.at(TRACK::SECOND_TRACK)->addTalkToSession(SESSION::MORNING_SESSION, pTalkToAdd);
				if (!bTalkAddedSuccessfully)
					bTalkAddedSuccessfully = _listOfTracks.at(TRACK::SECOND_TRACK)->addTalkToSession(SESSION::EVENING_SESSION, pTalkToAdd);
			}
		}

		assert(bTalkAddedSuccessfully);
	}
}

void conference::initListOfTalks(const std::string& inputFileLocation)
{
	LOG(INFO) << __FUNCTION__;
	std::ifstream inputFileStream(inputFileLocation);
	std::string lineStr;
	int lineCount = 0;
	std::vector<int> listOfTalkDurations;
	while (std::getline(inputFileStream, lineStr))
	{
		std::istringstream lineStrStream(lineStr);
		int lineItemCount = 0, talkDuration = 0;
		std::string talkTitle, talkDurationUnit;
		while (lineStrStream)
		{
			std::string lineItem;
			if (!getline(lineStrStream, lineItem, ',')) break;
			switch (lineItemCount)
			{
			case INPUTLINE_DATA_ITEMS::TALK_TITLE:
				talkTitle = lineItem;
				break;
			case INPUTLINE_DATA_ITEMS::TALK_DURATION:
				talkDuration = std::stoi(lineItem);
				break;
			case INPUTLINE_DATA_ITEMS::TALK_DURATION_UNIT:
			{
				int error_01 = strcmp(lineItem.c_str(), TALK_DURATION_UNIT_MINUTES);
				int error_02 = strcmp(lineItem.c_str(), TALK_DURATION_UNIT_LIGHTNING);
				if (0 == error_01 || 0 == error_02)
				{
					talkDurationUnit = lineItem;
				}
				else
				{
					throw(ERROR_INVALID_DURATION_TYPE_USED_TO_CREATE_TALK);
				}
				break;
			}
			default:
				assert(0);
				break;
			}
			++lineItemCount;
		}
		int strCmpErr = strcmp(talkDurationUnit.c_str(), TALK_DURATION_UNIT_LIGHTNING);
		int talkDurationMultiplier = ((0 == strCmpErr) ? LIGHTNING_TO_MINUTES_CONVERTER : 1);
		int idxToAddTalk = findIdxToAddItemToMaintainDescendingOrder(listOfTalkDurations, talkDuration*talkDurationMultiplier);
		talk* pTalk = new talk(talkTitle, talkDuration, talkDuration*talkDurationMultiplier, talkDurationUnit);
		if (nullptr != pTalk)
		{
			size_t currNumOfTalks = _globalListOfTalks.size();
			if (0 == currNumOfTalks || idxToAddTalk == currNumOfTalks)
			{
				_globalListOfTalks.push_back(pTalk);
				listOfTalkDurations.push_back(talkDuration*talkDurationMultiplier);
			}
			else
			{
				_globalListOfTalks.insert(_globalListOfTalks.begin() + idxToAddTalk, pTalk);
				listOfTalkDurations.insert(listOfTalkDurations.begin() + idxToAddTalk, talkDuration*talkDurationMultiplier);
			}
		}
		++lineCount;
	}
}

void conference::writeToFile(const std::string& outputFileLocation)
{
	LOG(INFO) << __FUNCTION__;

	std::ofstream outputFileStream(outputFileLocation);

	writeSession(outputFileStream, _listOfTracks.at(TRACK::FIRST_TRACK), SESSION::MORNING_SESSION,
		MORNING_SESSION_START_TIME_HOUR, MORNING_SESSION_START_TIME_MIN, ANTE_MERIDIEM_STRING, FIRST_TRACK_MORNING_SESSION_STRING, 
		LUNCH_TIME_AND_TITLE_STRING);

	writeSession(outputFileStream, _listOfTracks.at(TRACK::FIRST_TRACK), SESSION::EVENING_SESSION,
		EVENING_SESSION_START_TIME_HOUR, EVENING_SESSION_START_TIME_MIN, POST_MERIDIEM_STRING, FIRST_TRACK_EVENING_SESSION_STRING,
		NETWORKING_EVENT_TIME_AND_TITLE_STRING);

	writeSession(outputFileStream, _listOfTracks.at(TRACK::SECOND_TRACK), SESSION::MORNING_SESSION,
		MORNING_SESSION_START_TIME_HOUR, MORNING_SESSION_START_TIME_MIN, ANTE_MERIDIEM_STRING, SECOND_TRACK_MORNING_SESSION_STRING,
		LUNCH_TIME_AND_TITLE_STRING);

	writeSession(outputFileStream, _listOfTracks.at(TRACK::SECOND_TRACK), SESSION::EVENING_SESSION,
		EVENING_SESSION_START_TIME_HOUR, EVENING_SESSION_START_TIME_MIN, POST_MERIDIEM_STRING, SECOND_TRACK_EVENING_SESSION_STRING,
		NETWORKING_EVENT_TIME_AND_TITLE_STRING);
}
