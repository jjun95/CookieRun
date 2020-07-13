#pragma once
class CObj;
template<typename T>
class CAbstractFactory
{
public:
	static CObj* Create()
	{
		CObj* pObj = new T; 
		pObj->Ready_Object();
		return pObj; 
	}
	static CObj* Create(float fX, float fY)
	{
		CObj* pObj = new T;
		pObj->Ready_Object();
		pObj->Set_Pos(fX, fY); 
		return pObj;
	}
	static CObj* Create(float fX, float fY, float fAngle)
	{
		CObj* pObj = new T;
		pObj->Ready_Object();
		pObj->Set_Angle(fAngle); 
		pObj->Set_Pos(fX, fY);
		return pObj;
	}

};