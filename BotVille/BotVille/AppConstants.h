#ifndef APPCONSTANTS_H
#define APPCONSTANTS_H

//Number of updates we optimaly want each interval
const short WantedUpdatesPerSecond = 60;
//Miliseconds of each interval, (usually one second)
const short WantedIntervalLength = 1000; 
enum EntityType {
	STATIC_GROUND,
	STATIC_BUILDING, 
	STATIC_STAND, 
	STATIC_SHADOW, 
	AGENT_CIVILIAN, 
	AGENT_THIEF, 
	AGENT_GUARD };

#endif