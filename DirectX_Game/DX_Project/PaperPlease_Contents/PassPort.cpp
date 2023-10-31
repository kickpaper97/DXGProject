#include "PreCompile.h"
#include "PassPort.h"
#include "NormalTraveler.h"

PassPort::PassPort()
{
}

PassPort::~PassPort()
{
}

void PassPort::SetOwner(std::shared_ptr<class NormalTraveler> _Owner)
{
	Owner = _Owner;
	Info = _Owner.get()->GetInfo();
}
