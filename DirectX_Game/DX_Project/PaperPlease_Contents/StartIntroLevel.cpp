#include "PreCompile.h"
#include "StartIntroLevel.h"
#include "BasicActor.h"

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

	IntroPIcture = CreateActor<BasicActor>(GameObjectType::UI);
	IntroPIcture->GetSpriteRenderer()->SetSprite("intro0.png");

}

void StartIntroLevel::Update(float _Delta)
{


}

void StartIntroLevel::LevelStart(GameEngineLevel* _PrevLevel)
{

}

void StartIntroLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}
