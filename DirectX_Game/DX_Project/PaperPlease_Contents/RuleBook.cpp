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
	



	{
		GameEngineInput::AddInputObject(this);
		Transform.SetLocalPosition({ 200,-300 });

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


	if (GameEngineInput::IsPress('A',this))
	{
		Transform.AddLocalPosition(float4::LEFT * _Delta * 100);
	}

	if (GameEngineInput::IsPress('D',this))
	{
		Transform.AddLocalPosition(float4::RIGHT * _Delta * 100);
	}

	if (GameEngineInput::IsPress('W', this))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * 100);
	}

	if (GameEngineInput::IsPress('S', this))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * 100);
	}

	if (GameEngineInput::IsPress('L', this))
	{
		InnerRenderer->SetMaskTexture("Outer_Mask.png");
	}
	if (GameEngineInput::IsPress('K', this))
	{
		InnerRenderer->SetMaskTexture("Inner_Mask.png");
	}
}
