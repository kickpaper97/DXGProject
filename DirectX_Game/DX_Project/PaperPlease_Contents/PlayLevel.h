#pragma once
#include "LevelBase.h"

// Ό³Έν :
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
	int CurDay=-1;

	std::shared_ptr<GameEngineActor> NewStamp = nullptr;
	std::shared_ptr<class WaitingLine> NewLine = nullptr;
};

