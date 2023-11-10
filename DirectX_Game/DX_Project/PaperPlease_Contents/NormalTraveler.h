
#pragma once
#include "PeopleBase.h"
#include "TravelerInfo.h"


enum TravelerState
{
	WaitingStand,
	WatingMove,
	TurnStart,
	TurnStay,
	TurnEnd,
	Max,

};




class NormalTraveler : public PeopleBase
{
public:
	NormalTraveler();
	~NormalTraveler();

	NormalTraveler(const NormalTraveler& _Other) = delete;
	NormalTraveler(NormalTraveler&& _Other) noexcept = delete;
	NormalTraveler& operator=(const NormalTraveler& _Other) = delete;
	NormalTraveler& operator=(const NormalTraveler&& _Other) noexcept = delete;


	class TravelerInfo GetInfo() const
	{
		return Info;
	}

	
	std::shared_ptr<GameEngineSpriteRenderer> FaceRenderer = nullptr;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelEnd(GameEngineLevel* _Next) override;


	void RandomSetTravelerInfo();
	void RandomSetFace();


	std::shared_ptr<GameEngineSpriteRenderer> GetFaceRenderer()
	{
		return FaceRenderer;
	}


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
	//std::shared_ptr<GameEngineSpriteRenderer> FaceRenderer = nullptr;
	GameEngineRandom TimeRand;

	TravelerInfo Info;

	float StandingChangeTime = 0.0f;

};
