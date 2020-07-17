#pragma once
class CScroll_Manager
{
public:
	CScroll_Manager();
	~CScroll_Manager();

	static const int& Get_ScrollX() { return m_iScrollX; }
	static void Set_ScrollX(int iScrollX) { m_iScrollX += iScrollX; }

private:
	static int m_iScrollX;
};

