#include "PreCompile.h"
#include "StartIntroLevel.h"
#include "BasicActor.h"
#include "Cursor.h"

StartIntroLevel::StartIntroLevel()
{
}

StartIntroLevel::~StartIntroLevel()
{
}

void StartIntroLevel::Start()
{
	
	{
		GameEngineSprite::CreateSingle("Intro0.png");
		GameEngineSprite::CreateSingle("Intro1.png");
		GameEngineSprite::CreateSingle("Intro2.png");
		GameEngineSprite::CreateSingle("Intro3.png");
		GameEngineSprite::CreateSingle("Arstotzka.png");
	}

	IntroPIcture = CreateActor<BasicActor>(GameObjectType::BackGround);
	IntroPIcture->GetSpriteRenderer()->SetSprite("intro0.png");

}

void StartIntroLevel::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown(VK_RETURN))
	{

	}
	

}

void StartIntroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	std::shared_ptr<Cursor> NewCursor = CreateActor<Cursor>(GameObjectType::Cursor);

}

void StartIntroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}
