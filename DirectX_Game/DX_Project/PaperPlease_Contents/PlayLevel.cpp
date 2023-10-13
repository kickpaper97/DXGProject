#include "PreCompile.h"
#include "PlayLevel.h"
#include "BasicActor.h"
#include "PlayMap.h"
#include "Cursor.h"
#include "RuleBook.h"
#include "WaitingLine.h"
#include "PeopleBase.h"
#include "NomalTraveler.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{

	{
	//	GameEngineDirectory Dir;
	//	Dir.MoveParentToExistsChild("GameEngineResources");
	//	Dir.MoveChild("ContentsResources");
	//	Dir.MoveChild("assets");
	//	std::vector<GameEngineFile> Files = Dir.GetAllFile();

	//	for (size_t i = 0; i < Files.size(); i++)
	//	{
	//		// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
	//		GameEngineFile& File = Files[i];
	//		GameEngineTexture::Load(File.GetStringPath());
	//	}

		
		



	}

	
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);



	{
		
	}

	{
		std::shared_ptr<PlayMap> NewMap = CreateActor<PlayMap>(GameObjectType::BackGround);
	}

	{
		GameEngineInput::AddInputObject(this);
		NewLine = CreateActor<WaitingLine>();
		
		{

			NewLine->AddPerson({ 230.20f,-156.10f });
			NewLine->AddPerson({ 227.20f,-151.90f });
			NewLine->AddPerson({ 224.80f,-169.10f });
			NewLine->AddPerson({ 211.90f,-154.80f });
			NewLine->AddPerson({ 206.10f,-169.30f });
			NewLine->AddPerson({ 203.30f,-159.80f });
			NewLine->AddPerson({ 200.40f,-150.60f });
			NewLine->AddPerson({ 191.40f,-169.50f });
			NewLine->AddPerson({ 184.90f,-152.90f });
			NewLine->AddPerson({ 184.60f,-158.00f });
			NewLine->AddPerson({ 183.40f,-156.60f });
			NewLine->AddPerson({ 180.40f,-159.00f });
			NewLine->AddPerson({ 179.50f,-168.70f });
			NewLine->AddPerson({ 176.90f,-165.30f });
			NewLine->AddPerson({ 161.50f,-160.10f });
			NewLine->AddPerson({ 150.40f,-152.70f });
			NewLine->AddPerson({ 141.50f,-156.20f });
			NewLine->AddPerson({ 131.80f,-158.20f });
			NewLine->AddPerson({ 128.50f,-167.50f });
			NewLine->AddPerson({ 117.10f,-162.00f });
			NewLine->AddPerson({ 108.60f,-161.70f });
			NewLine->AddPerson({ 95.10f,-160.60f });
			NewLine->AddPerson({ 88.50f,-157.20f });
			NewLine->AddPerson({ 67.00f,-150.60f });
			NewLine->AddPerson({ 65.30f,-168.30f });
			NewLine->AddPerson({ 48.50f,-151.30f });
			NewLine->AddPerson({ 45.60f,-162.80f });
			NewLine->AddPerson({ 44.90f,-152.20f });
			NewLine->AddPerson({ 42.20f,-153.80f });
			NewLine->AddPerson({ 39.00f,-155.00f });
			NewLine->AddPerson({ 24.30f,-156.70f });
			NewLine->AddPerson({ 13.70f,-163.00f });
			NewLine->AddPerson({ 13.30f,-160.00f });
			NewLine->AddPerson({ 12.60f,-163.80f });
			NewLine->AddPerson({ 11.70f,-152.60f});
		}


	}

	
	{

	}

}

void PlayLevel::Update(float _Delta)
{

	if (true == GameEngineInput::IsDown('C', this))
	{
		NewLine->AddPerson();
		
	}

	if (true == GameEngineInput::IsDown('V', this))
	{
		std::shared_ptr<PeopleBase> Peoplecheck;
		Peoplecheck = NewLine->CallFirstPerson();
		
	}
}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	std::shared_ptr<Cursor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);

	//std::shared_ptr<RuleBook> NewRuleBook = CreateActor<RuleBook>();

	
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	if (nullptr != NewLine)
	{
		NewLine.reset();
		NewLine = nullptr;
	}
	

}
