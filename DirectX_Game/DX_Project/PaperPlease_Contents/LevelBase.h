
#pragma once
#include <GameEngineCore/GameEngineLevel.h>


class LevelBase : public GameEngineLevel
{
public:
	LevelBase();
	~LevelBase();

	LevelBase(const LevelBase& _Other) = delete;
	LevelBase(LevelBase&& _Other) noexcept = delete;
	LevelBase& operator=(const LevelBase& _Other) = delete;
	LevelBase& operator=(const LevelBase&& _Other) noexcept = delete;

	void UIOn();
	void UIOff();
protected:


private:
	bool isUI = true;
};

