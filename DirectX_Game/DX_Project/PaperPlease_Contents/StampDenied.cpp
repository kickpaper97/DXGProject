#include "PreCompile.h"
#include "StampDenied.h"
#include "Stamp.h"

StampDenied::StampDenied()
{
}

StampDenied::~StampDenied()
{
}
void StampDenied::Start()
{
	if (nullptr == GameEngineSprite::Find("StampBotDenied.png"))
	{
		GameEngineSprite::CreateSingle("StampBotDenied.png");
		GameEngineSprite::CreateSingle("StampTop.png");


	}


	{
		StampRenderer = CreateComponent<GameEngineSpriteRenderer>();
		StampRenderer->SetRenderOrder(RenderOrder::Stamp);
		StampRenderer->AutoSpriteSizeOn();
		StampRenderer->SetAutoScaleRatio(2.0f);
		StampRenderer->SetSprite("StampBotDenied.png");
		StampRenderer->Transform.SetLocalPosition({ -124.5f,43 });

		StampTop = CreateComponent<GameEngineSpriteRenderer>();
		StampTop->SetRenderOrder(RenderOrder::Stamp);
		StampTop->SetParent(StampRenderer);

		StampTop->AutoSpriteSizeOn();
		StampTop->SetAutoScaleRatio(2.0f);
		StampTop->SetSprite("StampTop.png");
		StampTop->Transform.SetLocalPosition({ 0,74 });

		{
			std::shared_ptr<GameEngineCollision> StampCollision = CreateComponent<GameEngineCollision>(CollisionOrder::StampApproved);
			StampCollision->SetParent(StampRenderer);
			StampCollision->SetCollisionType(ColType::AABBBOX2D);
			StampCollision->Transform.SetLocalScale({ 150,130 });
			StampCollision->Transform.SetLocalPosition(float4::ZERO);
		}
		{
			std::shared_ptr<GameEngineCollision> StampCollision = CreateComponent<GameEngineCollision>(CollisionOrder::StampApproved);
			StampCollision->SetParent(StampTop);
			StampCollision->SetCollisionType(ColType::SPHERE2D);
			StampCollision->Transform.SetLocalScale({ 54,54 });
			StampCollision->Transform.SetLocalPosition({ 0,9 });

		}
		{
			std::shared_ptr<GameEngineCollision> StampCollision = CreateComponent<GameEngineCollision>(CollisionOrder::StampApproved);
			StampCollision->SetParent(StampTop);
			StampCollision->SetCollisionType(ColType::AABBBOX2D);
			StampCollision->Transform.SetLocalScale({ 52,30 });
			StampCollision->Transform.SetLocalPosition({ 0,-10 });
		}

	}

}

void StampDenied::Update(float _Delta)
{


}