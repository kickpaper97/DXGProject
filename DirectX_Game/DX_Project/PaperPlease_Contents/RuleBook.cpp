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
	Pages[0] = (GameEngineTexture::Find("RulesInnerHome.png"));

	PaperBase::Start();

	SetPaperTexture(Pages[0]->GetName(), "RulesOuter.png");
	GetSpriteRenderer()->SetSprite(GetInnerTexture()->GetName());
	GetSpriteRenderer()->SetRenderOrder(RenderOrder::Play);



	{
		Transform.SetLocalPosition({ 500,-150 });

	}
	{
		std::shared_ptr<GameEngineCollision> Collision = GetCollision();
		float4 SpriteRenderScale = GetSpriteRenderer()->GetImageTransform().GetLocalScale();
		Collision->Transform.SetLocalScale(SpriteRenderScale);
		
	}

}

void RuleBook::Update(float _Delta)
{
	
}
