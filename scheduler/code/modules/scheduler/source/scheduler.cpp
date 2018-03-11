/*
From: http://rpg.ifi.uzh.ch/docs/glog.html

Unless otherwise specified, glog writes to the filename
"/tmp/<program name>.<hostname>.<user name>.log.<severity level>.<date>.<time>.<pid>"
(e.g., "/tmp/hello_world.example.com.hamaji.log.INFO.20080709-222411.10474").
By default, glog copies the log messages of severity level ERROR or FATAL to standard error (stderr) in addition to log files.
*/

#define GOOGLELOGGER_INC
#define CONFERENCE_INC

#include "dependency.h"

int main()
{
	std::string logEnabledEnvVar = "SCHEDULER_APP_LOGGING_ENABLED";
	char* pLogEnabledEnvVarValue = nullptr;
	size_t sz = 0;
	errno_t err = _dupenv_s(&pLogEnabledEnvVarValue, &sz, logEnabledEnvVar.c_str());
	if (0 == err && nullptr != pLogEnabledEnvVarValue && 0 == strcmp(pLogEnabledEnvVarValue, "1"))
	{
		google::InitGoogleLogging("Scheduler Logger initialization");
	}

	std::string inputDataFileEnvVarName = "SCHEDULER_APP_INPUT_DATA_FILE_PATH";
	sz = 0;
	char* inputDataFileName = nullptr;
	err = _dupenv_s(&inputDataFileName, &sz, inputDataFileEnvVarName.c_str());
	sessionData mrngSession, evngSession;

	mrngSession.durationLeft = DURATION_MORNING_SESSION;
	mrngSession.startTime = MORNING_SESSION_START_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_START_TIME_MIN;
	mrngSession.endTime = MORNING_SESSION_END_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + MORNING_SESSION_END_TIME_MIN;

	evngSession.durationLeft = DURATION_EVENING_SESSION;
	evngSession.startTime = EVENING_SESSION_START_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + EVENING_SESSION_START_TIME_MIN;
	evngSession.endTime = EVENING_SESSION_END_TIME_HOUR * HOUR_TO_MINUTE_CONVERTER + EVENING_SESSION_END_TIME_MIN;

	conference *pConf = new conference(inputDataFileName, mrngSession, evngSession);

	std::string outputFileEnvVarName = "SCHEDULER_APP_OUTPUT_FILE_PATH";
	char* outputFileName = nullptr;
	err = _dupenv_s(&outputFileName, &sz, outputFileEnvVarName.c_str());
	pConf->writeToFile(outputFileName);

	if (0 == err && nullptr != pLogEnabledEnvVarValue && 0 == strcmp(pLogEnabledEnvVarValue, "1"))
	{
		google::ShutdownGoogleLogging();
	}

	return 1;
}
