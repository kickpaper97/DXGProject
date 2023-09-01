#include "PreCompile.h"
#include "TitleLevel.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Start()
{


	GetMainCamera()->Transform.SetLocalPosition({GameEngineCore::MainWindow.GetScale().hX() , GameEngineCore::MainWindow.GetScale().hY(), -500.0f});
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);
}


void TitleLevel::Update(float _Delta)
{
	if (GameEngineInput::IsPress('P'))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
}


void TitleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}