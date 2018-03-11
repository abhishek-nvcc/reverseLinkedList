#ifdef CONFERENCE_INC
#define COMMONDEFINITIONS_INC
#define WINDOWS_INC
#define TRACK_INC
#define TALK_INC
#define FSTREAM_INC
#define SSTREAM_INC
#define STREAM_INC
#define IOSTREAM_INC
#define ASSERT_INC
#define UTILS_INC
#endif

#ifdef UTILS_INC
#define STRING_INC
#define TRACK_INC
#define FSTREAM_INC
#define COMMONDEFINITIONS_INC
#define VECTOR_INC
#define ASSERT_INC
#endif

#ifdef TRACK_INC
#define COMMONDEFINITIONS_INC
#define SESSION_INC
#define ASSERT_INC
#endif

#ifdef SESSION_INC
#define COMMONDEFINITIONS_INC
#define TALK_INC
#define ASSERT_INC
#endif

#ifdef TALK_INC
#define COMMONDEFINITIONS_INC
#define STRING_INC
#endif

#ifdef ASSERT_INC
#include <assert.h>
#endif

#ifdef IOSTREAM_INC
#include <iostream>
#endif

#ifdef SSTREAM_INC
#include <sstream>
#endif

#ifdef STREAM_INC
#include <string>
#endif

#ifdef FSTREAM_INC
#include <fstream>
#endif

#ifdef STRING_INC
#include <string>
#endif

#ifdef VECTOR_INC
#include <vector>
#endif

#ifdef WINDOWS_INC
#include "windows.h"
#endif

#ifdef CATCH_INC
#include "catch.hpp"
#endif

#ifdef GOOGLELOGGER_INC
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "glog\logging.h"
#endif

#ifdef COMMONDEFINITIONS_INC
#include "commonDefinitions.h"
#endif

#ifdef TALK_INC
#include "talk.h"
#endif

#ifdef SESSION_INC
#include "session.h"
#endif

#ifdef TRACK_INC
#include "track.h"
#endif

#ifdef CONFERENCE_INC
#include "conference.h"
#endif

#ifdef UTILS_INC
#include "utils.h"
#endif

