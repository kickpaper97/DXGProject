
#pragma once
#include<GameEngineCore/GameEngineLevel.h>

class DayOffLevel :public GameEngineLevel
{
public:
	DayOffLevel();
	~DayOffLevel();

	DayOffLevel(const DayOffLevel& _Other) = delete;
	DayOffLevel(DayOffLevel&& _Other) noexcept = delete;
	DayOffLevel& operator=(const DayOffLevel& _Other) = delete;
	DayOffLevel& operator=(const DayOffLevel&& _Other) noexcept = delete;


	void SetCurDay(int _Curday)
	{
		Curday = _Curday;
	}
protected:
	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	int Curday = 0;

};

