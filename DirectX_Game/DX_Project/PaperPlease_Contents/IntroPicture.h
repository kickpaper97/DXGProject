
#pragma once

class IntroPicture :public GameEngineActor
{
public:
	IntroPicture();
	~IntroPicture();

	IntroPicture(const IntroPicture& _Other) = delete;
	IntroPicture(IntroPicture&& _Other) noexcept = delete;
	IntroPicture& operator=(const IntroPicture& _Other) = delete;
	IntroPicture& operator=(const IntroPicture&& _Other) noexcept = delete;

	std::shared_ptr<class CustomSpriteRenderer> GetSpriteRenderer() const
	{
		return SpriteRenderer;
	}
protected:
	void Start() override;

	std::shared_ptr<class CustomSpriteRenderer> SpriteRenderer = nullptr;
private:

};

