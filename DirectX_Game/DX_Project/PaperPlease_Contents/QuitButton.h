
#pragma once
#include "BasicButton.h"

class QuitButton :public BasicButton
{
public:
	QuitButton();
	~QuitButton();

	QuitButton(const QuitButton& _Other) = delete;
	QuitButton(QuitButton&& _Other) noexcept = delete;
	QuitButton& operator=(const QuitButton& _Other) = delete;
	QuitButton& operator=(const QuitButton&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;

private:

};

