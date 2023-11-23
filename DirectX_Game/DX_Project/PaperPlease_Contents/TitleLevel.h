#pragma once
#include "LevelBase.h"
#


enum class TitleState
{
	Anime,
	Waiting,
};



class TitleLevel : public LevelBase
{
public:
	// constrcuter destructer
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;


	GameEngineSoundPlayer GetSound() const
	{
		return Sound;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	

private:
	float DeltaCheck = 0.5f;
	float4 AnimationDir = float4::UP;
	bool isAnimation = true;
	bool isAnimaitonPause = false;

	std::shared_ptr<class BasicActor> Logo = nullptr;

	GameEngineSoundPlayer Sound;
	GameEngineState LevelState;
	
};

