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

	OuterRenderer = CreateComponent<GameEngineSpriteRenderer>();
	OuterRenderer->SetMaterial("Overlay");
	{
		OuterRenderer->CreateAnimation("NomalTravelerStand1", "NomalTravelerAni.Png",13,13,0.1f,false);
		OuterRenderer->CreateAnimation("NomalTravelerStand2", "NomalTravelerAni.Png",14,14,0.1f,false);
		
		OuterRenderer->CreateAnimation("NomalTravelerHorizonWalk", "NomalTravelerAni.Png", 40, 43, 0.1f, true);
		OuterRenderer->CreateAnimation("NomalTravelerVerticalWalk", "NomalTravelerAni.Png", 44, 47, 0.1f, true);

		

	}

	{
		GameEngineRandom NewRand;
		NewRand.SetSeed(reinterpret_cast<long long>(this));
		int FirstPose = NewRand.RandomInt(0, 1);

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
	}

	

}

void NomalTraveler::Update(float _Delta)
{




	/*float FirstPoseChange = NewRand.RandomFloat(0.5f, 2.0f);
	float4 PoseTime = NewRand.RandomFloat(3.0f, 4.0f);*/

}

//Inner 로 들어올때 와 나갈때 조금 Rotation을 돌린다?
