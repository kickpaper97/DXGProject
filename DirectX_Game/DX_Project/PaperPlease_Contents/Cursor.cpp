#include "PreCompile.h"
#include "Cursor.h"

#include "BasicActor.h"
#include<GameEnginePlatform/GameEngineWindow.h>

Cursor* Cursor::MainCursor;


Cursor::Cursor()
{
	MainCursor = this;
}

Cursor::~Cursor()
{
}

void Cursor::Start()
{
	BasicActor::Start();
	SetOrder(GameObjectType::Cursor);
	GameEngineSpriteRenderer* Renderer = GetSpriteRenderer();
	Renderer->SetSprite("CursorArrow.png");
	Renderer->SetRenderOrder(RenderOrder::Cursor);

}

void Cursor::Update(float _Delta)
{

	{
	float4 CusorPos = GameEngineCore::MainWindow.GetMousePos();
	CusorPos.Y *= -1.0f;
	CusorPos.Y += GameEngineCore::MainWindow.GetScale().Y;
	Transform.SetLocalPosition(CusorPos);
	
	}
	/*if (콜리전조건)
	{
	Renderer->SetSprite("CursorHand.png");

	}
	else
	{
	Renderer->SetSprite("CursorArrow.png");
	}*/
}
