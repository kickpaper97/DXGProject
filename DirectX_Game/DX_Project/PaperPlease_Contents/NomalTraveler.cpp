#include "PreCompile.h"
#include "NomalTraveler.h"

NomalTraveler::NomalTraveler()
{


}

NomalTraveler::~NomalTraveler()
{
}



void NomalTraveler::Start()
{

	

	if (nullptr == GameEngineSprite::Find("NomalTravelerAni.Png"))
	{
		GameEngineSprite::CreateCut("NomalTravelerAni.Png", 10, 5);

	}

	OuterRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::People);

	

	{
		OuterRenderer->CreateAnimation("NomalTravelerStand1", "NomalTravelerAni.Png", 0.1f, 13, 13,false);
		OuterRenderer->CreateAnimation("NomalTravelerStand2", "NomalTravelerAni.Png", 0.1f, 14, 14,false);

		OuterRenderer->CreateAnimation("NomalTravelerHorizonWalk", "NomalTravelerAni.Png", 0.1f, 40, 43,  true);
		OuterRenderer->CreateAnimation("NomalTravelerVerticalWalk", "NomalTravelerAni.Png", 0.1f, 44, 47,  true);

		OuterRenderer->ChangeAnimation("NomalTravelerStand1");
		
	}

	{
	
		TimeRand.SetSeed(reinterpret_cast<long long>(this));
		int FirstPose = TimeRand.RandomInt(0, 1);
		StandingChangeTime = TimeRand.RandomFloat(1.0f, 3.0f);
		
		
		switch (FirstPose)
		{
		case 0:
			OuterRenderer->ChangeAnimation("NomalTravelerStand1");
			break;
		case 1:
			OuterRenderer->ChangeAnimation("NomalTravelerStand2");
			break;
		default:
			break;
		}

		OuterRenderer->GetImageTransform().SetLocalScale({64.0f,64.0f});
		OuterRenderer->SetRenderOrder(RenderOrder::People);

		ChanageState(TravelerState::WaitingStand);
	}
	

}

void NomalTraveler::Update(float _Delta)
{

	




	


	/*float FirstPoseChange = NewRand.RandomFloat(0.5f, 2.0f);
	float4 PoseTime = NewRand.RandomFloat(3.0f, 4.0f);*/

	StateUpdate(_Delta);

}

void NomalTraveler::WaitingStandStart()
{
}


void NomalTraveler::WaitingMoveStart()
{
}

void NomalTraveler::TurnStartStart()
{
}

void NomalTraveler::TurnStayStart()
{
}

void NomalTraveler::TurnEndStart()
{
}


void NomalTraveler::WaitingStandUpdate(float _Delta)
{


	if (0.0f >= StandingChangeTime)
	{
		if (OuterRenderer->IsCurAnimation("NomalTravelerStand1"))
		{
			OuterRenderer->ChangeAnimation("NomalTravelerStand2");
		}

		else if (OuterRenderer->IsCurAnimation("NomalTravelerStand2"))
		{
			OuterRenderer->ChangeAnimation("NomalTravelerStand1");
		}


		StandingChangeTime = TimeRand.RandomFloat(2.5f, 3.5f);


	}


	StandingChangeTime -= _Delta;

}

void NomalTraveler::WaitingMoveUpdate(float _Delta)
{
	
}

void NomalTraveler::TurnStartUpdate(float _Delta)
{
}

void NomalTraveler::TurnStayUpdate(float _Delta)
{
}

void NomalTraveler::TurnEndUpdate(float _Delta)
{
}

void NomalTraveler::StateUpdate(float _Delta)
{
	switch (State)
	{
	case WaitingStand:
		return WaitingStandUpdate(_Delta);
	case WatingMove:
		return WaitingMoveUpdate(_Delta);
	case TurnStart:
		return TurnStartUpdate(_Delta);
	case TurnStay:
		return TurnStayUpdate(_Delta);
	case TurnEnd:
		return TurnEndUpdate(_Delta);
	case Max:
	default:
		break;
	}
}

void NomalTraveler::ChanageState(TravelerState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case WaitingStand:
			WaitingStandStart();
			break;
		case WatingMove:
			WaitingMoveStart();
			break;
		case TurnStart:
			TurnStartStart();
			break;
		case TurnStay:
			TurnStayStart();
			break;
		case TurnEnd:
			TurnEndStart();
			break;
		case Max:
			break;
		default:
			break;
		}
	}

	State = _State;
}

void NomalTraveler::ChangeAnimationState(std::string_view _State)
{
}

//Inner 로 들어올때 와 나갈때 조금 Rotation을 돌린다?
