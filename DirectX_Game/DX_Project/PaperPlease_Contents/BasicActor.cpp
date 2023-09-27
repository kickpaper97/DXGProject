
#include "PreCompile.h"
#include "BasicActor.h"


BasicActor::BasicActor()
{
}

BasicActor::~BasicActor()
{
}


void BasicActor::Start()
{
	SpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(GetOrder());
	SpriteRenderer->SetAutoScaleRatio(2.0f);
}


