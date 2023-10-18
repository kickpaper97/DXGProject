
#pragma once

class StampBar : public	GameEngineActor
{
public:
	StampBar();
	~StampBar();

	StampBar(const StampBar& _Other) = delete;
	StampBar(StampBar&& _Other) noexcept = delete;
	StampBar& operator=(const StampBar& _Other) = delete;
	StampBar& operator=(const StampBar&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

	//void LevelStart(GameEngineLevel* _Prev) override;
	//void LevelEnd(GameEngineLevel* _Next) override;
private:

	std::shared_ptr<GameEngineComponent> ApprovedStamp = nullptr;
	std::shared_ptr<GameEngineComponent> DeniedStamp = nullptr;

};

