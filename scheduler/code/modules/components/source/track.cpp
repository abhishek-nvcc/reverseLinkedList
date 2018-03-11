#define TRACK_INC
#define GOOGLELOGGER_INC

#include "..\include\dependency.h"

track::track(const sessionData& morningSessionData, const sessionData& eveningSessionData)
{
	LOG(INFO) << __FUNCTION__;
	clearList();
	initListOfSessions(morningSessionData, eveningSessionData);
}

track::~track()
{
	LOG(INFO) << __FUNCTION__;
	clearList();
}

void track::initListOfSessions(const sessionData& morningSessionData, const sessionData& eveningSessionData)
{
	LOG(INFO) << __FUNCTION__;
	session* pSession_01 = new session(morningSessionData);
	session* pSession_02 = new session(eveningSessionData);
	assert(nullptr != pSession_01 && nullptr != pSession_02);
	_listOfSessions.push_back(pSession_01);
	_listOfSessions.push_back(pSession_02);
}

void track::clearList()
{
	LOG(INFO) << __FUNCTION__;
	if (0 < _listOfSessions.size())
	{
		if (nullptr != _listOfSessions.at(SESSION::MORNING_SESSION))
		{
			delete(_listOfSessions.at(SESSION::MORNING_SESSION));
			_listOfSessions.at(SESSION::MORNING_SESSION) = nullptr;
		}
		if (nullptr != _listOfSessions.at(SESSION::EVENING_SESSION))
		{
			delete(_listOfSessions.at(SESSION::EVENING_SESSION));
			_listOfSessions.at(SESSION::EVENING_SESSION) = nullptr;
		}
	}

	_listOfSessions.clear();
}

bool track::addTalkToSession(const SESSION session, talk* pTalk)
{
	bool bTalkAddedSuccessfully = false;
	switch (session)
	{
	case SESSION::MORNING_SESSION:
		bTalkAddedSuccessfully = _listOfSessions.at(SESSION::MORNING_SESSION)->addTalk(pTalk);
		break;
	case SESSION::EVENING_SESSION:
		bTalkAddedSuccessfully = _listOfSessions.at(SESSION::EVENING_SESSION)->addTalk(pTalk);
		break;
	}

	return(bTalkAddedSuccessfully);
}

std::string track::getTalkInSessionTitle(const SESSION session, const int idxOfTalkInSession) const
{
	return(_listOfSessions.at(session)->getTalkTitle(idxOfTalkInSession));
}

int track::getTalkInSessionDuration(const SESSION session, const int idxOfTalkInSession) const
{
	return(_listOfSessions.at(session)->getTalkDuration(idxOfTalkInSession));
}

std::string track::getTalkInSessionDurationUnit(const SESSION session, const int idxOfTalkInSession) const
{
	return(_listOfSessions.at(session)->getTalkDurationUnit(idxOfTalkInSession));
}
