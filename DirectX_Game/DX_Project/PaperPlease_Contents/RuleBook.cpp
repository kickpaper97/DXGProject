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
	
	if (nullptr == GameEngineSprite::Find("RulesInnerHome.png"))
	{
	GameEngineSprite::CreateSingle("RulesOuter.png");
	GameEngineSprite::CreateSingle("RulesInnerHome.png");

	}



	Pages.resize(20);
	Pages[0] = (GameEngineSprite::Find("RulesInnerHome.png"));

	PaperBase::Start();

	SetPaperTexture(Pages[0]->GetName(), "RulesOuter.png");
	



	{
		GameEngineInput::AddInputObject(this);
		Transform.SetLocalPosition({ 500,-150 });

	}
	

}

void RuleBook::Update(float _Delta)
{
	PaperBase::Update(_Delta);

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

	if (GameEngineInput::IsPress('L', this))
	{
		InnerRenderer->SetMaskTexture("Outer_Mask.png");
	}
	if (GameEngineInput::IsPress('K', this))
	{
		InnerRenderer->SetMaskTexture("Inner_Mask.png");
	}
}
