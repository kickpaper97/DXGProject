
#pragma once
#include "PeopleBase.h"

class Guard : public PeopleBase
{
public:
	Guard();
	~Guard();

	Guard(const Guard& _Other) = delete;
	Guard(Guard&& _Other) noexcept = delete;
	Guard& operator=(const Guard& _Other) = delete;
	Guard& operator=(const Guard&& _Other) noexcept = delete;

	void SetDestinationPos(const float4& _Pos)
	{
		DestinationPos = _Pos;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float4 DestinationPos;
	int Standing=0;
	bool isStand=false;
};

