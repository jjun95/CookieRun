#pragma once
#include "Struct.h"
class CMaps;

class CCollision_Manager
{
public:
	CCollision_Manager();
	~CCollision_Manager();
public:
	//static void Collision_Rect(list<CObj*>& rDstList, list<CObj*>& rSrcList);
	static void Collision_Rect(list<CMaps*>& rDstList, list<CObj*>& rSrcList);
	static void Collision_Sphere(list<CObj*>& rDstList, list<CObj*>& rSrcList);
	static void Collision_RectEX(list<CObj*>& rDstList, list<CObj*>& rSrcList);
	static bool Collision_RectEX(list<CMaps*>& rDstList, list<CObj*>& rSrcList);
private:
	static bool CheckSphere(const CObj* pDstObject, const CObj* rSrcObject);
	static bool CheckRect(const CObj* pDstObject, const CObj* rSrcObject, float* pMoveX, float* pMoveY);
	static bool CheckRect(CMaps* pDstObject, const CObj* rSrcObject, float* pMoveX, float* pMoveY);
};

