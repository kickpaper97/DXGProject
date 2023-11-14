
#pragma once

class PaperManager :public GameEngineActor
{
public:
	PaperManager();
	~PaperManager();

	PaperManager(const PaperManager& _Other) = delete;
	PaperManager(PaperManager&& _Other) noexcept = delete;
	PaperManager& operator=(const PaperManager& _Other) = delete;
	PaperManager& operator=(const PaperManager&& _Other) noexcept = delete;


protected:
	void Start() override;
	
	
	void AddPaper(std::shared_ptr<class PaperBase> _Paper)
	{

		Papers.push_back(_Paper);
		IsPapersEmpty = false;
	}

	void ReleasePaper(std::shared_ptr<class PaperBase> _Paper);


	int FindIndex(std::shared_ptr<class PaperBase> _Paper);

	bool GetIsEmpty() const
	{
		return IsPapersEmpty;
	}

private:
	bool IsPapersEmpty=true;

	std::vector<std::shared_ptr<class PaperBase>> Papers;

};

