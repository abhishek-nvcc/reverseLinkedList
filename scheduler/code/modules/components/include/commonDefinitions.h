#ifndef COMMONDEFINITIONS_H
#define COMMONDEFINITIONS_H

enum SESSION
{
	MORNING_SESSION = 0,
	EVENING_SESSION
};

enum TRACK
{
	FIRST_TRACK = 0,
	SECOND_TRACK
};

enum INPUTLINE_DATA_ITEMS
{
	TALK_TITLE = 0,
	TALK_DURATION,
	TALK_DURATION_UNIT
};

#define DURATION_MORNING_SESSION (180)
#define DURATION_EVENING_SESSION (240)

#define TALK_DURATION_UNIT_MINUTES ("min")
#define TALK_DURATION_UNIT_LIGHTNING ("lightning")
#define ERROR_INVALID_DURATION_TYPE_USED_TO_CREATE_TALK ("invalid duration unit")

#define LIGHTNING_TO_MINUTES_CONVERTER (5)

#define HOUR_TO_MINUTE_CONVERTER (60)

#define MORNING_SESSION_START_TIME_HOUR (9)
#define MORNING_SESSION_START_TIME_MIN (0)
#define MORNING_SESSION_END_TIME_HOUR (12)
#define MORNING_SESSION_END_TIME_MIN (0)

#define EVENING_SESSION_START_TIME_HOUR (13)
#define EVENING_SESSION_START_TIME_MIN (0)
#define EVENING_SESSION_END_TIME_HOUR (17)
#define EVENING_SESSION_END_TIME_MIN (0)

#define FIRST_TRACK_MORNING_SESSION_STRING ("Track 1: Morning Session")
#define FIRST_TRACK_EVENING_SESSION_STRING ("Track 1: Evening Session")

#define SECOND_TRACK_MORNING_SESSION_STRING ("Track 2: Morning Session")
#define SECOND_TRACK_EVENING_SESSION_STRING ("Track 2: Evening Session")

#define LUNCH_TIME_AND_TITLE_STRING ("12:00 pm Lunch")
#define NETWORKING_EVENT_TIME_AND_TITLE_STRING ("5:00 pm Networking Event")

#define POST_MERIDIEM_STRING ("pm")
#define ANTE_MERIDIEM_STRING ("am")

#endif