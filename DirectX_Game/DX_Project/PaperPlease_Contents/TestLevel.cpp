#include "PreCompile.h"
#include "TestLevel.h"

#include "Cursor.h"
#include "PassPort.h"

TestLevel::TestLevel()
{
}

TestLevel::~TestLevel()
{
}

void TestLevel::Start()
{

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);


	GameEngineInput::AddInputObject(this);



	std::shared_ptr<Cursor> newcursor = CreateActor<Cursor>();
	std::shared_ptr<PassPort>newpor = CreateActor<PassPort>();

	newpor->Transform.SetLocalPosition({ 700,-300 });


}

void TestLevel::Update(float _Delta)
{
}

void TestLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
}

void TestLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
}
