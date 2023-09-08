#include "PreCompile.h"
#include "Cursor.h"

#include "BasicActor.h"
#include<GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCollision.h>

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

	{
	SetOrder(GameObjectType::Cursor);
	GameEngineSpriteRenderer* Renderer = GetSpriteRenderer();
	Renderer->SetSprite("CursorArrow.png");
	Renderer->SetRenderOrder(RenderOrder::Cursor);

	}


	{
		CursorCollison = CreateComponent<GameEngineCollision>(CollisionOrder::Cursor);
		CursorCollison->Transform.SetLocalScale({ 1.0f,1.0f,1.0f });
	}

}

void Cursor::Update(float _Delta)
{

	{
	float4 CusorPos = GameEngineCore::MainWindow.GetMousePos();
	CusorPos.Y *= -1.0f;
	
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
