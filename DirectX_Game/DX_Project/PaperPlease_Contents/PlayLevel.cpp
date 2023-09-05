#include "PreCompile.h"
#include "PlayLevel.h"
#include "BasicActor.h"
#include "PlayMap.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("assets");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}

		GameEngineSprite::CreateSingle("CheckpointBack.png");
		GameEngineSprite::CreateSingle("Desk.png");
		//GameEngineSprite::CreateSingle("Console.png");
		GameEngineSprite::CreateSingle("BoothWall.png");

	}

	

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f});
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);


	{
		//std::shared_ptr<Player> Object = CreateActor<Player>();
	}

	{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>();
	}

}

void PlayLevel::Update(float _Delta)
{
	
}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}
