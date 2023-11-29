
#pragma once

class InkApproved:public GameEngineActor
{
public:
	InkApproved();
	~InkApproved();

	InkApproved(const InkApproved& _Other) = delete;
	InkApproved(InkApproved&& _Other) noexcept = delete;
	InkApproved& operator=(const InkApproved& _Other) = delete;
	InkApproved& operator=(const InkApproved&& _Other) noexcept = delete;

	
	float4 PassPortPos = float4::ZERO;

	void SetPassPortParent();

protected:
	std::shared_ptr<class CustomSpriteRenderer> StampSpriteRenderer;
	void Start() override;
	void Update(float _Delta) override;
private:

};

