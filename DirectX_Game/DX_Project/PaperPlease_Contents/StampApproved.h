
#pragma once

class StampApproved :public GameEngineActor 
{
public:
	StampApproved();
	~StampApproved();

	StampApproved(const StampApproved& _Other) = delete;
	StampApproved(StampApproved&& _Other) noexcept = delete;
	StampApproved& operator=(const StampApproved& _Other) = delete;
	StampApproved& operator=(const StampApproved&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;
private:

};

