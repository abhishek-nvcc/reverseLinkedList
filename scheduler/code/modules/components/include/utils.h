#ifndef UTILS_H
#define UTILS_H

int findIdxToAddItemToMaintainDescendingOrder(std::vector<int>& listOfTalkDurations, const int talkDuration);
void writeSession(std::ofstream& outputFileStream, const track* pTrack, const SESSION sessionID, 
	int startTimeHour, int startTimeMin, std::string startTimeMeridiemString, std::string headerString, std::string footerString);

#endif
