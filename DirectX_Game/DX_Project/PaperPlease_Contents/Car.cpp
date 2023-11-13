#include "PreCompile.h"
#include "Car.h"

Car::Car()
{
}

Car::~Car()
{
}

void Car::Start()
{
	if (nullptr == GameEngineSprite::Find("CarAni.png"))
	{
		GameEngineSprite::CreateCut("CarAni.png",3,1);
		GameEngineSprite::CreateSingle("Outer_Mask.png");

	}

	std::shared_ptr<GameEngineSpriteRenderer> SpriteRenderer = CreateComponent<GameEngineSpriteRenderer>();
	SpriteRenderer->CreateAnimation("CarMove", "CarAni.png", 0.1f, 2, 2, false);
	SpriteRenderer->ChangeAnimation("CarMove");
	SpriteRenderer->SetMaskTexture("Outer_Mask.png");
	SpriteRenderer->AutoSpriteSizeOn();
	SpriteRenderer->SetAutoScaleRatio(2.0f);
	Transform.SetLocalPosition({ 1100,800 });
}

void Car::Update(float _Delta)
{
	Transform.AddLocalPosition(float4::DOWN * 400 * _Delta);

	if (-1600.0f >= Transform.GetLocalPosition().Y)
	{
		Transform.SetLocalPosition({ 1100,50 });
	}

		
}
