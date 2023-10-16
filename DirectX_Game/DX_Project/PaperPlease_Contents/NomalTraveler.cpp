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
		GameEngineSprite::CreateCut("SheetF0.png",2, 2);
		GameEngineSprite::CreateCut("SheetF1.png", 2, 2);
		GameEngineSprite::CreateCut("SheetF2.png", 2, 2);
		GameEngineSprite::CreateCut("SheetF3.png", 2, 2);
		GameEngineSprite::CreateCut("SheetF4.png", 2, 2);

		GameEngineSprite::CreateCut("SheetM0.png", 2, 2);
		GameEngineSprite::CreateCut("SheetM1.png", 2, 2);
		GameEngineSprite::CreateCut("SheetM2.png", 2, 2);
		GameEngineSprite::CreateCut("SheetM3.png", 2, 2);
		GameEngineSprite::CreateCut("SheetM4.png", 2, 2);
		GameEngineSprite::CreateCut("SheetM5.png", 2, 2);
	

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

	{
		RandomSetTravelerInfo();
	}
	

}

void NomalTraveler::Update(float _Delta)
{

	




	


	/*float FirstPoseChange = NewRand.RandomFloat(0.5f, 2.0f);
	float4 PoseTime = NewRand.RandomFloat(3.0f, 4.0f);*/

	StateUpdate(_Delta);

}


void NomalTraveler::RandomSetTravelerInfo()
{

	int intRand = TimeRand.RandomInt(0, 1);
	Info.Sex = intRand;
	intRand = TimeRand.RandomInt(0, 6);
	Info.OriginCountry = static_cast<Country>(intRand);
	intRand = TimeRand.RandomInt(0, 2);
	Info.City = intRand;


	{

		/*int SheetNum = -1;
		std::string SheetName = "";
		int SheetX = -1;
		int SheetY = -1;
		if (Info.Sex == 0)
		{
			SheetNum = TimeRand.RandomInt(0, 4);
			SheetName = "SheetF";
			switch (SheetNum)
			{
			case 0:
				SheetName += "0";
				break;
			case 1:
				SheetName += "1";
				break;
			case 2:
				SheetName += "2";
				break;
			case 3:
				SheetName += "3";
				break;
			case 4:
				SheetName += "4";
				break;
			default:
				break;
			}
			SheetX = TimeRand.RandomInt(0, 1);
			SheetY = TimeRand.RandomInt(0, 1);

		}

		else
		{
			SheetNum = TimeRand.RandomInt(0, 5);

			SheetName = "SheetM";
			switch (SheetNum)
			{
			case 0:
				SheetName += "0";
				break;
			case 1:
				SheetName += "1";
				break;
			case 2:
				SheetName += "2";
				break;
			case 3:
				SheetName += "3";
				break;
			case 4:
				SheetName += "4";
				break;
			case 5:
				SheetName += "5";
				break;
			default:
				break;
			}
			SheetX = TimeRand.RandomInt(0, 1);
			SheetY = TimeRand.RandomInt(0, 1);
		}
		SheetName += ".png";
		Info.Face = CreateComponent<GameEngineSpriteRenderer>();
		Info.Face->CreateAnimation("Face", SheetName, 0.1f, SheetX, SheetY, false);
		Info.Face->ChangeAnimation("Face");
		*/

		RandomSetFace();




		{
			intRand = TimeRand.RandomInt(25, 65);
			Info.Date_of_Birth.push_back(intRand);
			intRand = TimeRand.RandomInt(1, 12);
			Info.Date_of_Birth.push_back(intRand);

			switch (intRand)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				intRand = TimeRand.RandomInt(1, 31);
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				intRand = TimeRand.RandomInt(1, 30);
				break;
			case 2:
				intRand = TimeRand.RandomInt(1, 29);
				break;
			default:
				break;
			}
			Info.Date_of_Birth.push_back(intRand);
		}
	}
}
	

void NomalTraveler::RandomSetFace()
{
	{

		int SheetNum = -1;
		
		if (Info.Sex == 0)
		{
			SheetNum = TimeRand.RandomInt(0, 4);
			Info.Face.SheetName = "SheetF";
			switch (SheetNum)
			{
			case 0:
				Info.Face.SheetName += "0";
				break;
			case 1:
				Info.Face.SheetName += "1";
				break;
			case 2:
				Info.Face.SheetName += "2";
				break;
			case 3:
				Info.Face.SheetName += "3";
				break;
			case 4:
				Info.Face.SheetName += "4";
				break;
			default:
				break;
			}
			Info.Face.SheetX = TimeRand.RandomInt(0, 1);
			Info.Face.SheetY = TimeRand.RandomInt(0, 1);

		}

		else
		{
			SheetNum = TimeRand.RandomInt(0, 5);

			Info.Face.SheetName = "SheetM";
			switch (SheetNum)
			{
			case 0:
				Info.Face.SheetName += "0";
				break;
			case 1:
				Info.Face.SheetName += "1";
				break;
			case 2:
				Info.Face.SheetName += "2";
				break;
			case 3:
				Info.Face.SheetName += "3";
				break;
			case 4:
				Info.Face.SheetName += "4";
				break;
			case 5:
				Info.Face.SheetName += "5";
				break;
			default:
				break;
			}
			Info.Face.SheetX = TimeRand.RandomInt(0, 1);
			Info.Face.SheetY = TimeRand.RandomInt(0, 1);
		}
		Info.Face.SheetName += ".png";
		FaceRenderer = CreateComponent<GameEngineSpriteRenderer>();
		FaceRenderer->CreateAnimation("Face", Info.Face.SheetName, 0.1f, Info.Face.SheetX, Info.Face.SheetY, false);
		FaceRenderer->ChangeAnimation("Face");
		FaceRenderer->SetAutoScaleRatio(2.0f);
		FaceRenderer->Off();



	}


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
