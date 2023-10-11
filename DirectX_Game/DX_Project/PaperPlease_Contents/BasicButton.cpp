#include"PreCompile.h"
#include "BasicButton.h"


BasicButton::BasicButton()
{
}

BasicButton::~BasicButton()
{
}

void BasicButton::Start()
{
	SpriteRenderer = CreateComponent<GameEngineUIRenderer>();
	SetOrder(GameObjectType::UI);
	SpriteRenderer->SetRenderOrder(RenderOrder::UI);

}

void BasicButton::Update(float _Delta)
{

}

