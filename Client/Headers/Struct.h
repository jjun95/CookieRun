#pragma once

typedef struct tagInfo
{
	float fX; 
	float fY; 
	int iCX;
	int iCY; 
}INFO;

typedef struct tagMapPoint
{
	tagMapPoint()
	{
		ZeroMemory(this, sizeof(tagMapPoint));
	}
	void SetPosition(float _fx, float _fy)
	{
		fX = static_cast<int>(_fx / iCX) * iCX + iCX / 2.f;
		fY = static_cast<int>(_fy / iCY) * iCY + iCY / 2.f;
	}

	float fX;
	float fY;
	int iCX;
	int iCY;
}MAPPOS;

typedef struct tagMapInfo
{
	tagMapInfo()
	{
		ZeroMemory(this, sizeof(tagMapInfo));
	}
	tagMapInfo(int _iCX, int _iCY)
	{
		ZeroMemory(this, sizeof(tagMapInfo));
		tPoint.iCX = _iCX;
		tPoint.iCY = _iCY;
	}
	MAPPOS tPoint;
}MAPINFO;

typedef struct tagFramge {
	int iDefaultStartFrame;
	int iStartFrame;
	int iEndFrame;
	int iSceneFrame;
	DWORD dwFrameTime;
	DWORD dwFrameSpeed;
}FRAME;