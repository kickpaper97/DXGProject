#include "PreCompile.h"
#include "StartButton.h"

StartButton::StartButton()
{
}

StartButton::~StartButton()
{
}

void StartButton::Start()
{

	BasicButton::Start();


	if (nullptr == GameEngineSprite::Find("StoryButton.png"))
	{
		GameEngineSprite::CreateSingle("StoryButton.png");

	}

	std::shared_ptr<GameEngineSpriteRenderer> Renderer = GetSpriteRenderer();
	Renderer->AutoSpriteSizeOn();
	Renderer->SetAutoScaleRatio(1.0f);
	Renderer->SetSprite("StoryButton.png");
	
	

	Collision->SetCollisionType(ColType::AABBBOX2D);


	Collision->Transform.SetLocalScale(Renderer->GetImageTransform().GetLocalScale());

}

void StartButton::Update(float _Delta)
{


	{
		EventParameter Para;
		Para.Stay = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{



				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					GameEngineCore::ChangeLevel("StartIntroLevel");
					return;

				}




			};

		Para.Enter = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{


				Cursor::MainCursor->GetRenderer()->SetSprite("CursorHand.png");

			};




		Para.Exit = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{

				Cursor::MainCursor->GetRenderer().get()->SetSprite("CursorArrow.png");

			};
		Collision->CollisionEvent(CollisionOrder::Cursor, Para);


	}


}
