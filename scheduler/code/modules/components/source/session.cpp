#define SESSION_INC
#define GOOGLELOGGER_INC

#include "..\include\dependency.h"

session::session(const sessionData& sessionData)
{
	LOG(INFO) << __FUNCTION__;
	clearList();
	_sessionData = sessionData;
}

session::~session()
{
	LOG(INFO) << __FUNCTION__;
	clearList();
}

void session::clearList()
{
	LOG(INFO) << __FUNCTION__;
	_listOfTalks.clear();
}

bool session::addTalk(talk* pTalk)
{
	bool bTalkAddedSuccessfully = false;
	assert(nullptr != pTalk);
	if (pTalk->getDuration() <= _sessionData.durationLeft)
	{
		std::vector<talk*>::iterator endIter = _listOfTalks.end();
		std::vector<talk*>::iterator iter = std::find(_listOfTalks.begin(), _listOfTalks.end(), pTalk);
		if (iter == endIter)
		{
			_listOfTalks.push_back(pTalk);
			_sessionData.durationLeft -= pTalk->getDurationInMin();
			bTalkAddedSuccessfully = true;
		}
	}

	return bTalkAddedSuccessfully;
}

std::string session::getTalkTitle(const int idxOfTalk)
{
	return(_listOfTalks.at(idxOfTalk)->getTitle());
}

std::string session::getTalkDurationUnit(const int idxOfTalk)
{
	return(_listOfTalks.at(idxOfTalk)->getDurationUnit());
}

int session::getTalkDuration(const int idxOfTalk)
{
	return(_listOfTalks.at(idxOfTalk)->getDuration());
}
