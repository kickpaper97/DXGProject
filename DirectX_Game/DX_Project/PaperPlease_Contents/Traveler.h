
#pragma once
#include "PeopleBase.h"

class Traveler :public	GameEngineActor
{
public:
	Traveler();
	~Traveler();

	Traveler(const Traveler& _Other) = delete;
	Traveler(Traveler&& _Other) noexcept = delete;
	Traveler& operator=(const Traveler& _Other) = delete;
	Traveler& operator=(const Traveler&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:

};

