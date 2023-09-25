#include "PreCompile.h"
#include "QuitButton.h"
#include "BasicButton.h"

QuitButton::QuitButton()
{
}

QuitButton::~QuitButton()
{
}

void QuitButton::Start()
{
	BasicButton::Start();
	std::shared_ptr<GameEngineSpriteRenderer> Renderer = GetSpriteRenderer();
	Renderer->SetSprite("QuitButton.png");
	Renderer->CreateAnimation("QuitButtonOFF", "QuitButton.png", 0.01f, 0, 0, false);
	Renderer->CreateAnimation("QuitButtonON", "QuitButton.png", 0.01f, 1, 1, false);
	Renderer->ChangeAnimation("QuitButtonOFF");

	
}

void QuitButton::Update(float _Delta)
{

	
}
