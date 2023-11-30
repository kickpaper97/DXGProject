#include "PreCompile.h"
#include "PaperManager.h"
#include "PaperBase.h"
#include "PassPort.h"
#include "NormalTraveler.h"
#include "Citation.h"
#include "Player.h"

PaperManager* PaperManager::MainPaperManager;

PaperManager::PaperManager()
{
	MainPaperManager = this;
}

PaperManager::~PaperManager()
{
}

void PaperManager::Start()
{
}

void PaperManager::ReleasePaper(std::shared_ptr<class PaperBase> _Paper)
{
	std::vector<std::shared_ptr<PaperBase>>::iterator it = std::find(Papers.begin(), Papers.end(), _Paper);
	std::shared_ptr<PaperBase>ptr = *it;
	Papers.erase(it);

	std::shared_ptr PassPortCheck = _Paper->GetDynamic_Cast_This<PassPort>();
	if (nullptr != PassPortCheck)
	{
		CurTraveler = PassPortCheck->GetOwner();
		switch (PassPortCheck->GetEntryCheck())
		{
		case PassPortChecked::Approved:
			CurTraveler->SetPassPortChecked(PassPortChecked::Approved);
			if (true == CurTraveler->GetIsLier())
			{
				IsCorrectCheck = 0;
			}
			else
			{
				IsCorrectCheck = 1;
			}

			break;
		
		case PassPortChecked::Denied:
			CurTraveler->SetPassPortChecked(PassPortChecked::Denied);
			if (true == CurTraveler->GetIsLier())
			{
				IsCorrectCheck = 1;
			}
			else
			{
				IsCorrectCheck = 0;

			}
			break;
		default:
			break;
		}
		
	}

	ptr->Death();

	if (0 == IsCorrectCheck)
	{
		Player::MainPlayer->PlayerDayPlay.AddWrongCount();
	}
	else if (1 == IsCorrectCheck)
	{
		std::shared_ptr<Citation> NewCitation = GetLevel()->CreateActor<Citation>();
		
		Player::MainPlayer->PlayerDayPlay.AddCorrectCount();

	}

	

	if (Papers.empty())
	{
		if (IsCorrectCheck == -1)
		{
			MsgBoxAssert("여권이 검사되지않고 모든 서류를 돌려줬습니다.");
			return;
		}

		CurTraveler->ChanageState(TravelerState::TurnEnd);
		IsPapersEmpty = true;
		ClearIsCorrectCheck();
		

	}
	

}



int PaperManager::FindIndex(std::shared_ptr<class PaperBase> _Paper)
{
	
	std::vector<std::shared_ptr<PaperBase>>::iterator it = std::find(Papers.begin(), Papers.end(), _Paper);
	if (it == Papers.end())
	{
		MsgBoxAssert("Paper가 관리되고있지 않습니다.");
		return -1;
	}
	int	index = std::distance(Papers.begin(), it);
	
	return index;
	
}

std::shared_ptr<class PassPort> PaperManager::GetCurPassPort()
{
	
	{
		
		std::vector<std::shared_ptr<class PaperBase>>::iterator Start = Papers.begin();
		std::vector<std::shared_ptr<class PaperBase>>::iterator End = Papers.end();

		for (; Start != End;)
		{
			std::shared_ptr<class PaperBase> ptr = *Start;
			

			if (nullptr== ptr->GetDynamic_Cast_This<PassPort>())
			{
				
				++Start;
				continue;
			}
	       return ptr->GetDynamic_Cast_This<PassPort>();
		
		}

	}
	return nullptr;

}




