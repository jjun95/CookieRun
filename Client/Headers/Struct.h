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
		fX = static_cast<int>(_fx / 90) * 90 - 45;
		fY = static_cast<int>(_fy / 90) * 90 - 45;
	}
	float fX;
	float fY;
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