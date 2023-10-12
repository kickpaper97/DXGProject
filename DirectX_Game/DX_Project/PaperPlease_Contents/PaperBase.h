
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


	virtual void SetPaperTexture(std::string_view _Name);
	void SetPaperTexture(std::string_view _InnerName, std::string_view _OuterName);


	std::shared_ptr<class GameEngineSpriteRenderer> GetSpriteRenderer() const
	{
		return PaperRenderer;
	}


	std::shared_ptr<class GameEngineTexture> GetInnerTexture() const
	{
		return InnerTexture;
	}

	std::shared_ptr<class GameEngineTexture> GetOuterTexture() const
	{
		return OuterTexture;
	}

	std::shared_ptr<GameEngineCollision> GetCollision() const
	{
		return Collision;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;
private:



	std::shared_ptr <class GameEngineSpriteRenderer> PaperRenderer;
	std::shared_ptr<GameEngineCollision> Collision;

	std::shared_ptr<class GameEngineTexture> InnerTexture;
	std::shared_ptr<class GameEngineTexture> OuterTexture;

	

};

