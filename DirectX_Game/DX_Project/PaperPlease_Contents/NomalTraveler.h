
#pragma once
#include "PeopleBase.h"

class NomalTraveler : public PeopleBase
{
public:
	NomalTraveler();
	~NomalTraveler();

	NomalTraveler(const NomalTraveler& _Other) = delete;
	NomalTraveler(NomalTraveler&& _Other) noexcept = delete;
	NomalTraveler& operator=(const NomalTraveler& _Other) = delete;
	NomalTraveler& operator=(const NomalTraveler&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:

};

