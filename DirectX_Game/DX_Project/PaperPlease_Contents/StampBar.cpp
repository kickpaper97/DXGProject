#include "PreCompile.h"
#include "StampBar.h"
#include "StampApproved.h"
#include "StampDenied.h"
#include "Stamp.h"

StampBar::StampBar()
{
}

StampBar::~StampBar()
{
}

void StampBar::Start()
{

	if (nullptr == GameEngineSprite::Find("StampBarBot.png"))
	{
		GameEngineSprite::CreateSingle("StampBarBot.png");
		GameEngineSprite::CreateSingle("StampBarMid.png");
		GameEngineSprite::CreateSingle("StampBarTop.png");

		GameEngineSprite::CreateSingle("StampBotApproved.png");
		GameEngineSprite::CreateSingle("StampBotDenied.png");
		GameEngineSprite::CreateSingle("StampTop.png");

		

	}
	
	std::shared_ptr<GameEngineSpriteRenderer> BarBotRenderer = CreateComponent<GameEngineSpriteRenderer>();
	std::shared_ptr<GameEngineSpriteRenderer> BarMidRenderer = CreateComponent<GameEngineSpriteRenderer>();
	std::shared_ptr<GameEngineSpriteRenderer> BarTopRenderer = CreateComponent<GameEngineSpriteRenderer>();

	BarBotRenderer->AutoSpriteSizeOn();
	BarMidRenderer->AutoSpriteSizeOn();
	BarTopRenderer->AutoSpriteSizeOn();
	BarBotRenderer->SetAutoScaleRatio(2.0f);
	BarMidRenderer->SetAutoScaleRatio(2.0f);
	BarTopRenderer->SetAutoScaleRatio(2.0f);
	BarBotRenderer-> SetSprite("StampBarBot.png");
	BarMidRenderer->SetSprite("StampBarMid.png");
	BarTopRenderer->SetSprite("StampBarTop.png");

	BarBotRenderer->SetRenderOrder(RenderOrder::StampBarBot);
	BarMidRenderer->SetRenderOrder(RenderOrder::StampBars);
	BarTopRenderer->SetRenderOrder(RenderOrder::StampTop);

	BarTopRenderer->Transform.SetLocalPosition({ 0,63 });
	BarBotRenderer->Transform.SetLocalPosition({ 0,-35});

	GameEngineInput::AddInputObject(this);
	//Stamp Switch Collsion
	{
	{

	std::shared_ptr<GameEngineCollision> SwitchCol = CreateComponent<GameEngineCollision>(CollisionOrder::StampSwitch);
	SwitchCol->SetCollisionType(ColType::AABBBOX2D);
	SwitchCol->Transform.SetLocalScale({ 76,115 });
	SwitchCol->Transform.SetLocalPosition({ -5,40 });

	}

	{

		std::shared_ptr<GameEngineCollision> SwitchCol = CreateComponent<GameEngineCollision>(CollisionOrder::StampSwitch);
		SwitchCol->SetCollisionType(ColType::AABBBOX2D);
		SwitchCol->Transform.SetLocalScale({ 74,115 });
		SwitchCol->Transform.SetLocalPosition({ -240,40 });

	}

	{

		std::shared_ptr<GameEngineCollision> SwitchCol = CreateComponent<GameEngineCollision>(CollisionOrder::StampSwitch);
		SwitchCol->SetCollisionType(ColType::AABBBOX2D);
		SwitchCol->Transform.SetLocalScale({ 74,115 });
		SwitchCol->Transform.SetLocalPosition({ 235,40 });

	}

	}

	

	//ON
	{
		
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{

			};
		StatePara.Stay = [=](float _Delta,GameEngineState* _Parent)
			{

			};
		StatePara.End = [=](GameEngineState* _Parent)
			{

			};
		State.CreateState(StampBarState::ON, StatePara);
	}

	//Off
	{

		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{

			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{

			};
		StatePara.End = [=](GameEngineState* _Parent)
			{

			};
		State.CreateState(StampBarState::OFF, StatePara);
	}

	State.ChangeState(StampBarState::OFF);

	PosOff = { 1400,-500 };
	

	Transform.SetLocalPosition(PosOff);
	GameEngineInput::AddInputObject(this);
}

void StampBar::Update(float _Delta)
{
	if (GameEngineInput::IsPress('D', this))
	{
		Transform.AddLocalPosition(float4::RIGHT);
	}
	{
		EventParameter Para;
		Para.Stay = [=](GameEngineCollision* _This, class GameEngineCollision* _Other)
			{

			};
		
	}


}
