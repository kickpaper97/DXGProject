#include "PreCompile.h"
#include "DayOffBackGround.h"

DayOffBackGround::DayOffBackGround()
{
}

DayOffBackGround::~DayOffBackGround()
{
}

void DayOffBackGround::Start()
{


	if (nullptr == GameEngineSprite::Find("NormalTravelerAni.Png"))
	{

		GameEngineSprite::CreateSingle("NightReport.png");
		//GameEngineSprite::CreateSingle("Upgrades.png");
		//GameEngineSprite::CreateSingle("Tokens.png");
		GameEngineSprite::CreateSingle("NightPassportFrame.png");
		GameEngineSprite::CreateCut("ApartmentClass.png",4,1);
		GameEngineSprite::CreateCut("Emotions.png", 1, 8);

	}



	{
		std::shared_ptr<GameEngineSpriteRenderer> Title = CreateComponent<GameEngineSpriteRenderer>();
		Title->AutoSpriteSizeOn();
		Title->SetAutoScaleRatio(2.0f);
		Title->SetSprite("NightReport.png");
		float4 TitlePos = float4{ GameEngineCore::MainWindow.GetScale().hX(),-80.0f };
		Title->Transform.SetLocalPosition(TitlePos);
	}

	{
		std::shared_ptr<GameEngineSpriteRenderer> Class = CreateComponent<GameEngineSpriteRenderer>();
		Class->AutoSpriteSizeOn();
		Class->SetAutoScaleRatio(2.0f);

		Class->CreateAnimation("Class8", "ApartmentClass.png", 0.01f, 0, 0, false);
		Class->CreateAnimation("Class7", "ApartmentClass.png", 0.01f, 1, 1, false);
		Class->CreateAnimation("Class6", "ApartmentClass.png", 0.01f, 2,2, false);
		Class->CreateAnimation("Class5", "ApartmentClass.png", 0.01f, 3, 3, false);

		Class->ChangeAnimation("Class8");
		float4 ClassPos = float4{ GameEngineCore::MainWindow.GetScale().hX()+450.0f,-100.0f };
		Class->Transform.SetLocalPosition(ClassPos);
	}

	{
		std::shared_ptr<GameEngineSpriteRenderer> WifeCondition = CreateComponent<GameEngineSpriteRenderer>();
		WifeCondition->AutoSpriteSizeOn();
		WifeCondition->SetAutoScaleRatio(2.0f);

		WifeCondition->CreateAnimation("Happy", "Emotions.png", 0.01f, 0, 0, false);
		WifeCondition->CreateAnimation("Good", "Emotions.png", 0.01f, 1, 1, false);
		WifeCondition->CreateAnimation("Sad", "Emotions.png", 0.01f, 2, 2, false);
		WifeCondition->CreateAnimation("Cold", "Emotions.png", 0.01f, 3, 3, false);
		WifeCondition->CreateAnimation("Sick", "Emotions.png", 0.01f, 4, 4, false);
		WifeCondition->CreateAnimation("VerySick", "Emotions.png", 0.01f, 5, 5, false);
		WifeCondition->CreateAnimation("Dead", "Emotions.png", 0.01f, 6, 6, false);
		WifeCondition->CreateAnimation("Starve", "Emotions.png", 0.01f, 7, 7, false);





		WifeCondition->ChangeAnimation("Good");
		float4 WifeConditionPos = float4{ GameEngineCore::MainWindow.GetScale().hX() + 450.0f,-200.0f };
		WifeCondition->Transform.SetLocalPosition(WifeConditionPos);
	}

	{
		std::shared_ptr<GameEngineSpriteRenderer> SonCondition = CreateComponent<GameEngineSpriteRenderer>();
		SonCondition->AutoSpriteSizeOn();
		SonCondition->SetAutoScaleRatio(2.0f);

		SonCondition->CreateAnimation("Happy", "Emotions.png", 0.01f, 0, 0, false);
		SonCondition->CreateAnimation("Good", "Emotions.png", 0.01f, 1, 1, false);
		SonCondition->CreateAnimation("Sad", "Emotions.png", 0.01f, 2, 2, false);
		SonCondition->CreateAnimation("Cold", "Emotions.png", 0.01f, 3, 3, false);
		SonCondition->CreateAnimation("Sick", "Emotions.png", 0.01f, 4, 4, false);
		SonCondition->CreateAnimation("VerySick", "Emotions.png", 0.01f, 5, 5, false);
		SonCondition->CreateAnimation("Dead", "Emotions.png", 0.01f, 6, 6, false);
		SonCondition->CreateAnimation("Starve", "Emotions.png", 0.01f, 7, 7, false);

		SonCondition->ChangeAnimation("Good");
		float4 SonConditionPos = float4{ GameEngineCore::MainWindow.GetScale().hX() + 450.0f,-280.0f };
		SonCondition->Transform.SetLocalPosition(SonConditionPos);
	}

	{
		std::shared_ptr<GameEngineSpriteRenderer> MotherCondition = CreateComponent<GameEngineSpriteRenderer>();
		MotherCondition->AutoSpriteSizeOn();
		MotherCondition->SetAutoScaleRatio(2.0f);

		MotherCondition->CreateAnimation("Happy", "Emotions.png", 0.01f, 0, 0, false);
		MotherCondition->CreateAnimation("Good", "Emotions.png", 0.01f, 1, 1, false);
		MotherCondition->CreateAnimation("Sad", "Emotions.png", 0.01f, 2, 2, false);
		MotherCondition->CreateAnimation("Cold", "Emotions.png", 0.01f, 3, 3, false);
		MotherCondition->CreateAnimation("Sick", "Emotions.png", 0.01f, 4, 4, false);
		MotherCondition->CreateAnimation("VerySick", "Emotions.png", 0.01f, 5, 5, false);
		MotherCondition->CreateAnimation("Dead", "Emotions.png", 0.01f, 6, 6, false);
		MotherCondition->CreateAnimation("Starve", "Emotions.png", 0.01f, 7, 7, false);

		MotherCondition->ChangeAnimation("Good");
		float4 MotherConditionPos = float4{ GameEngineCore::MainWindow.GetScale().hX() + 450.0f,-360.0f };
		MotherCondition->Transform.SetLocalPosition(MotherConditionPos);
	}

	{
		std::shared_ptr<GameEngineSpriteRenderer> UncleCondition = CreateComponent<GameEngineSpriteRenderer>();
		UncleCondition->AutoSpriteSizeOn();
		UncleCondition->SetAutoScaleRatio(2.0f);

		UncleCondition->CreateAnimation("Happy", "Emotions.png", 0.01f, 0, 0, false);
		UncleCondition->CreateAnimation("Good", "Emotions.png", 0.01f, 1, 1, false);
		UncleCondition->CreateAnimation("Sad", "Emotions.png", 0.01f, 2, 2, false);
		UncleCondition->CreateAnimation("Cold", "Emotions.png", 0.01f, 3, 3, false);
		UncleCondition->CreateAnimation("Sick", "Emotions.png", 0.01f, 4, 4, false);
		UncleCondition->CreateAnimation("VerySick", "Emotions.png", 0.01f, 5, 5, false);
		UncleCondition->CreateAnimation("Dead", "Emotions.png", 0.01f, 6, 6, false);
		UncleCondition->CreateAnimation("Starve", "Emotions.png", 0.01f, 7, 7, false);

		UncleCondition->ChangeAnimation("Good");
		float4 UncleConditionPos = float4{ GameEngineCore::MainWindow.GetScale().hX() + 450.0f,-440.0f };
		UncleCondition->Transform.SetLocalPosition(UncleConditionPos);
	}

}

void DayOffBackGround::Update(float _Delta)
{
	
}
