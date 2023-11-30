#include "PreCompile.h"
#include "AccessPermitInner.h"
#include "NormalTraveler.h"

AccessPermitInner::AccessPermitInner()
{
}

AccessPermitInner::~AccessPermitInner()
{
}

void AccessPermitInner::SetOwner(std::shared_ptr<class NormalTraveler> _Owner)
{
	Owner = _Owner;
	Info = _Owner.get()->GetInfo();
}

void AccessPermitInner::Start()
{
	if (nullptr == GameEngineSprite::Find("AccessPermitInner.png"))
	{
		GameEngineSprite::CreateSingle("AccessPermitInner.png");
		GameEngineSprite::CreateSingle("AccessPermitIOuter.png");

	}

	PaperBase::Start();
	SetPaperTexture("AccessPermit");

	

}

void AccessPermitInner::Update(float _Delta)
{
	PaperBase::Update(_Delta);



}
