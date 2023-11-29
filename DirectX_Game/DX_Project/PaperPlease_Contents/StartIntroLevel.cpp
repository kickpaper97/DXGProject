#include "PreCompile.h"
#include "StartIntroLevel.h"
#include "TitleLevel.h"

#include "CustomSpriteRenderer.h"
#include "IntroPicture.h"
#include "Cursor.h"

StartIntroLevel::StartIntroLevel()
{
}

StartIntroLevel::~StartIntroLevel()
{
}

void StartIntroLevel::Start()
{
	
	if(!GameEngineSprite::Find("Intro0.png"))
	{
		GameEngineSprite::CreateSingle("Intro0.png");
		GameEngineSprite::CreateSingle("Intro1.png");
		GameEngineSprite::CreateSingle("Intro2.png");
		GameEngineSprite::CreateSingle("Intro3.png");
		GameEngineSprite::CreateSingle("Arstotzka.png");
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);


	GameEngineInput::AddInputObject(this);


	IntroPic = CreateActor<IntroPicture>();
	IntroPic->GetSpriteRenderer()->SetIntroSprite();


	{
		CreateStateParameter Para;

		Para.Start = [=](GameEngineState* _Parent)
			{
				
				float4 PicPos = { GameEngineCore::MainWindow.GetScale().hX(), -GameEngineCore::MainWindow.GetScale().hY()};
				PicPos += {0, 100};

				
				IntroPic->GetSpriteRenderer()->SetSprite("Intro0.png");
				IntroPic->Transform.SetLocalPosition(PicPos);

				IsPress = false;
				
			};
		Para.Stay = [=](float _Delta,GameEngineState* _Parent)
			{
				if (true == IsPress)
				{
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta*0.75f;

				}
				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					IsPress = true;
				}
				if (0.0f>=IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord)
				{
					LevelState.ChangeState(IntroState::Intro1);
					return;
				}
			};
		Para.End = [=](GameEngineState* _Parent)
			{

			};

		LevelState.CreateState(IntroState::Intro0, Para);
	}

	{
		CreateStateParameter Para;

		Para.Start = [=](GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->SetSprite("Intro1.png");
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord = 1.0f;
				IsPress = false;
			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				if (true == IsPress)
				{
					IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta * 0.75f;

				}
				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					IsPress = true;
				}

				if (0.0f >= IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord)
				{
					LevelState.ChangeState(IntroState::Intro2);
					return;
				}
			};
		Para.End = [=](GameEngineState* _Parent)
			{

			};

		LevelState.CreateState(IntroState::Intro1, Para);
	}

	{
		CreateStateParameter Para;

		Para.Start = [=](GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->SetSprite("Intro2.png");
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord = 1.0f;
				IsPress = false;
			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				if (true == IsPress)
				{
					IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta * 0.75f;

				}
				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					IsPress = true;
				}

				if (0.0f >= IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord)
				{
					LevelState.ChangeState(IntroState::Intro3);
					return;
				}
			};
		Para.End = [=](GameEngineState* _Parent)
			{

			};

		LevelState.CreateState(IntroState::Intro2, Para);
	}

	{
		CreateStateParameter Para;

		Para.Start = [=](GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->SetSprite("Intro3.png");
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord = 1.0f;
				IsPress = false;
			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				if (true == IsPress)
				{
					IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta * 0.75f;

				}
				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					IsPress = true;
				}

				if (0.0f >= IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord)
				{
					LevelState.ChangeState(IntroState::Intro4);
					return;
				}
			};
		Para.End = [=](GameEngineState* _Parent)
			{

			};

		LevelState.CreateState(IntroState::Intro3, Para);
	}

	{
		CreateStateParameter Para;

		Para.Start = [=](GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->SetSprite("Arstotzka.png");
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord =1.0f;
				IsPress = false;
			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				
				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					GameEngineCore::ChangeLevel("PlayLevel");
					return;
				}
				
			};
		Para.End = [=](GameEngineState* _Parent)
			{

			};

		LevelState.CreateState(IntroState::Intro4, Para);
	}

	LevelState.ChangeState(IntroState::Intro0);
	GameEngineInput::AddInputObject(this);
	
}

void StartIntroLevel::Update(float _Delta)
{

	if(GameEngineInput::IsDown('P', this))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}

	LevelState.Update(_Delta);
}

void StartIntroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	std::shared_ptr<Cursor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);

	TitleLevel* PrevLevel = dynamic_cast<TitleLevel*>(_PrevLevel);

	Sound=PrevLevel->GetSound();
}

void StartIntroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	Sound.Stop();
}
