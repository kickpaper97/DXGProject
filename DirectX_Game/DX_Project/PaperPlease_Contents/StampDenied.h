
#pragma once
#include "Stamp.h"


class StampDenied :  public Stamp
{
public:
	StampDenied();
	~StampDenied();

	StampDenied(const StampDenied& _Other) = delete;
	StampDenied(StampDenied&& _Other) noexcept = delete;
	StampDenied& operator=(const StampDenied& _Other) = delete;
	StampDenied& operator=(const StampDenied&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;
private:

	bool IsMoving = false;

	std::vector<std::shared_ptr<GameEngineCollision>> Collisions;

	std::shared_ptr<GameEngineCollision> StampCheck;

	GameEngineSoundPlayer SoundEffect;
	GameEngineState State;

};

