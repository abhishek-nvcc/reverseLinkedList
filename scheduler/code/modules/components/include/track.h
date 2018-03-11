#ifndef TRACK_H
#define TRACK_H

#include <vector>

class session;
class vector;

class track
{
public:
	track(const sessionData& morningSession, const sessionData& eveningSession);
	~track();

	bool addTalkToSession(const SESSION session, talk* pTalk);
	void setSessionDetails(const SESSION sessionID, const int duration, const int startTime, const int endTime);

	size_t getNumOfTalksInSession(const SESSION session) const { return(_listOfSessions.at(session)->getNumOfTalks()); };
	std::string getTalkInSessionTitle(const SESSION session, const int idxOfTalkInSession) const;
	int getTalkInSessionDuration(const SESSION session, const int idxOfTalkInSession) const;
	std::string getTalkInSessionDurationUnit(const SESSION session, const int idxOfTalkInSession) const;

private:
	void clearList();
	void initListOfSessions(const sessionData& morningSession, const sessionData& eveningSession);

	std::vector<session*> _listOfSessions;
};

#endif
