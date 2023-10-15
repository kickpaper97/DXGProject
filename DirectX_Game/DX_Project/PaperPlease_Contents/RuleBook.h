
#pragma once
#include "PaperBase.h"

class RuleBook : public PaperBase
{
public:
	RuleBook();
	~RuleBook();

	RuleBook(const RuleBook& _Other) = delete;
	RuleBook(RuleBook&& _Other) noexcept = delete;
	RuleBook& operator=(const RuleBook& _Other) = delete;
	RuleBook& operator=(const RuleBook&& _Other) noexcept = delete;

	
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::vector<std::shared_ptr<class GameEngineSprite>> Pages;
	

	
};

