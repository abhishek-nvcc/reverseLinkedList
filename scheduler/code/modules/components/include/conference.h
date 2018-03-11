#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <vector>

class talk;
class track;
class vector;

class conference
{
public:
	conference(const std::string& inputFileLocation, const sessionData& morningSession, const sessionData& eveningSession);
	~conference();

	size_t totalNumOfTalks() const { return _globalListOfTalks.size(); };

	size_t getNumOfTalksInSession(const TRACK track, const SESSION session) const 
	{ return(_listOfTracks.at(track)->getNumOfTalksInSession(session)); };

	void writeToFile(const std::string& outputFileLocation);

private:
	void initListOfTalks(const std::string& inputFileLocation);
	void initListOfTracks(const sessionData& morningSession, const sessionData& eveningSession);
	void clearTracks();
	void clearGlobalListOfTalks();

	std::vector<talk*> _globalListOfTalks;
	std::vector<track*> _listOfTracks;
};

#endif
