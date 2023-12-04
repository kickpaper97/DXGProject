#include "PreCompile.h"
#include "PaperManager.h"
#include "PlayPaper.h"
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

void PaperManager::WorkInit(std::shared_ptr<class NormalTraveler> _CurTraveler)
{
	CurTraveler = _CurTraveler;
	IsPassPortChecked = false;
	IsCorrectCheck = -1;
}
void PaperManager::AddPaper(std::shared_ptr<class PlayPaper> _Paper)
{

		Papers.push_back(_Paper);
		if (true == IsPapersEmpty)
		{
			
			IsPapersEmpty = false;

		}

}

void PaperManager::ReleasePaper()
{
	std::vector<std::shared_ptr<class PlayPaper>>::iterator Start = Papers.begin();
	std::vector<std::shared_ptr<class PlayPaper>>::iterator End = Papers.end();

	for (; Start != End;)
	{
		std::shared_ptr<class PlayPaper> ptr = *Start;


		if (true == ptr->GetIsOut())
		{

			++Start;
			continue;
		}


		Papers.erase(Start);


	}

	if (Papers.empty())
	{

		PaperManager::MainPaperManager->PassPortCheck();


		if (IsCorrectCheck == -1)
		{
			MsgBoxAssert("여권이 검사되지않고 모든 서류를 돌려줬습니다.");
			return;
		}

		
		
		CurTraveler->ChanageState(TravelerState::TurnEnd);
		CurTraveler = nullptr;
		IsPapersEmpty = true;
		

	}
	

}
__int64 PaperManager::FindIndex(std::shared_ptr<class PlayPaper> _Paper)
{
	
	std::vector<std::shared_ptr<PlayPaper>>::iterator it = std::find(Papers.begin(), Papers.end(), _Paper);
	if (it == Papers.end())
	{
		MsgBoxAssert("Paper가 관리되고있지 않습니다.");
		return -1;
	}
	int	index = std::distance(Papers.begin(), it);
	
	return index;
	
}



void PaperManager::PassPortCheck()
{
	
		switch (EntryCheck)
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
		
	if (0 == IsCorrectCheck)
	{
		Player::MainPlayer->PlayerDayPlay.AddWrongCount();
	}
	else if (1 == IsCorrectCheck)
	{
		std::shared_ptr<Citation> NewCitation = GetLevel()->CreateActor<Citation>();

		Player::MainPlayer->PlayerDayPlay.AddCorrectCount();

	}
	
	IsPassPortChecked = true;
}

void PaperManager::PaperRenderChange()
{
	std::vector<std::shared_ptr<class PlayPaper>>::iterator Start = Papers.begin();
	std::vector<std::shared_ptr<class PlayPaper>>::iterator End = Papers.end();

	for (; Start != End;)
	{
		std::shared_ptr<class PlayPaper> ptr = *Start;


		if (nullptr == ptr->GetDynamic_Cast_This<PassPort>())
		{

			++Start;
			continue;
		}


	}



}







