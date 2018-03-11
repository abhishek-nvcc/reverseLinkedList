#ifndef TALK_H
#define TALK_H

class talk
{
public:
	talk(const std::string& title, const int duration, const int durationInMin, const std::string& durationUnit);
	~talk();

	int getDuration() const { return (_duration); };
	int getDurationInMin() const { return (_durationInMin); };
	std::string& getDurationUnit() { return (_durationUnit); };
	std::string& getTitle() { return (_title); };

private:
	std::string _title;
	int _duration;
	int _durationInMin;
	std::string _durationUnit;
};

#endif
