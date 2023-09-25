
#pragma once
#include <GameEngineCore/GameEngineActor.h>


class PaperBase : public GameEngineActor
{
public:
	PaperBase();
	~PaperBase();

	PaperBase(const PaperBase& _Other) = delete;
	PaperBase(PaperBase&& _Other) noexcept = delete;
	PaperBase& operator=(const PaperBase& _Other) = delete;
	PaperBase& operator=(const PaperBase&& _Other) noexcept = delete;


	virtual void SetTexture(std::string_view _Name);

	std::shared_ptr<class GameEngineSpriteRenderer> GetSpriteRenderer() const
	{
		return PaperRenderer;
	}

protected:
	void Start() override;

	std::shared_ptr <class GameEngineSpriteRenderer> PaperRenderer;

	std::shared_ptr<class GameEngineTexture> InnerTexture;
	std::shared_ptr<class GameEngineTexture> OuterTexture;

private:


	

};

