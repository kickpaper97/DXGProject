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

	GameEngineRenderTarget::IsDepth = false;
	GameEngineCore::MainWindow.CursorOff();

	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<DayOffLevel>("DayOffLevel");
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::ChangeLevel("TitleLevel");

	// 자기 텍스처 로드해야 한다.

}

void ContentsCore::Update(float _Delta)
{

}

void ContentsCore::Release()
{

}