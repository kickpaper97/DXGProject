#include "PreCompile.h"
#include "PlayLevel.h"

#include "BasicActor.h"


#include "PlayMap.h"
#include "BoothDoor.h"
#include "NextBell.h"
#include "Guard.h"
#include "Car.h"

#include "Cursor.h"

#include "WaitingLine.h"
#include "PeopleBase.h"
#include "NormalTraveler.h"

#include "Player.h"
#include "PaperManager.h"
#include "PassPort.h"
#include "RuleBook.h"

#include "StampBar.h"
#include "StampApproved.h"
#include "StampDenied.h"

#include <GameEngineCore/FadePostEffect.h>


PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{


	
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);





	{
		NewMap = CreateActor<PlayMap>(GameObjectType::BackGround);
		NewBell = CreateActor <NextBell>(GameObjectType::Play);
		NewBell->Transform.SetLocalPosition({ 348.0f,-168.0f });

		
	}
	{
		NewStamp  = CreateActor<StampBar>(GameObjectType::Stamp);
		std::shared_ptr<GameEngineActor>	NewApprovedStamp = CreateActor<StampApproved>();
		NewApprovedStamp->SetParent(NewStamp);
		std::shared_ptr<GameEngineActor>	NewDeniedStamp = CreateActor<StampDenied>();
		NewDeniedStamp->SetParent(NewStamp);
		NewStamp->Off();

	}

	{
		GameEngineInput::AddInputObject(this);
		NewLine = CreateActor<WaitingLine>();
		
		


	}

	{
		NewPapers = CreateActor<PaperManager>();
	}

	

	//State::DayStart
	{
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{
				

				//대기자 배치
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
					NewLine->AddPerson({ 11.70f,-152.60f });
				}
				// 군인 배치
				{
					std::shared_ptr<Guard>NewGaurd = CreateActor<Guard>();
					NewGaurd->Transform.SetLocalPosition({257,0});
					NewGaurd->SetDestinationPos({257,-135});

				}
				{
					std::shared_ptr<Guard>NewGaurd = CreateActor<Guard>();
					NewGaurd->Transform.SetLocalPosition({ 245,60 });
					NewGaurd->SetDestinationPos({ 245,-40 });

				}

				{
					std::shared_ptr<Guard>NewGaurd = CreateActor<Guard>();
					NewGaurd->Transform.SetLocalPosition({ 972,5 });
					NewGaurd->SetDestinationPos({ 888,-40 });

				}

				{
					std::shared_ptr<Guard>NewGaurd = CreateActor<Guard>();
					NewGaurd->Transform.SetLocalPosition({ 978,60 });
					NewGaurd->SetDestinationPos({ 890,-90 });

				}

				{
					std::shared_ptr<Guard>NewGaurd = CreateActor<Guard>();
					NewGaurd->Transform.SetLocalPosition({ 965,100 });
					NewGaurd->SetDestinationPos({ 888,-150 });

				}

				{
					std::shared_ptr<Car> NewCar = CreateActor<Car>();
				}

				//Player 배치
				std::shared_ptr<Player> NewPlayer = CreateActor<Player>();

				//

				std::shared_ptr<BoothDoor> NewBoothDoor = CreateActor<BoothDoor>();
				NewStamp->On();
				WorkTime = 0;

			};
		StatePara.End = [=](GameEngineState* _Parent)
			{

			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				
				
				if (false==Player::MainPlayer->GetOuterSpriteRenderer()->IsUpdate())
				{
					LevelState.ChangeState(PlayState::BeforeWork);
				}

				if (GameEngineInput::IsDown('M', this))
				{
					LevelState.ChangeState(PlayState::BeforeWork);
				}


			};

		LevelState.CreateState(PlayState::DayStart, StatePara);
	}


	//State::BeforeWork
	{
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{
				

				std::shared_ptr<RuleBook> NewRuleBook = CreateActor<RuleBook>();

				NewBell.get()->GetSpriteRenderer()->ChangeAnimation("NextBellAble");
				NewBell->SetIsPress(false);

				
			};
		StatePara.End= [=](GameEngineState* _Parent)
			{
				
			};
		StatePara.Stay = [=](float _Delta,GameEngineState* _Parent)
			{
				if (NewBell.get()->GetIsPress())
				{
					
					LevelState.ChangeState(PlayState::WalkingTravler);
					return;
				}

				

			};

		LevelState.CreateState(PlayState::BeforeWork,StatePara);
	}

	//walkingtravler
	{
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{
				CurTravler = NewLine->CallFirstPerson();
				
					
			};
		StatePara.End = [=](GameEngineState* _Parent)
			{
				




			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{

				
					
					CurTravler->WalkToBooth(_Delta);

					if (CurTravler->Transform.GetLocalPosition().X >= BoothPos.X-40 )
					{
						LevelState.ChangeState(PlayState::Working);
						return;
					}

				


				
				if (0.0f >= DayLimit - WorkTime)
				{
					LevelState.ChangeState(PlayState::AfterWork);
					return;
				}

				WorkTime += _Delta;
			};

		LevelState.CreateState(PlayState::WalkingTravler, StatePara);
	}

	//State::Working
	{
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{
				CurTravler->ChanageState(TravelerState::TurnStart);
				std::shared_ptr<PassPort> NewPassport = CreateActor<PassPort>();

				//NewPaperManger.push_back(NewPassport->GetDynamic_Cast_This<PaperBase>());
				NewPassport->SetOwner(CurTravler);

				NewPapers->AddPaper(NewPassport);
				
			};
		StatePara.End = [=](GameEngineState* _Parent)
			{
				
				CurTravler->ChanageState(TravelerState::TurnEnd);

				

			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				if (0.0f >= DayLimit - WorkTime)
				{
					LevelState.ChangeState(PlayState::AfterWork);
					return;
				}

				if (true == NewPapers->GetIsPapersEmpty())
				{
					LevelState.ChangeState(PlayState::Waiting);
				}

				WorkTime += _Delta;
			};

		LevelState.CreateState(PlayState::Working, StatePara);
	}

	//State::Waiting
	{
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{
				NewBell.get()->GetSpriteRenderer()->ChangeAnimation("NextBellAble");
				NewBell->SetIsPress(false);
			
			};
		StatePara.End = [=](GameEngineState* _Parent)
			{
				
			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				if (NewBell.get()->GetIsPress())
				{
					LevelState.ChangeState(PlayState::WalkingTravler);
					return;
				}


				if (0.0f <= DayLimit - WorkTime)
				{
					LevelState.ChangeState(PlayState::AfterWork);
					return;
				}

				WorkTime += _Delta;
			};

		LevelState.CreateState(PlayState::Waiting, StatePara);
	}

	//State::AfterWork
	{
		CreateStateParameter StatePara;
		StatePara.Start = [=](GameEngineState* _Parent)
			{

			};
		StatePara.End = [=](GameEngineState* _Parent)
			{
				
			};
		StatePara.Stay = [=](float _Delta, GameEngineState* _Parent)
			{
				if (2.0f<=LevelState.GetStateTime())
				{
					NewFade= GetLevelRenderTarget()->CreateEffect<FadePostEffect>();
					if (3.5f <= LevelState.GetStateTime())
					{
						GameEngineCore::ChangeLevel("DayOffLevel");
							return;
					}

				}
			
			};

		LevelState.CreateState(PlayState::AfterWork, StatePara);
	}


}

void PlayLevel::Update(float _Delta)
{

	if (true == GameEngineInput::IsDown('C', this))
	{
		
		
	}

	if (true == GameEngineInput::IsDown('V', this))
	{
		std::shared_ptr<PeopleBase> Peoplecheck;
		Peoplecheck = NewLine->CallFirstPerson();
		
	}

	LevelState.Update(_Delta);

}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	std::shared_ptr<Cursor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);

	


	LevelState.ChangeState(PlayState::DayStart);

	

	
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}
