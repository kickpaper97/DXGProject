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

	if (nullptr == GameEngineSprite::Find(Name + "Inner.png"))
	{
		GameEngineSprite::CreateSingle(Name + "Inner.png");
		GameEngineSprite::CreateSingle(Name + "Outer.png");

	}

	

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

	GameEngineRandom RotationRand;
	RotationRand.SetSeed(reinterpret_cast<long long>(this));

	OuterPaperRotation = { 0.0f,0.0f,RotationRand.RandomFloat(-18.0f, 18.0f) };
	OuterRenderer->Transform.SetLocalRotation(OuterPaperRotation);


	InnerRenderer->AutoSpriteSizeOn();
	OuterRenderer->AutoSpriteSizeOn();
	InnerRenderer->SetAutoScaleRatio(2.0f);
	//OuterRenderer->SetAutoScaleRatio(2.0f);
	InnerRenderer->SetSprite(_InnerName);
	OuterRenderer->SetSprite(_OuterName);
	InnerRenderer->Transform.TransformUpdate();
	OuterRenderer->Transform.TransformUpdate();
	

	if (MASKLINEPOS_X <= Transform.GetWorldPosition().X)
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
			Collision->Transform.SetLocalRotation(OuterPaperRotation);
	}

	
	
}

void PaperBase::SetOuterPaperRotation(const float4& _Rotation)
{
	OuterPaperRotation = _Rotation;
	OuterRenderer->Transform.SetLocalRotation(OuterPaperRotation);
	Collision->Transform.SetLocalRotation(OuterPaperRotation);
	
	OuterRenderer->Transform.TransformUpdate();
}

void PaperBase::SetWrongInfo()
{
}




void PaperBase::Start()
{
	/*PaperRenderer = CreateComponent<GameEngineSpriteRenderer>(10);
	PaperRenderer->SetAutoScaleRatio(2.0f);*/
	
	{
		Collision = CreateComponent<GameEngineCollision>(CollisionOrder::Papers);
		Collision->SetCollisionType(ColType::OBBBOX2D);
	}
}

void PaperBase::Update(float _Delta)
{
	

	if(Parent==Cursor::MainCursor)
	{
	

		float4 Position = Transform.GetWorldPosition();
		float4 CursorPos = Cursor::MainCursor->Transform.GetLocalPosition();

		if (MASKLINEPOS_X >= Transform.GetWorldPosition().X && -MASKLINEPOS_Y <= Transform.GetWorldPosition().Y + OuterRenderer->GetImageTransform().GetLocalScale().hY() )
		{
			
			float4 check = (OuterRenderer->GetImageTransform().GetLocalScale() + Transform.GetLocalPosition().Y);
			float ck = -MASKLINEPOS_Y - Parent->Transform.GetLocalPosition().Y - OuterRenderer->GetImageTransform().GetLocalScale().hY();
			float4 OverPos = { Transform.GetLocalPosition().X,-MASKLINEPOS_Y- Parent->Transform.GetLocalPosition().Y- OuterRenderer->GetImageTransform().GetLocalScale().hY()};
			Transform.SetLocalPosition(OverPos);
			
		}


		if (MASKLINEPOS_X<= CursorPos.X)
		{

			
			
			if (OuterRenderer.get()->IsUpdate())
			{
				

				OuterRenderer->Off();
				InnerRenderer->On();
				Transform.SetLocalPosition(InnerLocalPos);
				float4 SpriteRenderScale = InnerRenderer->GetImageTransform().GetLocalScale();
				Collision->Transform.SetLocalScale(SpriteRenderScale );
				Collision->Transform.SetLocalRotation(float4::ZERO);
				
			}
		}

		else 
		{
			
		/*	if (-MASKLINEPOS_Y <= Transform.GetWorldPosition().Y)
			{
				
				return;
			}*/



			if (InnerRenderer.get()->IsUpdate())
			{

				InnerLocalPos = Transform.GetLocalPosition();
				InnerRenderer->Off();
				OuterRenderer->On();
				Transform.SetLocalPosition(float4::ZERO);
				float4 SpriteRenderScale = OuterRenderer->GetImageTransform().GetLocalScale();
				Collision->Transform.SetLocalScale(SpriteRenderScale );
				Collision->Transform.SetLocalRotation(OuterPaperRotation);

			}

			

		}

	}
	



	
	
		
	


}
