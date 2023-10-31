#include "PreCompile.h"
#include "PeopleBase.h"

PeopleBase::PeopleBase()
{

}

PeopleBase::~PeopleBase()
{
}

void PeopleBase::Start()
{

	OuterRenderer->SetRenderOrder(RenderOrder::People);
	
}

void PeopleBase::Update(float _Delta)
{
}


