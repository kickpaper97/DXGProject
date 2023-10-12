
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

	std::shared_ptr<class PeopleBase> CallFirstPerson();


protected:

private:
	std::shared_ptr<std::list<std::shared_ptr<class PeopleBase>>> Waitings;

};

