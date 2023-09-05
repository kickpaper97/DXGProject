#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class Player : public GameEngineActor
{
	class PlayerData 
	{
	public:
		int Savings = 0;
		int PassPort = 0;
		int Class = 8;
		
	};
public:
	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void TestEvent(GameEngineRenderer* _Renderer);

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainSpriteRenderer;
	float4 GrivityForce = {0.0f, 0.0f, 0.0f, 1.0f};
};

