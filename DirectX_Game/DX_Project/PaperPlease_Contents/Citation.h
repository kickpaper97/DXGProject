
#pragma once
#include "PaperBase.h"

class Citation :public PaperBase
{
public:
	Citation();
	~Citation();

	Citation(const Citation& _Other) = delete;
	Citation(Citation&& _Other) noexcept = delete;
	Citation& operator=(const Citation& _Other) = delete;
	Citation& operator=(const Citation&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;
private:

};

