#include "PreCompile.h"
#include "PaperBase.h"

PaperBase::PaperBase()
{
}

PaperBase::~PaperBase()
{
}

void PaperBase::SetTexture(std::string_view _Name)
{
	
	std::string Name = _Name.data();
	
	
	InnerTexture = GameEngineTexture::Find(Name+"Inner.png");
	OuterTexture= GameEngineTexture::Find(Name + "Outer.png");

}

void PaperBase::Start()
{
	PaperRenderer = CreateComponent<GameEngineSpriteRenderer>(10);
	PaperRenderer->SetAutoScaleRatio(2.0f);
	

}
