#include "PreCompile.h"
#include "PlayPaper.h"

#include "PaperManager.h"
#include "Cursor.h"


PlayPaper::PlayPaper()
{
}

PlayPaper::~PlayPaper()
{
}

void PlayPaper::Start()
{
	PaperBase::Start();
}

void PlayPaper::Update(float _Delta)
{
	PaperBase::Update(_Delta);

	if (nullptr == Parent->GetDynamic_Cast_This<Cursor>())
	{
		if (0 <= Transform.GetWorldPosition().X && MASKLINEPOS_X > Transform.GetWorldPosition().X)
		{
			if (-410 <= Transform.GetWorldPosition().Y && MASKLINEPOS_Y > Transform.GetWorldPosition().Y)
			{
		
				if (true == PaperManager::MainPaperManager->GetIsPassPortChecked())
				{
					OuterRenderer->SetMaskTexture("PaperOut_Mask.png");
					IsOut = true;

				}

				
			

			}
		}

	}


	if (true == IsOut)
	{

		
		PaperManager::MainPaperManager->ReleasePaper();
		Death();
	}

}
