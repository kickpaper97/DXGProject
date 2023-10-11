#include "PreCompile.h"
#include "LevelBase.h"

LevelBase::LevelBase()
{

	GameEngineCore::GetBackBufferRenderTarget()->SetClearColor(float4(0, 0, 0,1));
}

LevelBase::~LevelBase()
{
}

void LevelBase::UIOn()
{
	if (true == isUI)
	{
		return;
	}

	std::shared_ptr<GameEngineCamera> Camera= GetCamera(static_cast<int>(ECAMERAORDER::UI));
	
	Camera->On();

	isUI = true;
}

void LevelBase::UIOff()
{

	if (false == isUI)
	{
		return;
	}

	std::shared_ptr<GameEngineCamera> Camera = GetCamera(static_cast<int>(ECAMERAORDER::UI));
	Camera->Off();

	isUI = false;

}
