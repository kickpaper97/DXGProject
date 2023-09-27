#include "PreCompile.h"
#include "PaperBase.h"

PaperBase::PaperBase()
{
}

PaperBase::~PaperBase()
{
}

void PaperBase::SetPaperTexture(std::string_view _Name)
{
	
	std::string Name = _Name.data();
	
	
	InnerTexture = GameEngineTexture::Find(Name+"Inner.png");
	OuterTexture= GameEngineTexture::Find(Name + "Outer.png");

}

void PaperBase::SetPaperTexture(std::string_view _InnerName, std::string_view _OuterName)
{
	InnerTexture = GameEngineTexture::Find(_InnerName);
	OuterTexture = GameEngineTexture::Find(_OuterName);
}

void PaperBase::Start()
{
	PaperRenderer = CreateComponent<GameEngineSpriteRenderer>(10);
	PaperRenderer->SetAutoScaleRatio(2.0f);
	

}
