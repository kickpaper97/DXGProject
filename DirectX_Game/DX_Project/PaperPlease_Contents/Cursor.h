
#pragma once
#include "BasicActor.h"

class Cursor : public GameEngineActor
{
public:

	static Cursor* MainCursor;

	

	Cursor();
	~Cursor();

	Cursor(const Cursor& _Other) = delete;
	Cursor(Cursor&& _Other) noexcept = delete;
	Cursor& operator=(const Cursor& _Other) = delete;
	Cursor& operator=(const Cursor&& _Other) noexcept = delete;

	std::shared_ptr<GameEngineCollision> GetCursorCollision() const
	{
		return CursorCollision;
	}

	std::shared_ptr<GameEngineUIRenderer> GetRenderer() const
	{
		return Renderer;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	float4 PrivCursorPos = float4::ZERO;

	std::shared_ptr<GameEngineUIRenderer> Renderer;
	std::shared_ptr<GameEngineCollision> CursorCollision;

};

