#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DayPlayInfo
{
	friend class Player;
public:
	void Clear()
	{
		CheckCorrectCount = 0;
		CheckWrongCount = 0;
	}

	void AutoAddCount(int _Check) 
	{
		if (0 == _Check)
		{
			AddWrongCount();
		}
		else
		{
			AddCorrectCount();

		}

	}



	void AddCorrectCount()
	{
		CheckCorrectCount++;
	}
	void AddWrongCount()
	{
		CheckWrongCount++;
	}

	int GetCorrectCount() const
	{
		return CheckCorrectCount;
	}
	int GetWrongCount() const
	{
		return CheckWrongCount;
	}

private:
	int CheckCorrectCount = 0;
	int CheckWrongCount = 0;

};



class Player : public GameEngineActor
{
	

public:

	static Player* MainPlayer;

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	void TestEvent(GameEngineRenderer* _Renderer);
	std::shared_ptr<class GameEngineSpriteRenderer> GetOuterSpriteRenderer() const
	{
		return OuterSpriteRenderer;
	}


	DayPlayInfo PlayerDayPlay;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> OuterSpriteRenderer;

	int Savings = 0;
	int FamillyPassPort = 0;
	int Class = 8;

};

