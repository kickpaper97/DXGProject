
#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class StartIntroLevel :public GameEngineLevel
{
public:
	StartIntroLevel();
	~StartIntroLevel();

	StartIntroLevel(const StartIntroLevel& _Other) = delete;
	StartIntroLevel(StartIntroLevel&& _Other) noexcept = delete;
	StartIntroLevel& operator=(const StartIntroLevel& _Other) = delete;
	StartIntroLevel& operator=(const StartIntroLevel&& _Other) noexcept = delete;


protected:

private:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;
};

