
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

	void SetOuterPaperRotation(const float4& _Rotation);
	

protected:
	void Start() override;
	void Update(float _Delta) override;

	virtual void SetWrongInfo();

	std::shared_ptr<GameEngineSpriteRenderer> InnerRenderer=nullptr;
	std::shared_ptr<GameEngineSpriteRenderer> OuterRenderer=nullptr;
	std::shared_ptr<GameEngineCollision> Collision;

	
private:

	float4 InnerLocalPos=float4::ZERO;
	
	float4 OuterPaperRotation = float4::ZERO;


	

	

};

