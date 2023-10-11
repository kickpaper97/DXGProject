
#pragma once


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


protected:
	void Start() override;
	void Update(float _Delta) override;
private:

	std::shared_ptr<GameEngineSpriteRenderer> Renderer;
	std::shared_ptr<GameEngineCollision> CursorCollision;

};

