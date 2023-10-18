#pragma once

#define LINEPOS_X  356.0f
#define LINEPOS_Y  434.0f

enum class RenderOrder
{
	BackGround,
	BackGroundChange,
	Car,
	People,
	OuterBox,
	Play,
	StampBarBot,
	Stamp,
	StampBars,
	UI,
	Cursor,
};

enum class GameObjectType
{
	BackGround,
	Play,
	Stamp,
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



////////////////////////////////////////

enum class Country
{
	Antegria,
	Arstotzka,
	Impor,
	Kolechia,
	Obristan,
	Republia,
	United_Federation,
};

enum class Antegria_City
{
	St_Marmero,
	Glorian,
	Outer_Grouse,
};
enum class Arstotzka_City
{
	Orvech_Vonor,
	East_Grestin,
	Paradizna,

};
enum class Impor_City
{
	Enkyo,
	Haihan,
	Tsunkeido,
};
enum class Kolechia_City
{
	Yurko_City,
	Vedor,
	West_Grestin,
};
enum class Obristan_City
{
	Skal,
	Lorndaz,
	Mergerous,
};
enum class Republia_City
{
	True_Glorian,
	Lesrenadi,
	Bostan,
};
enum class United_Federation_City
{
	Great_Rapid,
	Shingleton,
	Korista_City,
};