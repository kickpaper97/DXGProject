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
	GameEngineSpriteRenderer* Renderer = GetSpriteRenderer();
	Renderer->SetSprite("ConventionQuitButton.png");
	Renderer->CreateAnimation("QuitButtonOFF", "ConventionQuitButton.png", 0.01f, 0, 0, false);
	Renderer->CreateAnimation("QuitButtonON", "ConventionQuitButton.png", 0.01f, 1, 1, false);
	Renderer->ChangeAnimation("QuitButtonOFF");

	
}

void QuitButton::Update(float _Delta)
{

	
}
