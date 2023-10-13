#include "PreCompile.h"
#include "WaitingLine.h"

#include "NomalTraveler.h"
#include "Cursor.h"

WaitingLine::WaitingLine()
{
}

WaitingLine::~WaitingLine()
{
}

void WaitingLine::AddPerson()
{

	AddPerson(Cursor::MainCursor->Transform.GetLocalPosition());

}

void WaitingLine::AddPerson(const float4& _Position)
{
	std::shared_ptr<PeopleBase> NewPerson = GetLevel()->CreateActor<NomalTraveler>();
	NewPerson.get()->Transform.SetLocalPosition(_Position);
	Waitings.push_back(static_cast<std::shared_ptr<PeopleBase>>(NewPerson));
}

std::shared_ptr<PeopleBase> WaitingLine::CallFirstPerson()
{

	std::shared_ptr<PeopleBase> First = Waitings.front();
	Waitings.pop_front();
	/*std::list<std::shared_ptr<PeopleBase>>::iterator beginiter = Waitings.get()->begin();
	Waitings.get()->erase(beginiter);*/
	
	return First;
	

}


