
#pragma once
#include "LevelBase.h"

enum class IntroState
{
	Intro0,
	Intro1,
	Intro2,
	Intro3,
	Intro4,
};
class StartIntroLevel :public LevelBase
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
	std::shared_ptr<class IntroPicture> IntroPic;

	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	
	GameEngineState LevelState;
};

