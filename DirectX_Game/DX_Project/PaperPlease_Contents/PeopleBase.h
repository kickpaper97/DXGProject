
#pragma once


class PeopleBase : public GameEngineActor
{
public:
	PeopleBase();
	~PeopleBase();

	PeopleBase(const PeopleBase& _Other) = delete;
	PeopleBase(PeopleBase&& _Other) noexcept = delete;
	PeopleBase& operator=(const PeopleBase& _Other) = delete;
	PeopleBase& operator=(const PeopleBase&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr< GameEngineSpriteRenderer> OuterRenderer;
	std::shared_ptr<GameEngineCollision> OuterCollision;
private:
	

};

