
#pragma once
#include "TravelerInfo.h"

class PassPort
{
public:
	PassPort();
	~PassPort();

	PassPort(const PassPort& _Other) = delete;
	PassPort(PassPort&& _Other) noexcept = delete;
	PassPort& operator=(const PassPort& _Other) = delete;
	PassPort& operator=(const PassPort&& _Other) noexcept = delete;

	void SetOwner(std::shared_ptr<class NormalTraveler> _Owner);
	
	std::shared_ptr<class NormalTraveler> GetOwner() const
	{
		return Owner;
	}

protected:

private:

	std::shared_ptr<class NormalTraveler> Owner=nullptr;
	TravelerInfo Info;
};

