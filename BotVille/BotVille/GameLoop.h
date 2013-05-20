#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SDL.h>
#include "AppConstants.h"

class GameLoop
{
public:

	GameLoop();

	/* Destructor. */
	~GameLoop();

	/* Call Start() when you start using the timers (when you enter the gameloop, or resume play after a pause).
	   Also call it whenever you have updated the "Updates per Interval" or "Interval Duration" variables, 
	   to activate the change immediately. */
	void Start();

	/* This function makes the program (or current thread, if multi-threaded) halt execution until its 
	   time for another update. In other words, it frees up the CPU for other tasks until its time for 
	   a new update.

	   NOTE: As with any kind of "sleep" functionality, we're not guaranteed to get control back at the 
	         exact moment we want it, that's up to the OS (Windows) to handle. (99.9% of the time it 
	         works like a intm though. :-) */
	void SleepUntilUpdate();
	void Stop();
	bool GetLoopRunning();
private:
	unsigned short	m_usWantedUPI;			 // Number of updates we're striving to get per interval.
	unsigned short	m_usIntDur;				 // Duration of interval in milliseconds.
	unsigned short	m_usUpdatesLastInt;		 // Number of updates last interval total.
	unsigned short	m_usUpdatesCurrInt;		 // Number of updates current interval so far.

	Uint32			m_ui32CurrIntStartTick;	 // When current interval started.
	Uint32			m_ui32NextIntStartTick;	 // When next interval starts.
	Uint32			m_ui32NextUpdateTick;	 // Ideal time for next update.
	bool IsRunning;
};

#endif