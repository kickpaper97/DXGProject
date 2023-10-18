#include "PreCompile.h"
#include "ControlManager.h"

void ControlManager::Start()
{

	Tabs.push_back(std::make_shared<LevelChangeTab>("LevelChange"));
	Tabs.push_back(std::make_shared<DebugSwitchTab>("DebugSwitch"));
	CurTab = Tabs[0];
}

void ControlManager::OnGUI(GameEngineLevel* _Level, float _Delta)
{

	for (size_t i = 0; i < Tabs.size(); i++)
	{
		ImGui::SameLine();
		if (ImGui::Button(Tabs[i]->Name.c_str()))
		{
			CurTab = Tabs[i];
			ImGui::NewLine();
		}
	}

	if (nullptr != CurTab)
	{
		CurTab->OnGUI(_Level, _Delta);
	}
}

void LevelChangeTab::OnGUI(GameEngineLevel* _Level, float _Delta)
{
	std::map<std::string, std::shared_ptr<GameEngineLevel>>& AllLevels = GameEngineCore::GetAllLevel();

	std::vector<std::string> Names;
	for (std::pair<const std::string, std::shared_ptr<GameEngineLevel>> Pair : AllLevels)
	{
		/*if (ImGui::Button(Pair.first.c_str()))
		{
			GameEngineCore::ChangeLevel(Pair.first);
		}*/
		Names.push_back(Pair.first);
	}

	std::vector<const char*> CNames;

	for (size_t i = 0; i < Names.size(); i++)
	{
		CNames.push_back(Names[i].c_str());
	}

	if (ImGui::ListBox("LevelList", &Select, &CNames[0], static_cast<int>(Names.size())))
	{
		GameEngineCore::ChangeLevel(Names[Select]);
	}
}

void DebugSwitchTab::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	if (ImGui::Button("Collision OnOff"))
	{
		GameEngineLevel::IsDebug = !GameEngineLevel::IsDebug;
	}
}

