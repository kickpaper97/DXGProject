
#pragma once
#include "PeopleBase.h"

enum TravelerState
{
	WaitingStand,
	WatingMove,
	TurnStart,
	TurnStay,
	TurnEnd,
	Max,

};

class NomalTraveler : public PeopleBase
{
public:
	NomalTraveler();
	~NomalTraveler();

	NomalTraveler(const NomalTraveler& _Other) = delete;
	NomalTraveler(NomalTraveler&& _Other) noexcept = delete;
	NomalTraveler& operator=(const NomalTraveler& _Other) = delete;
	NomalTraveler& operator=(const NomalTraveler&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _Delta) override;



	void WaitingStandStart();
	void WaitingMoveStart();
	void TurnStartStart();
	void TurnStayStart();
	void TurnEndStart();

	void WaitingStandUpdate(float _Delta);
	void WaitingMoveUpdate(float _Delta);
	void TurnStartUpdate(float _Delta);
	void TurnStayUpdate(float _Delta);
	void TurnEndUpdate(float _Delta);



	void StateUpdate(float _Delta);
	void ChanageState(TravelerState _State);
	void ChangeAnimationState(std::string_view _State);

	TravelerState State = TravelerState::Max;
	std::string_view CurState = "";

private:
	GameEngineRandom TimeRand;
	

	float StandingChangeTime = 0.0f;

};

