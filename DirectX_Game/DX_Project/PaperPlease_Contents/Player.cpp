#include "PreCompile.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>
#include "PlayMap.h"

Player* Player::MainPlayer;

Player::Player() 
{
	MainPlayer = this;
}

Player::~Player() 
{
}

void Player::Start()
{
	if (nullptr == GameEngineSprite::Find("NomalTravelerAni.Png"))
	{
		GameEngineSprite::CreateCut("NomalTravelerAni.Png", 10, 5);
	}

	{
		OuterSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::People);
		OuterSpriteRenderer->SetRenderOrder(RenderOrder::People);
		OuterSpriteRenderer->AutoSpriteSizeOn();
		OuterSpriteRenderer->SetAutoScaleRatio(2.0f);
		OuterSpriteRenderer->CreateAnimation("NomalTravelerHorizonWalk", "NomalTravelerAni.Png", 0.1f, 40, 43, true);
		OuterSpriteRenderer->ChangeAnimation("NomalTravelerHorizonWalk");
		
		OuterSpriteRenderer->LeftFlip();
		//MainSpriteRenderer->CreateAnimation("Run", "HoHoYee_AttackABC", 0.05f, -1, -1, true);
		//MainSpriteRenderer->ChangeAnimation("Run");
		//MainSpriteRenderer->SetSamplerState(SamplerOption::LINEAR);
		//MainSpriteRenderer->Transform.SetLocalPosition({ 100.0f, 0.0f, 0.0f });

		//MainSpriteRenderer->SetEndEvent("Run", std::bind(&Player::TestEvent, this, std::placeholders::_1));

		//// MainSpriteRenderer->Transform.SetLocalScale({5, 5});
		
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ 480.0f, -170.0f, -500.0f });

}

void Player::TestEvent(GameEngineRenderer* _Renderer)
{
	int a = 0;
}

void Player::Update(float _Delta)
{
	


	if(OuterSpriteRenderer->IsUpdate() && 350.0f <= Transform.GetLocalPosition().X)
	{
		Transform.AddLocalPosition(float4::LEFT*10 * _Delta);
		if (370.0f >= Transform.GetLocalPosition().X)
		{
			OuterSpriteRenderer->Off();
		}
	}
	
	
	/*

	

	float Speed = 100.0f;

	if (GameEngineInput::IsDown('A'))
	{
		MainSpriteRenderer->AnimationPauseSwitch();
	}


	if (GameEngineInput::IsPress('A'))
	{
		Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('Q'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });
	}

	if (GameEngineInput::IsPress('E'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, -360.0f * _Delta });
	}*/

	//GameEngineColor Color = PlayMap::MainMap->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	//if (GameEngineColor::RED != Color)
	//{
	//	GrivityForce.Y -= _Delta * 100.0f;
	//	Transform.AddLocalPosition(GrivityForce * _Delta);
	//}
	//else 
	//{
	//	GrivityForce = 0.0f;
	//}
	// ���� ���ٰ��ϰ� �ʹٸ� while������ �÷��ּ���.


	// float4 Color = GetColor(Transform.GetWorldPosition());
}