#include "PreCompile.h"

#include "DayOffLevel.h"
#include "PlayLevel.h"

DayOffLevel::DayOffLevel()
{
}

DayOffLevel::~DayOffLevel()
{
}



void DayOffLevel::Start()
{
	GameEngineSprite::CreateSingle("NightReport.png");
	GameEngineSprite::CreateSingle("Tokens.png");
	GameEngineSprite::CreateSingle("Upgrades.png");
	GameEngineSprite::CreateSingle("NightPassportFrame.png");

}

void DayOffLevel::Update(float _Delta)
{
}

void DayOffLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	Curday = dynamic_cast<PlayLevel*>(_PrevLevel)->GetCurDay();
}

void DayOffLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	
}


