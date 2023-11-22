#include "PreCompile.h"
#include "NormalTraveler.h"



NormalTraveler::NormalTraveler()
{


}

NormalTraveler::~NormalTraveler()
{
}



void NormalTraveler::WalkToBooth(float _Delta)
{

	if (!OuterRenderer->IsCurAnimation("NormalTravelerHorizonWalk"))
	{
		OuterRenderer->ChangeAnimation("NormalTravelerHorizonWalk");
	}
	float4 curPos = Transform.GetLocalPosition();
	float4 chek = ((BoothPos - float4{10,0}) - curPos).NormalizeReturn();
	Transform.AddLocalPosition(chek *20* _Delta);
}

void NormalTraveler::Start()
{



	if (nullptr == GameEngineSprite::Find("NormalTravelerAni.Png"))
	{
		GameEngineSprite::CreateCut("NormalTravelerAni.Png", 10, 5);
		GameEngineSprite::CreateCut("SheetF0.png", 2, 2);
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

	OuterRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::NormalTraveler);


	{
		OuterRenderer->CreateAnimation("NormalTravelerStand1", "NormalTravelerAni.Png", 0.1f, 13, 13, false);
		OuterRenderer->CreateAnimation("NormalTravelerStand2", "NormalTravelerAni.Png", 0.1f, 14, 14, false);

		OuterRenderer->CreateAnimation("NormalTravelerHorizonWalk", "NormalTravelerAni.Png", 0.1f, 40, 43, true);
		OuterRenderer->CreateAnimation("NormalTravelerVerticalWalk", "NormalTravelerAni.Png", 0.1f, 44, 47, true);

		OuterRenderer->ChangeAnimation("NormalTravelerStand1");

	}

	{

		TimeRand.SetSeed(reinterpret_cast<long long>(this));
		int FirstPose = TimeRand.RandomInt(0, 1);
		StandingChangeTime = TimeRand.RandomFloat(1.0f, 3.0f);


		switch (FirstPose)
		{
		case 0:
			OuterRenderer->ChangeAnimation("NormalTravelerStand1");
			break;
		case 1:
			OuterRenderer->ChangeAnimation("NormalTravelerStand2");
			break;
		default:
			break;
		}

		OuterRenderer->GetImageTransform().SetLocalScale({ 64.0f,64.0f });
		OuterRenderer->SetRenderOrder(RenderOrder::NormalTraveler);

		ChanageState(TravelerState::WaitingStand);
	}

	{
		RandomSetTravelerInfo();
	}


}

void NormalTraveler::Update(float _Delta)
{



	if (FaceRenderer->IsUpdate() == true)
	{
		
		
	}





	/*float FirstPoseChange = NewRand.RandomFloat(0.5f, 2.0f);
	float4 PoseTime = NewRand.RandomFloat(3.0f, 4.0f);*/

	StateUpdate(_Delta);

}

void NormalTraveler::LevelEnd(GameEngineLevel* _Next)
{
	Death();
}


void NormalTraveler::RandomSetTravelerInfo()
{

	int intRand = TimeRand.RandomInt(0, 1);
	Info.Sex = intRand;
	intRand = TimeRand.RandomInt(0, 6);
	Info.OriginCountry = static_cast<Country>(intRand);
	intRand = TimeRand.RandomInt(0, 2);
	Info.City = intRand;


	RandomSetFace();


	{
		Info.Date_of_Birth.resize(3);
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


void NormalTraveler::RandomSetFace()
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
		FaceRenderer->CreateAnimation("Face", Info.Face.SheetName.c_str(), 1.0f, Info.Face.SheetX * 2 + Info.Face.SheetY, Info.Face.SheetX * 2 + Info.Face.SheetY, false);
		FaceRenderer->ChangeAnimation("Face");
		FaceRenderer->AutoSpriteSizeOn();
		FaceRenderer->SetAutoScaleRatio(2.0f);
		FaceRenderer->Off();



	}


}

void NormalTraveler::WaitingStandStart()
{
}


void NormalTraveler::WaitingMoveStart()
{
}

void NormalTraveler::TurnStartStart()
{
	FaceRenderer->On();
	FaceRenderer->Transform.SetWorldPosition({ 20,-350 });
	

}

void NormalTraveler::TurnStayStart()
{
}

void NormalTraveler::TurnEndStart()
{
}


void NormalTraveler::WaitingStandUpdate(float _Delta)
{


	if (0.0f >= StandingChangeTime)
	{
		if (OuterRenderer->IsCurAnimation("NormalTravelerStand1"))
		{
			OuterRenderer->ChangeAnimation("NormalTravelerStand2");
		}

		else if (OuterRenderer->IsCurAnimation("NormalTravelerStand2"))
		{
			OuterRenderer->ChangeAnimation("NormalTravelerStand1");
		}


		StandingChangeTime = TimeRand.RandomFloat(2.5f, 3.5f);


	}


	StandingChangeTime -= _Delta;

}

void NormalTraveler::WaitingMoveUpdate(float _Delta)
{

}

void NormalTraveler::TurnStartUpdate(float _Delta)
{
}

void NormalTraveler::TurnStayUpdate(float _Delta)
{
}

void NormalTraveler::TurnEndUpdate(float _Delta)
{
}

void NormalTraveler::StateUpdate(float _Delta)
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

void NormalTraveler::ChanageState(TravelerState _State)
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

void NormalTraveler::ChangeAnimationState(std::string_view _State)
{
}

//Inner 로 들어올때 와 나갈때 조금 Rotation을 돌린다?
