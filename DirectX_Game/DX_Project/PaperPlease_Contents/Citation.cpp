#include "PreCompile.h"
#include "Citation.h"

Citation::Citation()
{
}

Citation::~Citation()
{
}

void Citation::Start()
{
	if (nullptr == GameEngineSprite::Find("CitationInner.png"))
	{
		GameEngineSprite::CreateSingle("CitationOuter.png");
		GameEngineSprite::CreateSingle("CitationInner.png");

	}

	PaperBase::Start();
	SetPaperTexture("CitationInner.png", "CitationOuter.png");

}

void Citation::Update(float _Delta)
{
	PaperBase::Update(_Delta);


}
