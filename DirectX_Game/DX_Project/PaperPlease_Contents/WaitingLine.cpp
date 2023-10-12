#include "PreCompile.h"
#include "WaitingLine.h"
#include "PeopleBase.h"
#include "NomalTraveler.h"

WaitingLine::WaitingLine()
{
}

WaitingLine::~WaitingLine()
{
}

void WaitingLine::AddPerson()
{
	std::shared_ptr<PeopleBase> NewPerson(new NomalTraveler);
	Waitings.push_back(NewPerson);

}

std::shared_ptr<PeopleBase> WaitingLine::CallFirstPerson()
{

	std::shared_ptr<PeopleBase> First = Waitings.front();
	Waitings.pop_front();
	/*std::list<std::shared_ptr<PeopleBase>>::iterator beginiter = Waitings.get()->begin();
	Waitings.get()->erase(beginiter);*/
	
	return First;
	

}


