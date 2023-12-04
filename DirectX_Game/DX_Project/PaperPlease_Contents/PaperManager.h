
#pragma once

class PaperManager :public GameEngineActor
{
public:

	static PaperManager* MainPaperManager;

	PaperManager();
	~PaperManager();

	PaperManager(const PaperManager& _Other) = delete;
	PaperManager(PaperManager&& _Other) noexcept = delete;
	PaperManager& operator=(const PaperManager& _Other) = delete;
	PaperManager& operator=(const PaperManager&& _Other) noexcept = delete;
	
	




	bool GetIsPapersEmpty() const
	{
		return IsPapersEmpty;
	}

	
	int GetIsCorrectCheck() const
	{
		return IsCorrectCheck;
	}

	bool GetIsPassPortChecked()
	{
		return IsPassPortChecked;
	}

	void AddPaper(std::shared_ptr<class PlayPaper> _Paper);
	void WorkInit(std::shared_ptr<class NormalTraveler> _CurTraveler);


	void ReleasePaper();
__int64 FindIndex(std::shared_ptr<class PlayPaper> _Paper);


	void PassPortCheck();
	void PaperRenderChange();
	
	void SetPassPortEntryCheck(PassPortChecked _EntryCheck)
	{
		EntryCheck = _EntryCheck;
		IsPassPortChecked = true;
	}

protected:
	void Start() override;
	
	


private:

	bool IsPapersEmpty=true;
	bool IsPassPortChecked = false;
	int IsCorrectCheck = -1;

	PassPortChecked EntryCheck = PassPortChecked::Yet;

	std::shared_ptr<class NormalTraveler> CurTraveler;
	std::vector<std::shared_ptr<class PlayPaper>> Papers;

};

