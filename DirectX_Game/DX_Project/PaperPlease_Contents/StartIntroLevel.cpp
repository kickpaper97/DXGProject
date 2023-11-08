#include "PreCompile.h"
#include "StartIntroLevel.h"

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

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	GameEngineInput::AddInputObject(this);


	IntroPic = CreateActor<IntroPicture>(GameObjectType::BackGround);
	IntroPic->GetSpriteRenderer()->SetIntroSprite();


	
	{
		CreateStateParameter Para;

		Para.Start = [=](GameEngineState* _Parent)
			{
				std::shared_ptr<Cursor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);
				float4 PicPos = GameEngineCore::MainWindow.GetScale().Half();


				
				IntroPic->GetSpriteRenderer()->SetSprite("Intro0.png");
				IntroPic->Transform.SetLocalPosition(PicPos);

				
			};
		Para.Stay = [=](float _Delta,GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta*0.75f;

				if (3.0f <= LevelState.GetStateTime())
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

			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta;

				if (3.0f <= LevelState.GetStateTime())
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

			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta;

				if (3.0f <= LevelState.GetStateTime())
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

			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta;

				if (3.0f <= LevelState.GetStateTime())
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
			};
		Para.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				IntroPic->GetSpriteRenderer()->GetTexCoordData().CurTexCoord -= _Delta;

				
			};
		Para.End = [=](GameEngineState* _Parent)
			{

			};

		LevelState.CreateState(IntroState::Intro4, Para);
	}

	LevelState.ChangeState(IntroState::Intro0);
	
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
	

}

void StartIntroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}
