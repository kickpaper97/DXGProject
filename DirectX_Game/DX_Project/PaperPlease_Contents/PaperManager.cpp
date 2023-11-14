#include "PreCompile.h"
#include "PaperManager.h"
#include "PaperBase.h"

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
	_Paper->Death();
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



