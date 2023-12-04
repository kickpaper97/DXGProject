
#pragma once
#include "PlayPaper.h"
#include "TravelerInfo.h"

enum class PassPortState
{
	PassportIn,
	PassportOut,
};

class PassPort : public PlayPaper
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

	PassPortChecked GetEntryCheck() const
	{
		return EntryCheck;
	}

	

protected:
	void Start() override;
	void Update(float _Delta) override;
	void SetPaperTexture(std::string_view _Name) override;
	

private:
	std::shared_ptr<GameEngineSpriteRenderer> Picture;

	std::shared_ptr<class NormalTraveler> Owner=nullptr;

	

	GameEngineState State;
	
	TravelerInfo Info;
	PassPortChecked EntryCheck = PassPortChecked::Yet;
};

