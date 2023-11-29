#include "PreCompile.h"

#include "DayOffLevel.h"
#include "PlayLevel.h"
#include "Cursor.h"

#include "DayOffBackGround.h"

DayOffLevel::DayOffLevel()
{
}

DayOffLevel::~DayOffLevel()
{
}



void DayOffLevel::Start()
{

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		BackGround = CreateActor<DayOffBackGround>();
	}

}

void DayOffLevel::Update(float _Delta)
{

}

void DayOffLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	//Curday = dynamic_cast<PlayLevel*>(_PrevLevel)->GetCurDay();
	std::shared_ptr<Cursor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);
}

void DayOffLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	
}


