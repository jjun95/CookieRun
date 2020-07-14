#pragma once
class CMapBlock
{
public:
	explicit CMapBlock();
	explicit CMapBlock(const MAPINFO& mapInfo);
	~CMapBlock();

public:
	MAPINFO* Get_MapInfo() { return &m_tInfo; }
	void Set_Pos(const MAPPOS& pos) { m_tInfo.tPoint = pos; }
public:
	void Render_Map(HDC hDC);
private:
	MAPINFO m_tInfo;
};

