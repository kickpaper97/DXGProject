
#pragma once
#include "PeopleBase.h"
#include "ContentsEnum.h"
#include <vector>

enum TravelerState
{
	WaitingStand,
	WatingMove,
	TurnStart,
	TurnStay,
	TurnEnd,
	Max,

};


class TravelerInfo
{
public:

	class FaceInfo
	{
	public:
		std::string SheetName="";
		int SheetX = -1;
		int SheetY = -1;

	};


	int Sex=-1;
	Country OriginCountry;
	int City=-1;
	std::vector<int> Date_of_Birth;
	FaceInfo Face;

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
	GameEngineRandom TimeRand;
	
	std::shared_ptr<GameEngineSpriteRenderer> FaceRenderer = nullptr;
	TravelerInfo Info;

	float StandingChangeTime = 0.0f;

};
