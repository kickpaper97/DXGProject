#include "PreCompile.h"
#include "StampBar.h"

StampBar::StampBar()
{
}

StampBar::~StampBar()
{
}

void StampBar::Start()
{

	if (nullptr == GameEngineSprite::Find("Sta"))
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
	BarTopRenderer->SetRenderOrder(RenderOrder::StampBars);

}

void StampBar::Update(float _Delta)
{
}
