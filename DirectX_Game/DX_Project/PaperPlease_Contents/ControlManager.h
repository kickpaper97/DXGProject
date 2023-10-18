
#pragma once

class Tab
{
public:
	std::string Name;


	virtual void Start() {}
	virtual void OnGUI(GameEngineLevel* _Level, float _Delta) = 0;

	Tab(std::string_view _Name)
	{
		Name = _Name;
	}

};

class LevelChangeTab : public Tab
{
private:
	void OnGUI(GameEngineLevel* _Level, float _Delta);

	int Select = 0;
	std::shared_ptr<GameEngineLevel> SelectLevel = nullptr;

public:
	LevelChangeTab(std::string_view _Name)
		: Tab(_Name)
	{
	}
};

class DebugSwitchTab : public Tab
{
public:

	DebugSwitchTab(std::string_view _Name)
		: Tab(_Name)
	{
	}
private:
	void OnGUI(GameEngineLevel* _Level, float _DeltaTime);
};



class ControlManager : public GameEngineGUIWindow
{
public:
	void Start() override;
	void OnGUI(GameEngineLevel* _Level, float _Delta) override;

	std::shared_ptr <Tab> CurTab;
	std::vector<std::shared_ptr<Tab>> Tabs;

};

