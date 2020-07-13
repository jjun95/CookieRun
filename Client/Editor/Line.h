#pragma once
class CLine final
{
public:
	explicit CLine();
	explicit CLine(const LINEINFO& rLineInfo); 
	virtual ~CLine();
public:
	LINEINFO* Get_LineInfo() { return &m_tInfo; }
	void Set_RightPos(const LINEPOS& rRightPos) { m_tInfo.tRPoint = rRightPos; }
public:
	void Render_Line(HDC hDC); 
private:
	LINEINFO m_tInfo; 
};

