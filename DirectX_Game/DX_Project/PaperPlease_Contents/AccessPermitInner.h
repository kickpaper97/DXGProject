
#pragma once
#include "PaperBase.h"
#include "TravelerInfo.h"


class AccessPermitInner : public PaperBase
{
public:
	AccessPermitInner();
	~AccessPermitInner();

	AccessPermitInner(const AccessPermitInner& _Other) = delete;
	AccessPermitInner(AccessPermitInner&& _Other) noexcept = delete;
	AccessPermitInner& operator=(const AccessPermitInner& _Other) = delete;
	AccessPermitInner& operator=(const AccessPermitInner&& _Other) noexcept = delete;
	
	
	void SetOwner(std::shared_ptr<class NormalTraveler> _Owner);

	std::shared_ptr<class NormalTraveler> GetOwner() const
	{
		return Owner;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;
private:

	std::shared_ptr<class NormalTraveler> Owner = nullptr;


	TravelerInfo Info;
};

