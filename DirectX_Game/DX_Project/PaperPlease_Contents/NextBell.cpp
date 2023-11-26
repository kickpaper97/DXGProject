#include "PreCompile.h"
#include "NextBell.h"
#include "Cursor.h"

NextBell::NextBell()
{
}

NextBell::~NextBell()
{
}

void NextBell::Start()
{
	if (nullptr == GameEngineSprite::Find("OuterBooth.png"))
	{
		GameEngineSprite::CreateCut("OuterBooth.png", 1, 2);
	}


	if (nullptr == GameEngineSound::FindSound("speech-announce.WAV"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Audio");

		GameEngineSound::SoundLoad(FilePath.PlusFilePath("speech-announce.WAV"));
	}

	

	{
		SpriteRenderer = CreateComponent<GameEngineSpriteRenderer>();
		SpriteRenderer->SetRenderOrder(RenderOrder::OuterBox);
		SpriteRenderer->AutoSpriteSizeOn();
		SpriteRenderer->SetAutoScaleRatio(2.0f);
		SpriteRenderer->CreateAnimation("NextBellAble", "OuterBooth.png", 0.5f, 0, 1, true);
		SpriteRenderer->CreateAnimation("NextBellDisAble", "OuterBooth.png", 0.5f, 0, 0, false);
		SpriteRenderer->ChangeAnimation("NextBellDisAble");


	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->SetCollisionType(ColType::AABBBOX2D);
		float4 RenderScale = SpriteRenderer->GetImageTransform().GetLocalScale();
		Collision.get()->Transform.SetLocalScale({ RenderScale.X/2.5f ,RenderScale .Y/3.5f});
	}

	GameEngineInput::AddInputObject(this);
}

void NextBell::Update(float _Delta)
{

	{
		EventParameter Para;
		Para.Stay = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{



				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					if (false == isPress)
					{
					BoothSpeaker = GameEngineSound::SoundPlay("speech-announce.WAV");

					}
					isPress = true;
					SpriteRenderer->ChangeAnimation("NextBellDisAble");
					
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
