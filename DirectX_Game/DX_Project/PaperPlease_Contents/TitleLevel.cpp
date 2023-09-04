#include "PreCompile.h"
#include "TitleLevel.h"
#include "BasicActor.h"

#include <GameEngineCore/GameEngineComponent.h>

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Start()
{


	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("assets");
		
		
		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& ChildDir = Directorys[i];
			GameEngineSprite::CreateFolder(ChildDir.GetStringPath());
		}
		GameEngineSprite::CreateSingle("Title.png");
	}


	GetMainCamera()->Transform.SetLocalPosition({GameEngineCore::MainWindow.GetScale().hX() , GameEngineCore::MainWindow.GetScale().hY(), -500.0f});
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);



	float4 WindowSize=GameEngineCore::MainWindow.GetScale();
	{
		

	Logo = CreateActor<BasicActor>(1);
	Logo->GetSpriteRenderer()->SetSprite("Title.Png");
	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find("Title.Png");
	Logo->GetSpriteRenderer()->AutoSpriteSizeOn();
	Logo->GetSpriteRenderer()->SetAutoScaleRatio(2.0f);
	float check =Tex.get()->GetScale().hY();
	Logo->Transform.SetLocalPosition({ WindowSize.hX(),-check ,-500.0f});
	
	Tex.reset();
	}



}


void TitleLevel::Update(float _Delta)
{
	if (GameEngineInput::IsDown(VK_RETURN) ||
		GameEngineInput::IsDown(VK_LBUTTON))
	{
		isAnimation = false;
	}

	if (true == isAnimation)
	{

	}

	if (GameEngineInput::IsPress('W'))
	{
		Logo->Transform.AddLocalPosition(float4::UP);
	}

	if (GameEngineInput::IsPress('S'))
	{
		Logo->Transform.AddLocalPosition(float4::DOWN);
	}


	if (GameEngineInput::IsPress('P'))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
}


void TitleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	if (true == isAnimation)
	{

	}
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}