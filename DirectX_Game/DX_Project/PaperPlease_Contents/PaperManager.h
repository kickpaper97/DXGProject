
#pragma once
#include <GameEngineCore/GameEngineActor.h>


class PaperManager : public GameEngineActor
{
public:
	PaperManager();
	~PaperManager();

	PaperManager(const PaperManager& _Other) = delete;
	PaperManager(PaperManager&& _Other) noexcept = delete;
	PaperManager& operator=(const PaperManager& _Other) = delete;
	PaperManager& operator=(const PaperManager&& _Other) noexcept = delete;

	

protected:
	void Start() override;

private:
	std::vector<class PaperBase> PaperVector;
};

