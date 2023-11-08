
#pragma once

class Stamp : public GameEngineActor
{
public:
	Stamp();
	~Stamp();

	Stamp(const Stamp& _Other) = delete;
	Stamp(Stamp&& _Other) noexcept = delete;
	Stamp& operator=(const Stamp& _Other) = delete;
	Stamp& operator=(const Stamp&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<GameEngineSpriteRenderer> StampRenderer = nullptr;
	std::shared_ptr<GameEngineSpriteRenderer> StampTop = nullptr;	
private:

};

