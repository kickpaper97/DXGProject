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
	if (nullptr == GameEngineSprite::Find("NormalTravelerAni.Png"))
	{
		GameEngineSprite::CreateCut("NormalTravelerAni.Png", 10, 5);
	}

	{
		OuterSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::People);
		OuterSpriteRenderer->SetRenderOrder(RenderOrder::People);
		OuterSpriteRenderer->AutoSpriteSizeOn();
		OuterSpriteRenderer->SetAutoScaleRatio(2.0f);
		OuterSpriteRenderer->CreateAnimation("NormalTravelerHorizonWalk", "NormalTravelerAni.Png", 0.1f, 40, 43, true);
		OuterSpriteRenderer->ChangeAnimation("NormalTravelerHorizonWalk");
		
		
		//MainSpriteRenderer->CreateAnimation("Run", "HoHoYee_AttackABC", 0.05f, -1, -1, true);
		//MainSpriteRenderer->ChangeAnimation("Run");
		//MainSpriteRenderer->SetSamplerState(SamplerOption::LINEAR);
		//MainSpriteRenderer->Transform.SetLocalPosition({ 100.0f, 0.0f, 0.0f });

		//MainSpriteRenderer->SetEndEvent("Run", std::bind(&Player::TestEvent, this, std::placeholders::_1));

		//// MainSpriteRenderer->Transform.SetLocalScale({5, 5});
		
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ 450.0f, -170.0f, -500.0f });


	OuterSpriteRenderer->LeftFlip();
}

void Player::TestEvent(GameEngineRenderer* _Renderer)
{
	int a = 0;
}

void Player::Update(float _Delta)
{
	


	if(OuterSpriteRenderer->IsUpdate() && 350.0f <= Transform.GetLocalPosition().X)
	{
		Transform.AddLocalPosition(float4::LEFT*20 * _Delta);
		if (370.0f >= Transform.GetLocalPosition().X)
		{
			OuterSpriteRenderer->Off();
		}
	}
	

	// float4 Color = GetColor(Transform.GetWorldPosition());
}