
#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BasicActor : public GameEngineActor
{
public:
	BasicActor();
	~BasicActor();

	BasicActor(const BasicActor& _Other) = delete;
	BasicActor(BasicActor&& _Other) noexcept = delete;
	BasicActor& operator=(const BasicActor& _Other) = delete;
	BasicActor& operator=(const BasicActor&& _Other) noexcept = delete;

	
	GameEngineSpriteRenderer* GetSpriteRenderer() const
	{
		return SpriteRenderer.get();
	}

protected:

	void Start() override;

	

private:
	std::shared_ptr<class GameEngineSpriteRenderer> SpriteRenderer = nullptr;

};

