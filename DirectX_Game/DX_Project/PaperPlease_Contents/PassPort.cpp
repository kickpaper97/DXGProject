#include "PreCompile.h"
#include "PassPort.h"
#include "NormalTraveler.h"
#include "CustomSpriteRenderer.h"
#include "Cursor.h"
#include "InkApproved.h"

PassPort::PassPort()
{
}

PassPort::~PassPort()
{
}

void PassPort::SetOwner(std::shared_ptr<class NormalTraveler> _Owner)
{
	Owner = _Owner;
	Info = _Owner.get()->GetInfo();
}

void PassPort::StampPassPort(PassPortChecked _Check, float4 _WorldStampPos)
{
	std::shared_ptr<CustomSpriteRenderer>StampSpriteRenderer=  std::dynamic_pointer_cast<CustomSpriteRenderer>(InnerRenderer->CreateChild<CustomSpriteRenderer>(10));
	
	//std::shared_ptr<CustomSpriteRenderer>StampSpriteRenderer = CreateComponent <CustomSpriteRenderer>();
	StampSpriteRenderer->AutoSpriteSizeOn();
	StampSpriteRenderer->SetAutoScaleRatio(2.0f);

	StampSpriteRenderer->SetMaskTexture("Desk_Mask.png");
	


	switch (_Check)
	{
	case PassPortChecked::Approved:

	{
		//std::shared_ptr<InkApproved> NewInk = CreateComponent<InkApproved>();

	}
		if (EntryCheck == PassPortChecked::Yet)
		{
			EntryCheck = PassPortChecked::Approved;
		}
		
		break;
	case PassPortChecked::Denied:
		StampSpriteRenderer->SetSprite("InkDenied.png");
		if (EntryCheck == PassPortChecked::Yet)
		{
			EntryCheck = PassPortChecked::Denied;
		}

		break;


	
	default:
		break;
	}
	std::string ad = InnerRenderer->GetSprite()->GetName().data();
	StampSpriteRenderer->SetPassPortTexture(InnerRenderer->GetSprite()->GetName(), Transform.GetLocalPosition());


	float4 StampPos = this->Transform.GetWorldPosition() - _WorldStampPos;
	StampPos *= -1;
	StampSpriteRenderer->RenderBaseInfoValue.RendererScreenPos = StampPos;
	StampSpriteRenderer->Transform.SetLocalPosition(StampPos);
	
}

void PassPort::Start()
{
	
	

	if (nullptr == GameEngineSprite::Find("InkApproved.png"))
	{
		GameEngineSprite::CreateSingle("InkApproved.png");
		GameEngineSprite::CreateSingle("InkDenied.png");

	}

	PaperBase::Start();
	

	switch (Info.OriginCountry)
	{
	case Country::Arstotzka:
		SetPaperTexture("PassportArstotzka");
		break;
	case Country::Antegria:
		SetPaperTexture("PassportAntegria");

		break;
	case Country::Impor:
		SetPaperTexture("PassportAImpor");

		break;
	case Country::Kolechia:
		SetPaperTexture("PassportKolechia");

		break;
	case Country::Obristan:
		SetPaperTexture("PassportObristan");

		break;
	case Country::Republia:
		SetPaperTexture("PassportRepublia");

		break;
	case Country::United_Federation:
		SetPaperTexture("PassportUnitedFed");


		break;


	default:
		SetPaperTexture("PassportArstotzka");

		break;
	}
	

	OuterRenderer->SetAutoScaleRatio(1.0f);
	
	
	GameEngineInput::AddInputObject(this);


}

void PassPort::Update(float _Delta)
{
	PaperBase::Update(_Delta);

	if (GameEngineInput::IsDown(VK_RBUTTON, this))
	{
		float4 pos = Cursor::MainCursor->Transform.GetWorldPosition();
		StampPassPort(PassPortChecked::Approved, pos );



	}


	//this->Childs


}

void PassPort::SetPaperTexture(std::string_view _Name)
{

	std::string Name = _Name.data();

	//std::shared_ptr< GameEngineSprite > InnerSprite= GameEngineSprite::Find(Name + "Inner.png");
	//std::shared_ptr< GameEngineSprite > OuterSprite = GameEngineSprite::Find(Name + "Outer.png");

	if (nullptr == GameEngineSprite::Find(Name + "Inner.png"))
	{
		GameEngineSprite::CreateSingle(Name + "Inner.png");
		GameEngineSprite::CreateSingle(Name + "Outer.png");

	}



	PaperBase::SetPaperTexture(Name + "Inner.png", Name + "Outer.png");
	
	/*InnerRenderer->SetSprite(Name + "Inner.png");
	OuterRenderer->SetSprite(Name + "Outer.png");*/



}


