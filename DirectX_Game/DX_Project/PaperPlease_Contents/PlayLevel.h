#pragma once
#include "LevelBase.h"

// Ό³Έν :
enum class PlayState
{
	DayStart,
	BeforeWork,
	Working,
	Event,
	Waiting,
	AfterWork,
};


class PlayLevel : public LevelBase
{
public:
	// constrcuter destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;

	int GetCurDay() const
	{
		return CurDay;
	}

protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	int CurDay=30;

	std::shared_ptr<class PlayMap> NewMap;
	std::shared_ptr<class WaitingLine> NewLine = nullptr;
	std::shared_ptr<class NextBell> NewBell = nullptr;

	std::shared_ptr<GameEngineActor> NewStamp = nullptr;

	float WorkTime=0;
	GameEngineState LevelState;

};

