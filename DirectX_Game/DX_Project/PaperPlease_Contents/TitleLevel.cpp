#include "PreCompile.h"
#include "TitleLevel.h"
#include "BasicActor.h"
#include "BasicButton.h"
#include "QuitButton.h"
#include "Cursor.h"

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
		
		
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}

	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("assets");
		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());

		}
	}


	{
		
		GameEngineSprite::CreateSingle("Title.png");
		GameEngineSprite::CreateCut("QuitButton.png",1,2);
		
		GameEngineSprite::CreateSingle("CursorArrow.png");
		GameEngineSprite::CreateSingle("CursorHand.png");

	}


	GetMainCamera()->Transform.SetLocalPosition({GameEngineCore::MainWindow.GetScale().hX() , GameEngineCore::MainWindow.GetScale().hY(), -500.0f});
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);



	float4 WindowSize=GameEngineCore::MainWindow.GetScale();
	{
		

	Logo = CreateActor<BasicActor>(RenderOrder::BackGround);
	Logo->GetSpriteRenderer()->SetSprite("Title.Png");
	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find("Title.Png");
	Logo->GetSpriteRenderer()->AutoSpriteSizeOn();
	Logo->GetSpriteRenderer()->SetAutoScaleRatio(2.0f);
	float check =Tex.get()->GetScale().hY();
	Logo->Transform.SetLocalPosition({ WindowSize.hX(),-check ,-500.0f});
	
	
	}



}


void TitleLevel::Update(float _Delta)
{

	float4 WindowSize = GameEngineCore::MainWindow.GetScale();

	if (true == isAnimation)
	{
		if (GameEngineInput::IsDown(VK_RETURN) ||
			GameEngineInput::IsDown(VK_LBUTTON)||
			(GameEngineCore::MainWindow.GetScale().Half().Y+ GameEngineCore::MainWindow.GetScale().Half().Half().hY()) <=Logo->Transform.GetWorldPosition().Y
			)
		{
			float4 Logopos={GameEngineCore::MainWindow.GetScale().hX(), GameEngineCore::MainWindow.GetScale().Half().Y + GameEngineCore::MainWindow.GetScale().Half().Half().hY()};
			Logo->Transform.SetLocalPosition(Logopos);
			std::shared_ptr<BasicActor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);
			std::shared_ptr<BasicButton> NewQuitButton = CreateActor<QuitButton>(GameObjectType::UI);
			NewQuitButton.get()->Transform.SetLocalPosition({ 1100,600 });
			isAnimation = false;
		}

		if (false == isAnimaitonPause)
		{
			Logo->Transform.AddLocalPosition(AnimationDir/4 );
		}


		float y = Logo->Transform.GetWorldPosition().Y;

	}
	else
	{
		if (false == isAnimaitonPause)
		{
			Logo->Transform.AddLocalPosition(AnimationDir/4);
		}
	}

	if (GameEngineInput::IsDown('A'))
	{
		Logo->GetSpriteRenderer()->On();
	}

	if (GameEngineInput::IsDown('D'))
	{
		Logo->GetSpriteRenderer()->Off();
	}


	if (GameEngineInput::IsDown('P'))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}

	DeltaCheck -= _Delta;
	if (0.0f >= DeltaCheck)
	{
		


		if (true == isAnimaitonPause)
		{
			isAnimaitonPause = false;
			if (false == isAnimation)
			{
				if (float4::UP == AnimationDir)
				{
					AnimationDir = float4::DOWN;
				}
				else if (float4::DOWN == AnimationDir)
				{
					AnimationDir = float4::UP;
				}
			}
		}
		else
		{
			isAnimaitonPause = true;
		}

		DeltaCheck = 0.6f;
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