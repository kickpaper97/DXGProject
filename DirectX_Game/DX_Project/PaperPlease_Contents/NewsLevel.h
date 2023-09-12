
#pragma once

class NewsLevel
{
public:
	NewsLevel();
	~NewsLevel();

	NewsLevel(const NewsLevel& _Other) = delete;
	NewsLevel(NewsLevel&& _Other) noexcept = delete;
	NewsLevel& operator=(const NewsLevel& _Other) = delete;
	NewsLevel& operator=(const NewsLevel&& _Other) noexcept = delete;


protected:

private:

};

