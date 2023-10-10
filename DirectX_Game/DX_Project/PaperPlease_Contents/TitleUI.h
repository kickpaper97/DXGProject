
#pragma once

class TitleUI :public GameEngineActor
{
public:
	TitleUI();
	~TitleUI();

	TitleUI(const TitleUI& _Other) = delete;
	TitleUI(TitleUI&& _Other) noexcept = delete;
	TitleUI& operator=(const TitleUI& _Other) = delete;
	TitleUI& operator=(const TitleUI&& _Other) noexcept = delete;


protected:

private:
	void Start() override;
	void Update(float _Delta) override;

};

