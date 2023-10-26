
#pragma once

class NextBell : public GameEngineActor
{
public:
	NextBell();
	~NextBell();

	NextBell(const NextBell& _Other) = delete;
	NextBell(NextBell&& _Other) noexcept = delete;
	NextBell& operator=(const NextBell& _Other) = delete;
	NextBell& operator=(const NextBell&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<GameEngineSpriteRenderer> SpriteRenderer;

	std::shared_ptr<GameEngineCollision> Collision;
};

