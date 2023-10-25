#include "PreCompile.h"
#include "IntroPicture.h"

#include "CustomSpriteRenderer.h"

IntroPicture::IntroPicture()
{
}

IntroPicture::~IntroPicture()
{
}

void IntroPicture::Start()
{
	SpriteRenderer = CreateComponent<CustomSpriteRenderer>(GetOrder());
	SpriteRenderer->SetAutoScaleRatio(2.0f);
}
