#include "PreCompile.h"
#include "PaperManager.h"
#include "PaperBase.h"
#include "PassPort.h"
#include "NormalTraveler.h"
#include "Player.h"

PaperManager::PaperManager()
{
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
	Papers.erase(it);

	std::shared_ptr PassPortCheck = _Paper->GetDynamic_Cast_This<PassPort>();
	if (nullptr != PassPortCheck)
	{
		switch (PassPortCheck->GetEntryCheck())
		{
		case PassPortChecked::Approved:
		
			if (true == PassPortCheck->GetOwner()->GetIsLier())
			{
				IsCorrectCheck = 0;
			}
			else
			{
				IsCorrectCheck = 1;
			}

			break;
		
		case PassPortChecked::Denied:
			if (true == PassPortCheck->GetOwner()->GetIsLier())
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

	_Paper->Death();


	if (Papers.empty())
	{
		if (IsCorrectCheck == -1)
		{
			MsgBoxAssert("여권이 검사되지않고 모든 서류를 돌려줬습니다.");
			return;
		}


		IsPapersEmpty = true;

		

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




