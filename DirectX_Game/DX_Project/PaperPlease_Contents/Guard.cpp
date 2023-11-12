#include "PreCompile.h"
#include "Guard.h"

#include "PeopleBase.h"

Guard::Guard()
{
}

Guard::~Guard()
{
}

void Guard::Start()
{
	if (nullptr == GameEngineSprite::Find("GuardAni.Png"))
	{
		GameEngineSprite::CreateCut("GuardAni.Png", 10, 7);
		

	}

	OuterRenderer = CreateComponent<GameEngineSpriteRenderer>();
	
	PeopleBase::Start();
	OuterRenderer->CreateAnimation("GuardStand1", "GuardAni.Png", 1.0f, 12, 13, true);
	OuterRenderer->CreateAnimation("GuardStand2", "GuardAni.Png", 1.0f, 14, 15, true);

	OuterRenderer->CreateAnimation("VerticalMove", "GuardAni.Png", 0.15f, 59, 62, true);
	OuterRenderer->CreateAnimation("HorizontalMove", "GuardAni.png", 0.15f, 55, 58, true);
	OuterRenderer->ChangeAnimation("VerticalMove");
	OuterRenderer->GetImageTransform().SetLocalScale({ 64.0f,64.0f });
	OuterRenderer->LeftFlip();

	GameEngineRandom StandRand;
	StandRand.SetSeed(reinterpret_cast<long long>(this));
	Standing = StandRand.RandomInt(1, 2);
	
}

void Guard::Update(float _Delta)
{

	if (false == isStand)
	{
		if (DestinationPos != Transform.GetLocalPosition())
		{
			if (DestinationPos.Y != Transform.GetLocalPosition().Y)
			{
				if (false==OuterRenderer->IsCurAnimation("VerticalMove"))
				{
					OuterRenderer->ChangeAnimation("VerticalMove");
				}

				Transform.AddLocalPosition(float4::DOWN * 20 * _Delta);

				if (DestinationPos.Y >= Transform.GetLocalPosition().Y)
				{
					Transform.SetLocalPosition({ Transform.GetLocalPosition().X,DestinationPos.Y });
				}

			}
			else if (DestinationPos.X != Transform.GetLocalPosition().X)
			{
				if (false==OuterRenderer->IsCurAnimation("HorizontalMove"))
				{
					OuterRenderer->ChangeAnimation("HorizontalMove");
					OuterRenderer->LeftFlip();
				}

				Transform.AddLocalPosition(float4::LEFT * 20 * _Delta);

				if (DestinationPos.X >= Transform.GetLocalPosition().X)
				{
					Transform.SetLocalPosition({ DestinationPos.X,Transform.GetLocalPosition().Y });
				}

			}
		}
		else
		{
			switch (Standing)
			{
			case 0:
			{
				MsgBoxAssert("Gaurd의 Stand를 정하지 않았습니다.");
				return;

			}

			case 1:
				OuterRenderer->ChangeAnimation("GuardStand1");
				break;
			case 2:
				OuterRenderer->ChangeAnimation("GuardStand2");
				break;
			default:
				break;
			}

			isStand = true;
		}

	}



}
