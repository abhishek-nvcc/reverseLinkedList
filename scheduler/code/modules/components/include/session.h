#ifndef SESSION_H
#define SESSION_H

#include <vector>

class talk;
class vector;

struct sessionData
{
	int durationLeft = 0;
	int startTime = 0;
	int endTime = 0;
};

class session
{
public:
	session(const sessionData& sessionData);
	~session();

	bool addTalk(talk* pTalk);

	size_t getNumOfTalks() const{ return(_listOfTalks.size()); };
	std::string getTalkTitle(const int idxOfTalk);
	int getTalkDuration(const int idxOfTalk);
	std::string getTalkDurationUnit(const int idxOfTalk);

private:
	void clearList();

	std::vector<talk*> _listOfTalks;
	sessionData _sessionData;
};

#endif
