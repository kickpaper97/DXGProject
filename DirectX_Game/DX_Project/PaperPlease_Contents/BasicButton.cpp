#include"PreCompile.h"
#include "BasicButton.h"

#include "BasicActor.h"
#include "Cursor.h"
BasicButton::BasicButton()
{
}

BasicButton::~BasicButton()
{
}

void BasicButton::Start()
{
	SpriteRenderer = CreateComponent<GameEngineSpriteRenderer>();
	
	SetOrder(GameObjectType::UIButton);
	/*
	GetSpriteRenderer()->SetRenderOrder(RenderOrder::UI);*/

	Collision = CreateComponent<GameEngineCollision>();

	GameEngineInput::GameEngineInput::AddInputObject(this);

}

void BasicButton::Update(float _Delta)
{




	

	
}

