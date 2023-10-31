#pragma once
#include "ContentsEnum.h"
#include <vector>
#include<string>


class TravelerInfo
{
public:

	class FaceInfo
	{
	public:
		std::string SheetName = "";
		int SheetX = -1;
		int SheetY = -1;

	};

	TravelerInfo();
	~TravelerInfo();

	//TravelerInfo(const TravelerInfo& _Other) = delete;
	//TravelerInfo(TravelerInfo&& _Other) noexcept = delete;
	//TravelerInfo& operator=(const TravelerInfo& _Other) = delete;
	//TravelerInfo& operator=(const TravelerInfo&& _Other) noexcept = delete;



	int Sex = -1;
	Country OriginCountry;
	int City = -1;
	std::vector<int> Date_of_Birth;
	FaceInfo Face;

};