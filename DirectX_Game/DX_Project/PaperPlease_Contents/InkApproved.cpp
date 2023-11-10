#include "PreCompile.h"
#include "InkApproved.h"

#include "CustomSpriteRenderer.h"

InkApproved::InkApproved()
{
}

InkApproved::~InkApproved()
{
}

void InkApproved::Start()
{
	{
		std::shared_ptr<CustomSpriteRenderer>StampSpriteRenderer = CreateComponent< CustomSpriteRenderer>();

			//std::shared_ptr<CustomSpriteRenderer>StampSpriteRenderer = CreateComponent <CustomSpriteRenderer>();
			StampSpriteRenderer->AutoSpriteSizeOn();
		StampSpriteRenderer->SetAutoScaleRatio(2.0f);
		StampSpriteRenderer->SetSprite("InkApproved.png");

		StampSpriteRenderer->SetMaskTexture("Desk_Mask.png");


	//StampSpriteRenderer->SetPassPortTexture(InnerRenderer->GetSprite()->GetName(), Transform.GetLocalPosition());
	}

	/*float4 StampPos = this->Transform.GetWorldPosition() - _WorldStampPos;
	StampPos *= -1;
	StampSpriteRenderer->RenderBaseInfoValue.RendererScreenPos = StampPos;
	StampSpriteRenderer->Transform.SetLocalPosition(StampPos);*/
}

void InkApproved::Update(float _Delta)
{



	


}

