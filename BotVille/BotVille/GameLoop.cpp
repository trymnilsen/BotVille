#include "GameLoop.h"


GameLoop::GameLoop()
{
	m_usWantedUPI=WantedUpdatesPerSecond;
	m_usIntDur = WantedIntervalLength;
}
GameLoop::~GameLoop()
{
}
void GameLoop::SleepUntilUpdate()
{
		// Sleep until it's time for coming update.
	long lTicksRemaining = m_ui32NextUpdateTick - SDL_GetTicks();
	if (0 < lTicksRemaining)
	{
		SDL_Delay(lTicksRemaining);
	}

	// Sleep done - update variables so they're ready for the next update again.
	++m_usUpdatesCurrInt;
	m_ui32NextUpdateTick = m_ui32CurrIntStartTick + ((m_usUpdatesCurrInt + 1) * m_usIntDur / m_usWantedUPI);
	while (m_ui32NextUpdateTick > m_ui32NextIntStartTick)
	{
		m_ui32CurrIntStartTick = m_ui32NextIntStartTick;
		m_ui32NextIntStartTick += m_usIntDur;
		m_usUpdatesLastInt = m_usUpdatesCurrInt;
		m_usUpdatesCurrInt = 0;
	}
}
void GameLoop::Start()
{
	IsRunning=true;
// Setting the rest of the variables to default values.
	m_usUpdatesLastInt = 0;
	m_usUpdatesCurrInt = 0;
	m_ui32CurrIntStartTick = SDL_GetTicks();
	m_ui32NextIntStartTick = m_ui32CurrIntStartTick + m_usIntDur;
	m_ui32NextUpdateTick = m_ui32CurrIntStartTick + ((m_usUpdatesCurrInt + 1) * m_usIntDur / m_usWantedUPI);
}
void GameLoop::Stop()
{
	IsRunning=false;
}
bool GameLoop::GetLoopRunning()
{
	return IsRunning;
}
