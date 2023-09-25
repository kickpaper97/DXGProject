#include "PreCompile.h"
#include "LevelBase.h"

LevelBase::LevelBase()
{

	GameEngineCore::GetBackBufferRenderTarget()->SetClearColor(float4(0, 0, 0,1));
}

LevelBase::~LevelBase()
{
}
