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
	Pages.push_back(GameEngineTexture::Find("RulesInnerHome.png"));

	SetPaperTexture(Pages[0].get()->GetName(), "RulesOuter.png");
	GetSpriteRenderer()->SetSprite(GetInnerTexture().get()->GetName());



	{

	}

}

void RuleBook::Update(float _Delta)
{
}
