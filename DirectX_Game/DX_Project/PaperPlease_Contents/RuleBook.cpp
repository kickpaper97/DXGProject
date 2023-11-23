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
	
	if (nullptr == GameEngineSprite::Find("RulesInnerHome.png"))
	{
	GameEngineSprite::CreateSingle("RulesOuter.png");
	GameEngineSprite::CreateSingle("RulesInnerHome.png");

	}



	Pages.resize(20);
	Pages[0] = (GameEngineSprite::Find("RulesInnerHome.png"));

	PaperBase::Start();

	SetPaperTexture(Pages[0]->GetName(), "RulesOuter.png");
	OuterRenderer->SetAutoScaleRatio(2.0f); 
	Collision->Transform.SetLocalScale(OuterRenderer->GetImageTransform().GetLocalScale()*2.0f);
	SetOuterPaperRotation(float4::ZERO);
	


	{
		GameEngineInput::AddInputObject(this);
		Transform.SetLocalPosition({ 252,-591 });

	}
	

}

void RuleBook::Update(float _Delta)
{
	PaperBase::Update(_Delta);

	/*if (MASKLINEPOS_X>=Transform.GetWorldPosition().X && -MASKLINEPOS_Y <= Transform.GetWorldPosition().Y)
	{
		float OverPos = -MASKLINEPOS_Y - Transform.GetLocalScale().hY();
		
		Transform.SetWorldPosition({ Transform.GetWorldPosition().X,OverPos });
	}*/

	if (OuterRenderer->IsUpdate() && MASKLINEPOS_X >= Transform.GetWorldPosition().X &&- MASKLINEPOS_Y >= Transform.GetWorldPosition().Y)
	{
		if (dynamic_cast<GameEngineLevel*>(Parent))
		{
			if (Transform.GetLocalPosition().X > AtBoothPos.X)
			{
				Transform.AddLocalPosition(float4::LEFT*600*_Delta);
				if (Transform.GetLocalPosition().X <= AtBoothPos.X)
				{
					Transform.SetLocalPosition({ AtBoothPos.X, Transform.GetLocalPosition().Y });
				}
			}
			else if(Transform.GetLocalPosition().X < AtBoothPos.X)
			{
				Transform.AddLocalPosition(float4::RIGHT*600*_Delta);
				if (Transform.GetLocalPosition().X >= AtBoothPos.X)
				{
					Transform.SetLocalPosition({ AtBoothPos.X ,Transform.GetLocalPosition().Y});
				}
			}

			if (AtBoothPos.X == Transform.GetLocalPosition().X&&AtBoothPos.Y!=Transform.GetLocalPosition().Y)
			{
				Transform.AddLocalPosition(float4::DOWN * 600 * _Delta);
				if (AtBoothPos.Y >= Transform.GetLocalPosition().Y)
				{
					Transform.SetLocalPosition(AtBoothPos);
				}
			}
			
		}

	}


}
