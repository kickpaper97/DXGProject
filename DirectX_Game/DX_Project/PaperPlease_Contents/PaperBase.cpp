#include "PreCompile.h"
#include "PaperBase.h"

#include "Cursor.h"

PaperBase::PaperBase()
{
}

PaperBase::~PaperBase()
{
}

void PaperBase::SetPaperTexture(std::string_view _Name)
{
	
	std::string Name = _Name.data();
	
	//std::shared_ptr< GameEngineSprite > InnerSprite= GameEngineSprite::Find(Name + "Inner.png");
	//std::shared_ptr< GameEngineSprite > OuterSprite = GameEngineSprite::Find(Name + "Outer.png");

	SetPaperTexture(Name + "Inner.png", Name + "Outer.png");

	/*InnerRenderer->SetSprite(Name + "Inner.png");
	OuterRenderer->SetSprite(Name + "Outer.png");*/



}

void PaperBase::SetPaperTexture(std::string_view _InnerName, std::string_view _OuterName)
{
	if (InnerRenderer == nullptr)
	{
		InnerRenderer = CreateComponent<GameEngineSpriteRenderer>();
		OuterRenderer = CreateComponent<GameEngineSpriteRenderer>();
	}

	InnerRenderer->SetSprite(_InnerName);
	OuterRenderer->SetSprite(_OuterName);

	
}

void PaperBase::Start()
{
	/*PaperRenderer = CreateComponent<GameEngineSpriteRenderer>(10);
	PaperRenderer->SetAutoScaleRatio(2.0f);*/
	
	{
		Collision = CreateComponent<GameEngineCollision>(CollisionOrder::Papers);
		Collision->SetCollisionType(ColType::AABBBOX2D);
	}
}

void PaperBase::Update(float _Delta)
{
	

	

}
