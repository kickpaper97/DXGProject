
#pragma once

class BoothDoor : public GameEngineActor
{
public:
	BoothDoor();
	~BoothDoor();

	BoothDoor(const BoothDoor& _Other) = delete;
	BoothDoor(BoothDoor&& _Other) noexcept = delete;
	BoothDoor& operator=(const BoothDoor& _Other) = delete;
	BoothDoor& operator=(const BoothDoor&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	float4 Scale;
	std::shared_ptr<GameEngineSpriteRenderer> sprite;
	float Timer = 5.0f;
	int Dir = 0;
	bool isSoundEffect=false;
};

