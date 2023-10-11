
#pragma once


class BasicButton : public GameEngineActor
{
public:
	BasicButton();
	~BasicButton();

	BasicButton(const BasicButton& _Other) = delete;
	BasicButton(BasicButton&& _Other) noexcept = delete;
	BasicButton& operator=(const BasicButton& _Other) = delete;
	BasicButton& operator=(const BasicButton&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineUIRenderer> GetSpriteRenderer() const
	{
		return SpriteRenderer;
	}

protected:
	void Start() override;
	void Update(float _Delta)override;
private:

	std::shared_ptr<class GameEngineUIRenderer> SpriteRenderer = nullptr;
};

