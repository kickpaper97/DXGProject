#include "PreCompile.h"
#include "Cursor.h"



#include "BasicActor.h"

#include "PaperBase.h"
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
	
	if (nullptr == GameEngineSprite::Find("CursorArrow.png"))
	{
		GameEngineSprite::CreateSingle("CursorArrow.png");
		GameEngineSprite::CreateSingle("CursorHand.png");

	}


	{
	SetOrder(GameObjectType::Cursor);
	Renderer = CreateComponent<GameEngineUIRenderer>();
	Renderer->SetSprite("CursorArrow.png");
	Renderer->Transform.SetLocalPosition({ -GameEngineCore::MainWindow.GetScale().hX(),GameEngineCore::MainWindow.GetScale().hY() });
	Renderer->AutoSpriteSizeOn();
	Renderer->SetAutoScaleRatio(2.0);
	Renderer->SetRenderOrder(RenderOrder::Cursor);
	Renderer->SetPivotType(PivotType::LeftTop);

	}


	{
		CursorCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Cursor);
		CursorCollision->Transform.SetLocalScale({ 5.0f,5.0f,1.0f });
		CursorCollision->SetCollisionType(ColType::AABBBOX2D);
		float4 CollisionScale = CursorCollision->Transform.GetLocalScale();
		CursorCollision->Transform.AddLocalPosition({ CollisionScale.hX(),-CollisionScale.hY() });
	}

	PrevCursorPos= GetLevel()->GetMainCamera()->GetWorldMousePos2D();
	GameEngineInput::AddInputObject(this);
}

void Cursor::Update(float _Delta)
{
	
	
	float4 CusorPos = GetLevel()->GetMainCamera()->GetWorldMousePos2D();
	Transform.SetLocalPosition(CusorPos);
	

		
	


	
	
	
	
	

	/*if (콜리전조건)
	{
	Renderer->SetSprite("CursorHand.png");

	}
	else
	{
	Renderer->SetSprite("CursorArrow.png");
	}*/

	{
		EventParameter Para;
		Para.Stay = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{

			
					if (GameEngineInput::IsDown(VK_LBUTTON, this))
					{



						float4 PrevPos = _Other->GetActor()->Transform.GetWorldPosition();

						_Other->GetActor()->ChangeParent(dynamic_cast<GameEngineObject*>(this), 0);
						_Other->GetActor()->Transform.SetLocalPosition(PrevPos - this->Transform.GetLocalPosition());



					}

					if (GameEngineInput::IsPress(VK_LBUTTON, this))
					{


						//_Other->GetActor()->Transform.AddLocalPosition(CusorPos - PrivCursorPos);

					}

					GameEngineObject* paobj = _Other->GetActor()->GetParentObject();

					if (paobj == this && GameEngineInput::IsUp(VK_LBUTTON, this))
					{

						_Other->GetActor()->ChangeParent(dynamic_cast<GameEngineObject*>(GetLevel()), 0);

						float4 PrevLocalPos = _Other->GetActor()->Transform.GetLocalPosition();
						_Other->GetActor()->Transform.SetLocalPosition(this->Transform.GetLocalPosition() + PrevLocalPos);

					}


			};

		Para.Enter = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{
				std::vector<class GameEngineCollision*>::iterator Start = PaperCollisions.begin();
				std::vector<class GameEngineCollision*>::iterator End = PaperCollisions.end();

				for (; Start != End;)
				{
					
					if (*Start != _Other)
					{
						Start++;
						continue;
					}
					else
					{
						return;
					}
					

				}

					PaperCollisions.push_back(_Other);

			};

		Para.Exit = [=](class GameEngineCollision* _This, class GameEngineCollision* _Other)
			{
				std::vector<class GameEngineCollision*>::iterator Start = PaperCollisions.begin();
				std::vector<class GameEngineCollision*>::iterator End = PaperCollisions.end();


				for (; Start != End;)
				{

					if (*Start != _Other)
					{
						Start++;
						continue;
					}
					else
					{
						PaperCollisions.erase(Start);
						return;
					}

				}
				
				
			};

		CursorCollision->CollisionEvent(CollisionOrder::Papers, Para);
	

	}

	PrevCursorPos = Transform.GetLocalPosition();


	//if (GameEngineInput::IsDown(VK_LBUTTON, this))
	//{
	//	if (false == PaperCollisions.empty())
	//	{
	//		
	//		std::vector<class GameEngineCollision*>::iterator Start = PaperCollisions.begin();
	//		std::vector<class GameEngineCollision*>::iterator End = PaperCollisions.end();
	//		

	//		GameEngineCollision* PaperCollision=*Start;
	//		
	//		for (; Start != End;)
	//		{
	//			if(*Start)
	//			
	//				Start++;
	//				continue;
	//		}


	//	}
	//}


	
}
