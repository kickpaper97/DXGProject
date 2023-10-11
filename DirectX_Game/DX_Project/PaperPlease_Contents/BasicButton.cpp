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
	SpriteRenderer = CreateComponent<GameEngineUIRenderer>();
	
	SetOrder(GameObjectType::UIButton);
	GetSpriteRenderer()->SetRenderOrder(RenderOrder::UI);

}

void BasicButton::Update(float _Delta)
{

}

