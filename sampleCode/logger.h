#include <iostream>
#include <string>

using namespace std;

static FILE *pLogFile = nullptr;
static const std::string logFileName = "log.log";

static const char* t(const std::string& testStr)
{
    return(testStr.c_str());
}

#define LOGSTR(str)\
{\
    if(nullptr == pLogFile)\
    {\
        pLogFile = fopen(logFileName.c_str(), "w");\
    }\
    if(nullptr != pLogFile)\
    {\
        fprintf(pLogFile, "%s\n", t(str));\
    }\
}

#define LOG(fileName, functionName, lineNumber) \
{\
    if(nullptr == pLogFile)\
    {\
        pLogFile = fopen(logFileName.c_str(), "w");\
    }\
    if(nullptr != pLogFile)\
    {\
        fprintf(pLogFile, "%s, %s, %d\n", t(fileName), t(functionName), \
        lineNumber);\
    }\
}

void exiting()
{
    LOG(__FILE__, __FUNCTION__, __LINE__)
    if (nullptr != pLogFile)
    {
        fclose(pLogFile);
        pLogFile = nullptr;
    }
}
