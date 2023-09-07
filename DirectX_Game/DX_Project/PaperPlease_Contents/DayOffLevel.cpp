#include "PreCompile.h"

#include "DayOffLevel.h"
#include "PlayLevel.h"

DayOffLevel::DayOffLevel()
{
}

DayOffLevel::~DayOffLevel()
{
}



void DayOffLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	Curday = dynamic_cast<PlayLevel*>(_PrevLevel)->GetCurDay();
}

void DayOffLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	
}


