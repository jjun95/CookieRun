#pragma once

typedef struct tagInfo
{
	float fX; 
	float fY; 
	int iCX;
	int iCY; 
}INFO;

typedef struct tagLinePoint
{
	tagLinePoint()
	{
		ZeroMemory(this, sizeof(tagLinePoint));
	}
	tagLinePoint(float _fx, float _fy)
		:fX(_fx), fY(_fy)
	{}
	float fX; 
	float fY; 
}LINEPOS;

typedef struct tagMapPoint
{
	tagMapPoint()
	{
		ZeroMemory(this, sizeof(tagMapPoint));
	}
	tagMapPoint(float _fx, float _fy)
	{
		fLeft = static_cast<int>(_fx / MAPTILE_SIZE) * MAPTILE_SIZE;
		fTop = static_cast<int>(_fy / MAPTILE_SIZE) * MAPTILE_SIZE;
	}
	float fLeft;
	float fTop;
}MAPPOS;

typedef struct tagLineInfo
{
	tagLineInfo()
	{
		ZeroMemory(this, sizeof(tagLineInfo)); 
	}
	tagLineInfo(const LINEPOS& rLeftPoint, const LINEPOS& rRightPoint)
		:tLPoint(rLeftPoint)
		, tRPoint(rRightPoint)
	{}
	LINEPOS tLPoint; 
	LINEPOS tRPoint; 
}LINEINFO;

typedef struct tagMapInfo
{
	tagMapInfo()
	{
		ZeroMemory(this, sizeof(tagMapInfo));
	}
	MAPPOS tPoint;
}MAPINFO;