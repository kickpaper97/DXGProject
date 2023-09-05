
#pragma once
#include "BasicActor.h"

class BasicButton : public BasicActor
{
public:
	BasicButton();
	~BasicButton();

	BasicButton(const BasicButton& _Other) = delete;
	BasicButton(BasicButton&& _Other) noexcept = delete;
	BasicButton& operator=(const BasicButton& _Other) = delete;
	BasicButton& operator=(const BasicButton&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta)override;
private:

};

