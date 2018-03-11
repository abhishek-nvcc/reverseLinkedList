#define UTILS_INC
#define GOOGLELOGGER_INC

#include "..\include\dependency.h"

int findIdxToAddItemToMaintainDescendingOrder(std::vector<int>& listOfTalkDurations, const int talkDuration)
{
	LOG(INFO) << __FUNCTION__;
	int idx = 0;
	size_t currentSize = listOfTalkDurations.size();
	if (0 < currentSize)
	{
		if (talkDuration > listOfTalkDurations.at(0))
		{
			idx = 0;
		}
		else if (talkDuration < listOfTalkDurations.at(currentSize - 1))
		{
			idx = currentSize;
		}
		else
		{
			std::vector<int>::iterator iter = listOfTalkDurations.begin();
			std::vector<int>::iterator iterEnd = listOfTalkDurations.end();
			for (; iter != iterEnd; ++iter, ++idx)
			{
				if ((iter + 1) != iterEnd)
				{
					if (talkDuration == *(iter))
					{
						break;
					}
					else if ((talkDuration < *(iter)) && (talkDuration >= *(iter + 1)))
					{
						++idx;
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	return idx;
}

void writeSession(std::ofstream& outputFileStream, const track* pTrack, const SESSION sessionID,
	int startTimeHour, int startTimeMin, std::string startTimeMeridiemString, std::string headerString, std::string footerString)
{
	outputFileStream << headerString << std::endl;
	size_t numOfTalksInSession = pTrack->getNumOfTalksInSession(sessionID);
	int absStartTime = startTimeHour * HOUR_TO_MINUTE_CONVERTER + startTimeMin;
	int startTimeHourTemp = startTimeHour - ((12 < startTimeHour) ? 12 : 0);
	std::string startTimeHourString = std::to_string(startTimeHourTemp);
	std::string appendToStartTimeMin = ((10 > startTimeMin) ? "0" : "");
	std::string startTimeMinString = appendToStartTimeMin + std::to_string(startTimeMin);
	for (size_t idxOfTalk = 0; idxOfTalk < numOfTalksInSession; ++idxOfTalk)
	{
		std::string talkTitle = pTrack->getTalkInSessionTitle(sessionID, idxOfTalk);
		int talkDuration = pTrack->getTalkInSessionDuration(sessionID, idxOfTalk);
		std::string talkDurationType = pTrack->getTalkInSessionDurationUnit(sessionID, idxOfTalk);
		outputFileStream << startTimeHourString << ":" << startTimeMinString <<
			" " << startTimeMeridiemString << " " << talkTitle << " " << talkDuration << " " << talkDurationType << std::endl;
		int strCmpErr = strcmp(talkDurationType.c_str(), TALK_DURATION_UNIT_LIGHTNING);
		int talkDurationMultiplier = ((0 == strCmpErr) ? LIGHTNING_TO_MINUTES_CONVERTER : 1);
		absStartTime += talkDuration * talkDurationMultiplier;
		startTimeHour = absStartTime / HOUR_TO_MINUTE_CONVERTER;
		startTimeMeridiemString = ((12 <= startTimeHour) ? POST_MERIDIEM_STRING : ANTE_MERIDIEM_STRING);
		startTimeMin = absStartTime - startTimeHour * HOUR_TO_MINUTE_CONVERTER;
		startTimeHourTemp = startTimeHour - ((12 < startTimeHour) ? 12 : 0);
		startTimeHourString = std::to_string(startTimeHourTemp);
		appendToStartTimeMin = ((10 > startTimeMin) ? "0" : "");
		startTimeMinString = appendToStartTimeMin + std::to_string(startTimeMin);
	}
	outputFileStream << footerString << std::endl;
	outputFileStream << std::endl;
}
