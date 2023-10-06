
#pragma once
#include "BasicActor.h"

class Cursor : public BasicActor
{
public:

	static Cursor* MainCursor;


	Cursor();
	~Cursor();

	Cursor(const Cursor& _Other) = delete;
	Cursor(Cursor&& _Other) noexcept = delete;
	Cursor& operator=(const Cursor& _Other) = delete;
	Cursor& operator=(const Cursor&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;
private:


	std::shared_ptr<GameEngineCollision> CursorCollision;

};

