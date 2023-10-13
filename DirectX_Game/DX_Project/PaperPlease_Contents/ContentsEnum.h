#pragma once

enum class RenderOrder
{
	BackGround,
	BackGroundChange,
	Car,
	People,
	OuterBox,
	Play,
	UI,
	Cursor,
};

enum class GameObjectType
{
	BackGround,
	Play,
	UIButton,
	Cursor,
};


enum class CollisionOrder
{
	Cursor,
	UI_Button,
	Papers,
	Play,
};
