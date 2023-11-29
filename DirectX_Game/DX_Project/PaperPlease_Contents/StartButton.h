
#pragma once
#include "BasicButton.h"

class StartButton :public BasicButton
{
public:
	StartButton();
	~StartButton();

	StartButton(const StartButton& _Other) = delete;
	StartButton(StartButton&& _Other) noexcept = delete;
	StartButton& operator=(const StartButton& _Other) = delete;
	StartButton& operator=(const StartButton&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:

};

