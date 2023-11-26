#include "PreCompile.h"
#include "Car.h"

Car::Car()
{
}

Car::~Car()
{
}

void Car::Start()
{
	if (nullptr == GameEngineSprite::Find("CarAni.png"))
	{
		GameEngineSprite::CreateCut("CarAni.png",3,1);
		GameEngineSprite::CreateSingle("Outer_Mask.png");

	}


	if (nullptr == GameEngineSound::FindSound("car-driveby.WAV"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Audio");

		GameEngineSound::SoundLoad(FilePath.PlusFilePath("car-driveby.WAV"));


	}
	
	

	

	std::shared_ptr<GameEngineSpriteRenderer> SpriteRenderer = CreateComponent<GameEngineSpriteRenderer>();
	SpriteRenderer->CreateAnimation("CarMove", "CarAni.png", 0.1f, 2, 2, false);
	SpriteRenderer->ChangeAnimation("CarMove");
	SpriteRenderer->SetMaskTexture("Outer_Mask.png");
	SpriteRenderer->AutoSpriteSizeOn();
	SpriteRenderer->SetAutoScaleRatio(2.0f);
	Transform.SetLocalPosition({ 1100,800 });
}

void Car::Update(float _Delta)
{
	Transform.AddLocalPosition(float4::DOWN * 400 * _Delta);

	if (-1600.0f >= Transform.GetLocalPosition().Y)
	{
		isSound = false;
		Transform.SetLocalPosition({ 1100,50 });

	}

	if (5.0f>=Transform.GetLocalPosition().Y && false == isSound)
	{
		isSound = true;
		Sound = GameEngineSound::SoundPlay("car-driveby.WAV");
		Sound.SetVolume(0.08f);
	}

		
}
