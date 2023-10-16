
#pragma once


class InspectBox : GameEngineComponent
{
public:
	InspectBox();
	~InspectBox();

	InspectBox(const InspectBox& _Other) = delete;
	InspectBox(InspectBox&& _Other) noexcept = delete;
	InspectBox& operator=(const InspectBox& _Other) = delete;
	InspectBox& operator=(const InspectBox&& _Other) noexcept = delete;


protected:

	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<GameEngineSpriteRenderer> Renderer = nullptr;
	std::shared_ptr<GameEngineCollision> Collision = nullptr;

};

