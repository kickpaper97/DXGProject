#include "PreCompile.h"
#include "StampDenied.h"
#include "Stamp.h"

StampDenied::StampDenied()
{
}

StampDenied::~StampDenied()
{
}
void StampDenied::Start()
{
	if (nullptr == GameEngineSprite::Find("StampBotDenied.png"))
	{
		GameEngineSprite::CreateSingle("StampBotDenied.png");
		GameEngineSprite::CreateSingle("StampTop.png");


	}


	if (nullptr == GameEngineSound::FindSound("stamp-down.WAV"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Audio");

		GameEngineSound::SoundLoad(FilePath.PlusFilePath("stamp-down.WAV"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("stamp-up.WAV"));


	}

	{
		StampRenderer = CreateComponent<GameEngineSpriteRenderer>();
		StampRenderer->SetRenderOrder(RenderOrder::Stamp);
		StampRenderer->AutoSpriteSizeOn();
		StampRenderer->SetAutoScaleRatio(2.0f);
		StampRenderer->SetSprite("StampBotDenied.png");
		Transform.SetLocalPosition({ 114.5f,43 });

		StampTop = CreateComponent<GameEngineSpriteRenderer>();
		StampTop->SetRenderOrder(RenderOrder::Stamp);
		StampTop->SetParent(StampRenderer);

		StampTop->AutoSpriteSizeOn();
		StampTop->SetAutoScaleRatio(2.0f);
		StampTop->SetSprite("StampTop.png");
		StampTop->Transform.SetLocalPosition({ 0,74 });

		{
			std::shared_ptr<GameEngineCollision> StampCollision = CreateComponent<GameEngineCollision>(CollisionOrder::StampDenied);
			StampCollision->SetParent(StampRenderer);
			StampCollision->SetCollisionType(ColType::AABBBOX2D);
			StampCollision->Transform.SetLocalScale({ 150,130 });
			StampCollision->Transform.SetLocalPosition(float4::ZERO);
			Collisions.push_back(StampCollision);

		}
		{
			std::shared_ptr<GameEngineCollision> StampCollision = CreateComponent<GameEngineCollision>(CollisionOrder::StampDenied);
			StampCollision->SetParent(StampTop);
			StampCollision->SetCollisionType(ColType::SPHERE2D);
			StampCollision->Transform.SetLocalScale({ 54,54 });
			StampCollision->Transform.SetLocalPosition({ 0,9 });
			Collisions.push_back(StampCollision);


		}
		{
			std::shared_ptr<GameEngineCollision> StampCollision = CreateComponent<GameEngineCollision>(CollisionOrder::StampDenied);
			StampCollision->SetParent(StampTop);
			StampCollision->SetCollisionType(ColType::AABBBOX2D);
			StampCollision->Transform.SetLocalScale({ 52,30 });
			StampCollision->Transform.SetLocalPosition({ 0,-10 });
			Collisions.push_back(StampCollision);
		}

	}

	{
		StampCheck = CreateComponent<GameEngineCollision>(CollisionOrder::Ink);
		StampCheck->SetCollisionType(ColType::AABBBOX2D);
		float4 InkScale = GameEngineTexture::Find("InkApproved.png")->GetScale() * 2.0f;/*->GetSpriteData(0).GetScale() * 2.0f*/;


		StampCheck->Transform.AddLocalPosition({ float4::DOWN * 40 });
		StampCheck->Transform.SetLocalScale(InkScale);
		StampCheck->Off();
	}

	//ON
	{

		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{

				IsMoving = true;
				SoundEffect = GameEngineSound::SoundPlay("stamp-down.WAV");

			};

		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{



				if (13 < Transform.GetLocalPosition().Y)
				{
					Transform.AddLocalPosition(float4::DOWN * 300 * _Delta);



					if (13 >= Transform.GetLocalPosition().Y)
					{
						Transform.SetLocalPosition({ Transform.GetLocalPosition().X,13 });

						State.ChangeState(StampState::StampOFF);
						return;
					}
				}


			};
		StatePara.End = [=](GameEngineState* _Parent)
			{


			};
		State.CreateState(StampState::StampON, StatePara);
	}

	//Off
	{

		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{


				if (true == IsMoving)
				{
					SoundEffect = GameEngineSound::SoundPlay("stamp-up.WAV");

				}
			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{

				if (43 > Transform.GetLocalPosition().Y)
				{
					Transform.AddLocalPosition(float4::UP * 500 * _Delta);
					if (43 <= Transform.GetLocalPosition().Y)
					{
						Transform.SetLocalPosition({ Transform.GetLocalPosition().X,43 });

						IsMoving = false;
					}
				}



			};
		StatePara.End = [=](GameEngineState* _Parent)
			{

			};
		State.CreateState(StampState::StampOFF, StatePara);
	}

	State.ChangeState(StampState::StampOFF);

	GameEngineInput::AddInputObject(this);

}

void StampDenied::Update(float _Delta)
{
	{
		EventParameter Para;
		Para.Stay = [=](GameEngineCollision* _This, class GameEngineCollision* _Other)
			{


				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					{
						IsMoving = true;
						State.ChangeState(StampState::StampON);
						return;
					}
				}
			};

		for (int i = 0; i < Collisions.size(); i++)
		{
			Collisions[i]->CollisionEvent(CollisionOrder::Cursor, Para);
		}

	}




	if (true == IsMoving)
	{
		if (13 != Transform.GetLocalPosition().Y)
		{

			StampCheck->Off();

		}
		else
		{
			StampCheck->On();

		}
	}




	State.Update(_Delta);
}
