#include "PreCompile.h"
#include "QuitButton.h"
#include "BasicButton.h"

QuitButton::QuitButton()
{
}

QuitButton::~QuitButton()
{
}

void QuitButton::Start()
{

	BasicButton::Start();


	if (nullptr == GameEngineSprite::Find("QuitButton.png"))
	{
		GameEngineSprite::CreateCut("QuitButton.png", 1,2);

	}

	std::shared_ptr<GameEngineSpriteRenderer> Renderer =GetSpriteRenderer();
	Renderer->AutoSpriteSizeOn();
	Renderer->SetAutoScaleRatio(2.0f);
	Renderer->SetSprite("QuitButton.png");
	Renderer->CreateAnimation("QuitButtonOFF", "QuitButton.png", 0.01f, 0, 0, false);
	Renderer->CreateAnimation("QuitButtonON", "QuitButton.png", 0.01f, 1, 1, false);
	Renderer->ChangeAnimation("QuitButtonOFF");


	Collision->SetCollisionType(ColType::SPHERE2D);
	
	
	Collision->Transform.SetLocalScale(Renderer->GetImageTransform().GetLocalScale());
	
}

void QuitButton::Update(float _Delta)
{

	BasicButton::Update(_Delta);
	
	
	{
		EventParameter SubPara;
		SubPara.Stay = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{

				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					DestroyWindow(GameEngineCore::MainWindow.GetHWND());

				}




			};

		SubPara.Enter = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{

				SpriteRenderer->ChangeAnimation("QuitButtonON");
				Cursor::MainCursor->GetRenderer()->SetSprite("CursorHand.png");

			};

		
			

		SubPara.Exit = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{
				SpriteRenderer->ChangeAnimation("QuitButtonOFF");
				Cursor::MainCursor->GetRenderer().get()->SetSprite("CursorArrow.png");

			};
		Collision->CollisionEvent(CollisionOrder::Cursor, SubPara);
		

		


	}
	
	
}
