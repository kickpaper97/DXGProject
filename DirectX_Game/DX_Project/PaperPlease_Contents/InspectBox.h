
#pragma once


class InspectBox 
{
public:
	InspectBox();
	~InspectBox();

	InspectBox(const InspectBox& _Other) = delete;
	InspectBox(InspectBox&& _Other) noexcept = delete;
	InspectBox& operator=(const InspectBox& _Other) = delete;
	InspectBox& operator=(const InspectBox&& _Other) noexcept = delete;


protected:

private:

};

