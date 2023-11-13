
#pragma once

class Car :public GameEngineActor
{
public:
	Car();
	~Car();

	Car(const Car& _Other) = delete;
	Car(Car&& _Other) noexcept = delete;
	Car& operator=(const Car& _Other) = delete;
	Car& operator=(const Car&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	
};

