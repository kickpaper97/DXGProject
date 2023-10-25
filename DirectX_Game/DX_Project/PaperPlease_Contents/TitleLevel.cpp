#include "PreCompile.h"
#include "TitleLevel.h"
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


	///나중에 각자의 객체로 들어가야한다
	if(nullptr==GameEngineSprite::Find("Title.png"))
	{
		
		GameEngineSprite::CreateSingle("Title.png");
		//GameEngineSprite::CreateCut("QuitButton.png",1,2);
		

	}



	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	GameEngineInput::AddInputObject(this);

	float4 WindowSize=GameEngineCore::MainWindow.GetScale();
	



	


	{
		CreateStateParameter StateParmeter;

		

		StateParmeter.Start = [=](class GameEngineState* _Parent)
			{
				{

					Logo = CreateActor<BasicActor>(RenderOrder::BackGround);
					Logo->GetSpriteRenderer()->SetSprite("Title.Png");
					std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Find("Title.Png");
					Logo->GetSpriteRenderer()->AutoSpriteSizeOn();
					Logo->GetSpriteRenderer()->SetAutoScaleRatio(2.0f);
					float check = WindowSize.Y + Tex.get()->GetScale().Y;
					Logo->Transform.SetLocalPosition({ WindowSize.hX(),-check });
					Logo->On();
				}
				
				if (nullptr == Cursor::MainCursor)
				{
					std::shared_ptr<Cursor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);
					NewCursor->On();
				}

			};

		StateParmeter.Stay = [=](float _Delta, class GameEngineState* _Parent)
			{
				

				if (GameEngineInput::IsDown(VK_RETURN, this) ||
					GameEngineInput::IsDown(VK_LBUTTON, this) ||
					(GameEngineCore::MainWindow.GetScale().Half().Y + GameEngineCore::MainWindow.GetScale().Half().Half().hY()) <= Logo->Transform.GetWorldPosition().Y
					)
				{
					_Parent->ChangeState(TitleState::Waiting);
					return;
				}

				if (0.0f >= DeltaCheck)
				{
					if (false == isAnimaitonPause)
					{
						isAnimaitonPause = true;
					}
					else
					{
						isAnimaitonPause = false;
					}

					DeltaCheck = 0.6f;
				}

				if (false == isAnimaitonPause)
				{
					Logo->Transform.AddLocalPosition(AnimationDir / 4 * 250 * _Delta);
				}


				float y = Logo->Transform.GetWorldPosition().Y;




				DeltaCheck -= _Delta;

			};

		StateParmeter.End = [=](class GameEngineState* _Parent)
			{
				



			};

		LevelState.CreateState(TitleState::Anime, StateParmeter);
	}

	{
		CreateStateParameter StateParameter;

		
		StateParameter.Start = [=](class GameEngineState* _Parent)
			{
				
				float4 Logopos = { GameEngineCore::MainWindow.GetScale().hX(), -GameEngineCore::MainWindow.GetScale().Half().Y + GameEngineCore::MainWindow.GetScale().Half().Half().hY() };
				Logo->Transform.SetLocalPosition(Logopos);

				std::shared_ptr<BasicButton> NewQuitButton = CreateActor<QuitButton>(GameObjectType::UIButton);
				NewQuitButton->Transform.SetWorldPosition({ 1100,-50 });

			};
		StateParameter.Stay = [=](float _Delta, class GameEngineState* _Parent)
			{

				if (0.0f >= DeltaCheck)
				{


					if (true == isAnimaitonPause)
					{
						isAnimaitonPause = false;

						if (float4::UP == AnimationDir)
						{
							AnimationDir = float4::DOWN;
						}
						else if (float4::DOWN == AnimationDir)
						{
							AnimationDir = float4::UP;
						}

					}
					else
					{
						isAnimaitonPause = true;
					}

					DeltaCheck = 0.6f;
				}

				if (false == isAnimaitonPause)
				{
					Logo->Transform.AddLocalPosition(AnimationDir / 4 * 250 * _Delta);
				}

				DeltaCheck -= _Delta;
			};

		LevelState.CreateState(TitleState::Waiting,StateParameter);
	}


	LevelState.ChangeState(TitleState::Anime);
}


void TitleLevel::Update(float _Delta)
{

	float4 WindowSize = GameEngineCore::MainWindow.GetScale();


	LevelState.Update(_Delta);
	



	if (GameEngineInput::IsDown('P', this))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}


	if (GameEngineInput::IsDown('M', this))
	{
		UIOff();
	}

	if (GameEngineInput::IsDown('N',this))
	{
		UIOn();
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