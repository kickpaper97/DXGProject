
#pragma once
#include "PaperBase.h"

class PlayPaper:public PaperBase
{
public:
	PlayPaper();
	~PlayPaper();

	PlayPaper(const PlayPaper& _Other) = delete;
	PlayPaper(PlayPaper&& _Other) noexcept = delete;
	PlayPaper& operator=(const PlayPaper& _Other) = delete;
	PlayPaper& operator=(const PlayPaper&& _Other) noexcept = delete;

	bool GetIsOut() const
	{
		return IsOut;
	}
protected:
	void Start() override;
	void Update(float _Delta)override;

	bool IsOut = false;


private:
};

