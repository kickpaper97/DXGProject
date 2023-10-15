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
		Transform.SetLocalPosition({ 500,-150 });

	}
	{
		
		float4 SpriteRenderScale = InnerRenderer->GetImageTransform().GetLocalScale();
		Collision->Transform.SetLocalScale(SpriteRenderScale);
		
	}

}

void RuleBook::Update(float _Delta)
{
	
}
