#include "PreCompile.h"
#include "PassPort.h"

#include "NormalTraveler.h"
#include "CustomSpriteRenderer.h"
#include "Cursor.h"
#include "StampApproved.h"
#include "StampDenied.h"
#include "PaperManager.h"

PassPort::PassPort()
{
}

PassPort::~PassPort()
{
}

void PassPort::Start()
{
	
	

	if (nullptr == GameEngineSprite::Find("InkApproved.png"))
	{
		GameEngineSprite::CreateSingle("InkApproved.png");
		GameEngineSprite::CreateSingle("InkDenied.png");

	}



	if (nullptr == GameEngineSprite::Find("dSheetF0.Png"))
	{
		
		GameEngineSprite::CreateCut("dSheetF0.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetF1.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetF2.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetF3.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetF4.png", 2, 2);

		GameEngineSprite::CreateCut("dSheetM0.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetM1.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetM2.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetM3.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetM4.png", 2, 2);
		GameEngineSprite::CreateCut("dSheetM5.png", 2, 2);

		GameEngineSprite::CreateSingle("Testmask.png");

	}



	PlayPaper::Start();

	
	Transform.SetLocalPosition({150,-450 });
	GameEngineInput::AddInputObject(this);


}

void PassPort::Update(float _Delta)
{
	PlayPaper::Update(_Delta);



	


	{
		EventParameter Para;

		
		Para.Enter = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{


			};
		Para.Stay = [=](class GameEngineCollision* _This, class GameEngineCollision*_Other)
			{
				std::shared_ptr< StampApproved> Approvedptr = _Other->GetActor()->GetDynamic_Cast_This<StampApproved>();
				if (nullptr != Approvedptr)
				{

						StampPassPort(PassPortChecked::Approved, _Other->Transform.GetWorldPosition());

				}

				std::shared_ptr< StampDenied> Deniedptr = _Other->GetActor()->GetDynamic_Cast_This<StampDenied>();
				if (nullptr != Deniedptr)
				{

					StampPassPort(PassPortChecked::Denied, _Other->Transform.GetWorldPosition());

				}
				//std::shared_ptr< StampApproved> ptr = _Other->GetActor()->GetDynamic_Cast_This<StampApproved>()

			};

		Collision->CollisionEvent(CollisionOrder::Ink, Para);

	}




	//this->Childs


}

void PassPort::SetOwner(std::shared_ptr<class NormalTraveler> _Owner)
{
	Owner = _Owner;
	Info = _Owner.get()->GetInfo();


	switch (Info.OriginCountry)
	{
	case Country::Arstotzka:
		SetPaperTexture("PassportArstotzka");
		break;
	case Country::Antegria:
		SetPaperTexture("PassportAntegria");

		break;
	case Country::Impor:
		SetPaperTexture("PassportImpor");

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


		break;
	}


	

	
	
	
	



	

	
	//Picture->Transform.SetLocalPosition()


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
	OuterRenderer->SetAutoScaleRatio(1.0f);


	Picture = CreateComponent<GameEngineSpriteRenderer>();
	Picture->SetMaskTexture("Desk_Mask.png");
	//Picture->ChangeParent(dynamic_cast<GameEngineObject*>(InnerRenderer));
	std::string PictureName = "d" + Info.Face.SheetName;
	Picture->CreateAnimation("FacePicture", PictureName, 0.1f, Info.Face.SheetX * 2 + Info.Face.SheetY, Info.Face.SheetX * 2 + Info.Face.SheetY, false);
	Picture->ChangeAnimation("FacePicture");
	Picture->AutoSpriteSizeOn();
	Picture->SetAutoScaleRatio(0.5f);
	//Picture->Transform.SetLocalScale({})
		
	
	/*InnerRenderer->SetSprite(Name + "Inner.png");
	OuterRenderer->SetSprite(Name + "Outer.png");*/



}
void PassPort::StampPassPort(PassPortChecked _Check, float4 _WorldStampPos)
{
	std::shared_ptr<CustomSpriteRenderer>StampSpriteRenderer= CreateComponent <CustomSpriteRenderer>();
	StampSpriteRenderer->SetParent(InnerRenderer);
	StampSpriteRenderer->Transform.SetLocalPosition(_WorldStampPos-Transform.GetWorldPosition());
	StampSpriteRenderer->SetMaskTexture("PassportMask.png", MyMaskMode::DynamicMask);
	StampSpriteRenderer->SetPassPortTexture("Desk_Mask.png");

	StampSpriteRenderer->RenderBaseInfoValue.MaskPivot =-(StampSpriteRenderer->Transform.GetLocalPosition());

	
	StampSpriteRenderer->AutoSpriteSizeOn();
	StampSpriteRenderer->SetAutoScaleRatio(2.0f);
	


	switch (_Check)
	{
	case PassPortChecked::Approved:

	StampSpriteRenderer->SetSprite("InkApproved.png");


		if (EntryCheck == PassPortChecked::Yet)
		{
			EntryCheck = PassPortChecked::Approved;
			PaperManager::MainPaperManager->SetPassPortEntryCheck(EntryCheck);
			
		}
		
		break;
	case PassPortChecked::Denied:
		StampSpriteRenderer->SetSprite("InkDenied.png");
		if (EntryCheck == PassPortChecked::Yet)
		{
			EntryCheck = PassPortChecked::Denied;
			PaperManager::MainPaperManager->SetPassPortEntryCheck(EntryCheck);
			


		}

		break;


	
	default:
		break;
	}

	

}



