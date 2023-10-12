#include "PreCompile.h"
#include "WaitingLine.h"
#include "PeopleBase.h"

WaitingLine::WaitingLine()
{
}

WaitingLine::~WaitingLine()
{
}

void WaitingLine::AddPerson()
{
	std::shared_ptr<PeopleBase> NewPerson(new PeopleBase());
	Waitings->push_back(NewPerson);

}

std::shared_ptr<PeopleBase> WaitingLine::CallFirstPerson()
{

	std::list<std::shared_ptr<PeopleBase>>::iterator beginiter = Waitings.get()->begin();
	Waitings.get()->erase(beginiter);
	return (*beginiter);

}


