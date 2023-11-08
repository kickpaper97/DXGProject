
#pragma once

class DayOffBackGround :public GameEngineActor
{
public:
	DayOffBackGround();
	~DayOffBackGround();

	DayOffBackGround(const DayOffBackGround& _Other) = delete;
	DayOffBackGround(DayOffBackGround&& _Other) noexcept = delete;
	DayOffBackGround& operator=(const DayOffBackGround& _Other) = delete;
	DayOffBackGround& operator=(const DayOffBackGround&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	std::shared_ptr<GameEngineSpriteRenderer> Class = nullptr;

	std::shared_ptr<GameEngineSpriteRenderer> WifeCondition = nullptr;
	std::shared_ptr<GameEngineSpriteRenderer> SonCondition = nullptr;
	std::shared_ptr<GameEngineSpriteRenderer> MotherCondition = nullptr;
	std::shared_ptr<GameEngineSpriteRenderer> UncleCondition = nullptr;
};

