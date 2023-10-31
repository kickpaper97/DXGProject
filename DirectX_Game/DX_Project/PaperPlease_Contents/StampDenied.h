
#pragma once

class StampDenied
{
public:
	StampDenied();
	~StampDenied();

	StampDenied(const StampDenied& _Other) = delete;
	StampDenied(StampDenied&& _Other) noexcept = delete;
	StampDenied& operator=(const StampDenied& _Other) = delete;
	StampDenied& operator=(const StampDenied&& _Other) noexcept = delete;


protected:

private:

};

