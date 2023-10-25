
#pragma once
#include "Cursor.h"

class BasicButton : public GameEngineActor
{
public:
	BasicButton();
	~BasicButton();

	BasicButton(const BasicButton& _Other) = delete;
	BasicButton(BasicButton&& _Other) noexcept = delete;
	BasicButton& operator=(const BasicButton& _Other) = delete;
	BasicButton& operator=(const BasicButton&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> GetSpriteRenderer() const
	{
		return SpriteRenderer;
	}

protected:
	void Start() override;
	void Update(float _Delta)override;
	
	std::shared_ptr<class GameEngineSpriteRenderer> SpriteRenderer = nullptr;
	std::shared_ptr<GameEngineCollision> Collision;

	
private:

};

