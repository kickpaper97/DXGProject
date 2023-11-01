#include "PreCompile.h"
#include "StampApproved.h"
#include "CustomSpriteRenderer.h"

StampApproved::StampApproved()
{
}

StampApproved::~StampApproved()
{
}

void StampApproved::Start()
{
	if (nullptr == GameEngineSprite::Find("InkApproved.png"))
	{
		GameEngineSprite::CreateSingle("InkApproved.png");
		

	}


	std::shared_ptr<CustomSpriteRenderer> StampRenderer = CreateComponent<CustomSpriteRenderer>();
	

	StampRenderer->AutoSpriteSizeOn();
	StampRenderer->SetAutoScaleRatio(2.0f);
	StampRenderer->SetSprite("InkApproved.png");

	GameEngineInput::AddInputObject(this);
}

void StampApproved::Update(float _Delta)
{
	if (GameEngineInput::IsDown(VK_RBUTTON, this))
	{

	}

}
