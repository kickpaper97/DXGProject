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
		InnerRenderer->SetMaskTexture("Desk_Mask.png");
		OuterRenderer = CreateComponent<GameEngineSpriteRenderer>();
		OuterRenderer->SetMaskTexture("Inner_Mask.png");
	}

	InnerRenderer->AutoSpriteSizeOn();
	OuterRenderer->AutoSpriteSizeOn();
	InnerRenderer->SetAutoScaleRatio(2.0f);
	OuterRenderer->SetAutoScaleRatio(2.0f);
	InnerRenderer->SetSprite(_InnerName);
	OuterRenderer->SetSprite(_OuterName);
	InnerRenderer->Transform.TransformUpdate();
	OuterRenderer->Transform.TransformUpdate();
	

	if (LINEPOS_X > Transform.GetWorldPosition().X)
	{

			OuterRenderer->Off();
			InnerRenderer->On();
			float4 SpriteRenderScale = InnerRenderer->GetImageTransform().GetLocalScale();
			Collision->Transform.SetLocalScale(SpriteRenderScale);

	}
	else
	{
		
			InnerRenderer->Off();
			OuterRenderer->On();
			float4 SpriteRenderScale = OuterRenderer->GetImageTransform().GetLocalScale();
			Collision->Transform.SetLocalScale(SpriteRenderScale);

	}

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

	if(Parent==Cursor::MainCursor)
	{
		float4 Position = Transform.GetWorldPosition();
		float4 CursorPos = Cursor::MainCursor->Transform.GetLocalPosition();


		if (LINEPOS_X<= CursorPos.X)
		{

			
			
			if (OuterRenderer.get()->IsUpdate())
			{
				

				OuterRenderer->Off();
				InnerRenderer->On();
				float4 SpriteRenderScale = InnerRenderer->GetImageTransform().GetLocalScale();
				Collision->Transform.SetLocalScale(SpriteRenderScale );
				
				
			}
		}

		else 
		{
			InnerLocalPos = Transform.GetLocalPosition();

			if (InnerRenderer.get()->IsUpdate())
			{

				InnerRenderer->Off();
				OuterRenderer->On();
				Transform.SetLocalPosition(float4::ZERO);
				float4 SpriteRenderScale = OuterRenderer->GetImageTransform().GetLocalScale();
				Collision->Transform.SetLocalScale(SpriteRenderScale );

			}
		}

	}
}
