
#pragma once
#include "PaperBase.h"
#include "TravelerInfo.h"



class PassPort : public PaperBase
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
	void StampPassPort(PassPortChecked _Check, float4 _StampPos);

protected:
	void Start() override;
	void Update(float _Delta) override;
	void SetPaperTexture(std::string_view _Name) override;

private:

	std::shared_ptr<class NormalTraveler> Owner=nullptr;

	
	
	
	TravelerInfo Info;
	PassPortChecked EntryCheck = PassPortChecked::Yet;
};

