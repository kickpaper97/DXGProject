#include "PreCompile.h"
#include "ContentsCore.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include "TitleLevel.h"
#include "PlayLevel.h"
#include"DayOffLevel.h"

//#include<GameEnginePlatform/GameEngineWindow.h>

ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::Start()
{
	GameEngineCore::MainWindow.CursorOff();

	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<DayOffLevel>("DayOffLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::ChangeLevel("PlayLevel");

	// �ڱ� �ؽ�ó �ε��ؾ� �Ѵ�.

}

void ContentsCore::Update(float _Delta)
{

}

void ContentsCore::Release()
{

}