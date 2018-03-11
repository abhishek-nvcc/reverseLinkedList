#define TALK_INC
#define GOOGLELOGGER_INC

#include "..\include\dependency.h"

talk::talk(const std::string& title, const int duration, const int durationInMin, const std::string& durationUnit)
{
	LOG(INFO) << __FUNCTION__;
	_title = title;
	_durationUnit = durationUnit;
	_duration = duration;
	_durationInMin = durationInMin;
}

talk::~talk()
{
	LOG(INFO) << __FUNCTION__;
}
