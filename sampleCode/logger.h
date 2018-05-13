#include <iostream>
#include <string>

using namespace std;

FILE *pLogFile = nullptr;
const std::string logFileName = "F:\\docs\\git\\testCode\\sampleCode\\logFile.txt";

const char* t(const std::string& testStr)
{
    return(testStr.c_str());
}

#define LOGSTR(str)\
{\
    if(nullptr == pLogFile)\
    {\
        fopen_s(&pLogFile , logFileName.c_str(), "w");\
    }\
    fprintf(pLogFile, "%s\n", t(str));\
}

#define LOG(fileName, functionName, lineNumber) \
{\
    if(nullptr == pLogFile)\
    {\
        fopen_s(&pLogFile , logFileName.c_str(), "w");\
    }\
    fprintf(pLogFile, "%s, %s, %d\n", t(fileName), t(functionName), \
        lineNumber);\
}

void exiting()
{
    fclose(pLogFile);
    pLogFile = nullptr;
}