#include "PreCompile.h"
#include "RuleBook.h"

RuleBook::RuleBook()
{
}

RuleBook::~RuleBook()
{
}

void RuleBook::Start()
{
	

	GameEngineSprite::CreateSingle("RulesInnerHome.png");
	GameEngineSprite::CreateSingle("RulesOuter.png");



	Pages.resize(20);
	Pages[0] = (GameEngineSprite::Find("RulesInnerHome.png"));

	PaperBase::Start();

	SetPaperTexture(Pages[0]->GetName(), "RulesOuter.png");
	//InnerRenderer->SetSprite(GetInnerTexture()->GetName());
	//InnerRenderer->SetRenderOrder(RenderOrder::Play);



	{
		GameEngineInput::AddInputObject(this);
		Transform.SetLocalPosition({ 500,-150 });

	}
	{
		
		float4 SpriteRenderScale = InnerRenderer->GetImageTransform().GetLocalScale();
		Collision->Transform.SetLocalScale(SpriteRenderScale);
		
	}

}

void RuleBook::Update(float _Delta)
{
	if (GameEngineInput::IsPress('A',this))
	{
		Transform.AddLocalPosition(float4::LEFT * _Delta * 100);
	}

	if (GameEngineInput::IsPress('D',this))
	{
		Transform.AddLocalPosition(float4::RIGHT * _Delta * 100);
	}

	if (GameEngineInput::IsPress('W', this))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * 100);
	}

	if (GameEngineInput::IsPress('S', this))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * 100);
	}
}
