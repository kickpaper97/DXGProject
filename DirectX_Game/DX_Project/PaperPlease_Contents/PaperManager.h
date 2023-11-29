
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
	
	


	void AddPaper(std::shared_ptr<class PaperBase> _Paper)
	{

		Papers.push_back(_Paper);
		if (false == IsPapersEmpty)
		{
		IsPapersEmpty = false;

		}
	}

	void ReleasePaper(std::shared_ptr<class PaperBase> _Paper);


	int FindIndex(std::shared_ptr<class PaperBase> _Paper);

	bool GetIsPapersEmpty() const
	{
		return IsPapersEmpty;
	}

	std::shared_ptr<class PassPort> GetCurPassPort();


	void ClearIsCorrectCheck()
	{
		IsCorrectCheck = -1;
	}
	int GetIsCorrectCheck() const
	{
		return IsCorrectCheck;
	}

protected:
	void Start() override;
	
	


private:

	bool IsPapersEmpty=true;
	int IsCorrectCheck = -1;

	std::vector<std::shared_ptr<class PaperBase>> Papers;

};

