
#pragma once

class Cusor
{
public:
	Cusor();
	~Cusor();

	Cusor(const Cusor& _Other) = delete;
	Cusor(Cusor&& _Other) noexcept = delete;
	Cusor& operator=(const Cusor& _Other) = delete;
	Cusor& operator=(const Cusor&& _Other) noexcept = delete;


protected:

private:

};

