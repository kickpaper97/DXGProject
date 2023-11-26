#include "PreCompile.h"
#include "StampBar.h"
#include "StampApproved.h"
#include "StampDenied.h"
#include "Stamp.h"

StampBar::StampBar()
{
}

StampBar::~StampBar()
{
}

void StampBar::Start()
{

	if (nullptr == GameEngineSprite::Find("StampBarBot.png"))
	{
		GameEngineSprite::CreateSingle("StampBarBot.png");
		GameEngineSprite::CreateSingle("StampBarMid.png");
		GameEngineSprite::CreateSingle("StampBarTop.png");

		GameEngineSprite::CreateSingle("StampBotApproved.png");
		GameEngineSprite::CreateSingle("StampBotDenied.png");
		GameEngineSprite::CreateSingle("StampTop.png");

		

	}

	if (nullptr == GameEngineSound::FindSound("stampbar-close.WAV"))
	{
		GameEnginePath FilePath;
		FilePath.SetCurrentPath();
		FilePath.MoveParentToExistsChild("ContentsResources");
		FilePath.MoveChild("ContentsResources\\Audio");

		GameEngineSound::SoundLoad(FilePath.PlusFilePath("stampbar-close.WAV"));
		GameEngineSound::SoundLoad(FilePath.PlusFilePath("stampbar-open.WAV"));


	}


	
	std::shared_ptr<GameEngineSpriteRenderer> BarBotRenderer = CreateComponent<GameEngineSpriteRenderer>();
	std::shared_ptr<GameEngineSpriteRenderer> BarMidRenderer = CreateComponent<GameEngineSpriteRenderer>();
	std::shared_ptr<GameEngineSpriteRenderer> BarTopRenderer = CreateComponent<GameEngineSpriteRenderer>();

	BarBotRenderer->AutoSpriteSizeOn();
	BarMidRenderer->AutoSpriteSizeOn();
	BarTopRenderer->AutoSpriteSizeOn();
	BarBotRenderer->SetAutoScaleRatio(2.0f);
	BarMidRenderer->SetAutoScaleRatio(2.0f);
	BarTopRenderer->SetAutoScaleRatio(2.0f);
	BarBotRenderer-> SetSprite("StampBarBot.png");
	BarMidRenderer->SetSprite("StampBarMid.png");
	BarTopRenderer->SetSprite("StampBarTop.png");

	BarBotRenderer->SetRenderOrder(RenderOrder::StampBarBot);
	BarMidRenderer->SetRenderOrder(RenderOrder::StampBars);
	BarTopRenderer->SetRenderOrder(RenderOrder::StampTop);

	BarTopRenderer->Transform.SetLocalPosition({ 0,63 });
	BarBotRenderer->Transform.SetLocalPosition({ 0,-35});

	GameEngineInput::AddInputObject(this);
	//Stamp Switch Collsion
	{
	{

	std::shared_ptr<GameEngineCollision> SwitchCol = CreateComponent<GameEngineCollision>(CollisionOrder::StampSwitch);
	SwitchCol->SetCollisionType(ColType::AABBBOX2D);
	SwitchCol->Transform.SetLocalScale({ 76,115 });
	SwitchCol->Transform.SetLocalPosition({ -5,40 });

	Collisions.push_back(SwitchCol);
	}

	{

		std::shared_ptr<GameEngineCollision> SwitchCol = CreateComponent<GameEngineCollision>(CollisionOrder::StampSwitch);
		SwitchCol->SetCollisionType(ColType::AABBBOX2D);
		SwitchCol->Transform.SetLocalScale({ 74,115 });
		SwitchCol->Transform.SetLocalPosition({ -240,40 });
		Collisions.push_back(SwitchCol);

	}

	{

		std::shared_ptr<GameEngineCollision> SwitchCol = CreateComponent<GameEngineCollision>(CollisionOrder::StampSwitch);
		SwitchCol->SetCollisionType(ColType::AABBBOX2D);
		SwitchCol->Transform.SetLocalScale({ 74,115 });
		SwitchCol->Transform.SetLocalPosition({ 235,40 });
		Collisions.push_back(SwitchCol);

	}

	}

	PosOff = { 1400,-450 };
	PosOn = { 890, -450 };

	//ON
	{
		
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{
				
				IsMoving = true;
				//SoundEffect = GameEngineSound::SoundPlay("stampbar-open.WAV");

			};

		StatePara.Stay = [=](float _Delta,GameEngineState* _Parent)
			{


				if (PosOn != Transform.GetLocalPosition())
				{
					Transform.AddLocalPosition(float4::LEFT * 1500 * _Delta);
					if (PosOn.X >= Transform.GetLocalPosition().X)
					{
						Transform.SetLocalPosition(PosOn);
						IsMoving = false;
					}
				}

				{
					EventParameter Para;
					Para.Stay = [=](GameEngineCollision* _This, class GameEngineCollision* _Other)
						{
							if (GameEngineInput::IsDown(VK_LBUTTON, this))
							{
								{
									State.ChangeState(StampBarState::OFF);
									return;
								}
							}
						};
					for (int i = 0; i < Collisions.size(); i++)
					{
						Collisions[i]->CollisionEvent(CollisionOrder::Cursor, Para);
					}
				}

				
			};
		StatePara.End = [=](GameEngineState* _Parent)
			{
				SoundEffect = GameEngineSound::SoundPlay("stampbar-close.WAV");

			};
		State.CreateState(StampBarState::ON, StatePara);
	}

	//Off
	{

		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{
				IsMoving = true;
				//SoundEffect = GameEngineSound::SoundPlay("stampbar-close.WAV");
			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				
				if (PosOff != Transform.GetLocalPosition())
				{
					Transform.AddLocalPosition(float4::RIGHT*1500* _Delta);
					if ( PosOff.X<=Transform.GetLocalPosition().X)
					{
						Transform.SetLocalPosition( PosOff);
						IsMoving = false;
					}
				}


				{
					EventParameter Para;
					Para.Stay = [=](GameEngineCollision* _This, class GameEngineCollision* _Other)
						{


							if (GameEngineInput::IsDown(VK_LBUTTON, this))
							{
								{
									State.ChangeState(StampBarState::ON);
									return;
								}
							}
						};

					for (int i = 0; i < Collisions.size(); i++)
					{
						Collisions[i]->CollisionEvent(CollisionOrder::Cursor,Para);
					}

				}
				


			};
		StatePara.End = [=](GameEngineState* _Parent)
			{
				SoundEffect = GameEngineSound::SoundPlay("stampbar-open.WAV");
			};
		State.CreateState(StampBarState::OFF, StatePara);
	}

	State.ChangeState(StampBarState::OFF);

	

	Transform.SetLocalPosition(PosOff);
	GameEngineInput::AddInputObject(this);
}

void StampBar::Update(float _Delta)
{
	/*{
		EventParameter Para;
		Para.Stay = [=](GameEngineCollision* _This, class GameEngineCollision* _Other)
			{
				if (GameEngineInput::IsDown(VK_LBUTTON, this))
				{
					if (Transform.GetLocalPosition() == PosOn&&false==IsMoving)
					{
						State.ChangeState(StampBarState::OFF);
						return;
					}
					else if(Transform.GetLocalPosition() == PosOff && false == IsMoving)
					{
						State.ChangeState(StampBarState::ON);
						return;
					}
				}
			};
		
	}*/

	State.Update(_Delta);
}
