#include"PreCompile.h"
#include "BasicButton.h"

#include "BasicActor.h"

BasicButton::BasicButton()
{
}

BasicButton::~BasicButton()
{
}

void BasicButton::Start()
{
	BasicActor::Start();
	SetOrder(GameObjectType::UI);
	GetSpriteRenderer()->SetRenderOrder(RenderOrder::UI);

}

void BasicButton::Update(float _Delta)
{

}

