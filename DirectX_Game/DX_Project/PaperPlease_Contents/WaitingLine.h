
#pragma once
#include <list>



class WaitingLine :public GameEngineActor
{
public:
	WaitingLine();
	~WaitingLine();

	WaitingLine(const WaitingLine& _Other) = delete;
	WaitingLine(WaitingLine&& _Other) noexcept = delete;
	WaitingLine& operator=(const WaitingLine& _Other) = delete;
	WaitingLine& operator=(const WaitingLine&& _Other) noexcept = delete;

	void AddPerson();
	void AddPerson(const float4& _Position);

	std::shared_ptr<class NormalTraveler> CallFirstPerson();


protected:

private:
	std::list<std::shared_ptr<class NormalTraveler>> Waitings;

};

