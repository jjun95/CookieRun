#include "stdafx.h"
#include "Collision_Manager.h"
#include "Obj.h"
#include "Obj_Manager.h"
#include "Player.h"
#include "Pet.h"
#include "Maps.h"
#include "MapBlock.h"

CCollision_Manager::CCollision_Manager()
{
}


CCollision_Manager::~CCollision_Manager()
{
}

//void CCollision_Manager::Collision_Rect(list<CObj*>& rDstList, list<CObj*>& rSrcList)
//{
//	RECT rc = {}; 
//	for (auto& rDstObject : rDstList)
//	{
//		for (auto& rSrcObject : rSrcList)
//		{
//			if (IntersectRect(&rc,&rDstObject->Get_Rect(), &rSrcObject->Get_Rect()))
//			{
//				rDstObject->Set_Dead(); 
//				rSrcObject->Set_Dead(); 
//			}
//		}
//	}
//}

void CCollision_Manager::Collision_ScoreRect(list<CMaps*>& rDstList, list<CObj*>& rSrcList)
{
	RECT rc = {};
	for (auto& rDstObject : rDstList)
	{
		for (auto& rSrcObject : rSrcList)
		{
			if (IntersectRect(&rc, rDstObject->Get_MapRect(), rSrcObject->Get_Rect()))
			{
				//if (dynamic_cast<CPlayer*>(CObj_Manager::Get_Instance()->Get_Player())->Get_Hp() <= 0)
				//	return;
				int coin = rDstObject->Get_Coin();
				int score = rDstObject->Get_Score() + ( 50 * CObj::Get_JellyLevel());
				MAP::DETAILED_ID eDTID = rDstObject->Get_DTID();
				dynamic_cast<CPlayer*>(CObj_Manager::Get_Instance()->Get_Player())->Set_Coin(coin);
				dynamic_cast<CPlayer*>(CObj_Manager::Get_Instance()->Get_Player())->Set_Score(score);
				rDstObject->Set_Dead();
				switch (eDTID) {
				case MAP::SMALLHP:
					dynamic_cast<CPlayer*>(rSrcObject)->Set_Hp(20);
					break;
				case MAP::BIGHP:
					dynamic_cast<CPlayer*>(rSrcObject)->Set_Hp(40);
					break;
				case MAP::BOOSTER:
					CMap_Manager::Get_Instance()->Set_Speed(DEFAULT_SPEED * 2);
					dynamic_cast<CPlayer*>(rSrcObject)->Set_IsBoost();
					break;
				case MAP::GIANT:
					dynamic_cast<CPlayer*>(rSrcObject)->Set_IsGiant();
					break;
				case MAP::MAGNET:
					dynamic_cast<CPet*>(CObj_Manager::Get_Instance()->Get_Pet())->Set_Magnet();
					CMap_Manager::Get_Instance()->Set_Magnet(true);
					break;
				}
			}
		}
	}
}

void CCollision_Manager::Collision_ObstacleRect(list<CMaps*>& rDstList, list<CObj*>& rSrcList)
{
	RECT rc = {};
	for (auto& rDstObject : rDstList)
	{
		for (auto& rSrcObject : rSrcList)
		{
			if (IntersectRect(&rc, rDstObject->Get_MapRect(), rSrcObject->Get_Rect()))
			{
				bool isBoost = dynamic_cast<CPlayer*>(rSrcObject)->Get_IsBoost();
				bool isGiant = dynamic_cast<CPlayer*>(rSrcObject)->Get_IsGiant();
				if (isBoost || isGiant) {
					rDstObject->Set_Dead();
					return;
				}
				dynamic_cast<CPlayer*>(rSrcObject)->Set_Hp(-30);
				dynamic_cast<CPlayer*>(rSrcObject)->Set_Hit();
			}
		}
	}
}

void CCollision_Manager::Collision_Sphere(list<CObj*>& rDstList, list<CObj*>& rSrcList)
{
	for (auto& rDstObject : rDstList)
	{
		for (auto& rSrcObject : rSrcList)
		{
			if (CheckSphere(rDstObject, rSrcObject))
			{
				rDstObject->Set_Dead();
				rSrcObject->Set_Dead();
			}
		}
	}
}

void CCollision_Manager::Collision_RectEX(list<CObj*>& rDstList, list<CObj*>& rSrcList)
{
	float fMoveX = 0.f, fMoveY = 0.f; 

	for (auto& rDstObject : rDstList)
	{
		for (auto& rSrcObject : rSrcList)
		{
			if (CheckRect(rDstObject, rSrcObject, &fMoveX, &fMoveY))
			{
				float fX = rSrcObject->Get_Info()->fX; 
				float fY = rSrcObject->Get_Info()->fY; 

				if (fMoveX > fMoveY)
				{
					if (fY < rDstObject->Get_Info()->fY)
						fMoveY *= -1.f; 
					
					rSrcObject->Set_Pos(fX, fY + fMoveY); 
				}
				else
				{
					if (fX < rDstObject->Get_Info()->fX)
						fMoveX *= -1.f; 
					rSrcObject->Set_Pos(fX + fMoveX, fY);
				}
			}
		}
	}

}

bool CCollision_Manager::Collision_RectEX(list<CMaps*>& rDstList, list<CObj*>& rSrcList)
{
	float fMoveX = 0.f, fMoveY = 0.f;
	bool isCollide = false;

	for (auto& rDstObject : rDstList)
	{
		for (auto& rSrcObject : rSrcList)
		{
			if (CheckRect(rDstObject, rSrcObject, &fMoveX, &fMoveY))
			{
				isCollide = true;
				float fX = rSrcObject->Get_Info()->fX;
				float fY = rSrcObject->Get_Info()->fY;

//				if (fMoveX > fMoveY)
//				{
					if (fY < rDstObject->Get_MapInfo()->tPoint.fY)
						fMoveY *= -1.f;

					rSrcObject->Set_Pos(fX, fY + fMoveY);

				if (dynamic_cast<CPlayer*>(rSrcObject)->Get_Hp() <= 0)
					dynamic_cast<CPlayer*>(rSrcObject)->Set_Dead();
//				}
				//else
				//{
				//	if (fX < rDstObject->Get_MapInfo()->tPoint.fX)
				//		fMoveX *= -1.f;
				//	rSrcObject->Set_Pos(fX + fMoveX, fY);
				//}
			}
		}
	}
	return isCollide;
}

bool CCollision_Manager::CheckSphere(const CObj * pDstObject, const CObj * rSrcObject)
{
	float fRadiusSum = static_cast<float>((pDstObject->Get_Info()->iCX >> 1) + (rSrcObject->Get_Info()->iCX >> 1));
	float fX = pDstObject->Get_Info()->fX - rSrcObject->Get_Info()->fX;
	float fY = pDstObject->Get_Info()->fY - rSrcObject->Get_Info()->fY;
	float fDist = sqrtf(fX * fX + fY * fY); 

	return fDist <fRadiusSum;
}

bool CCollision_Manager::CheckRect(const CObj * pDstObject, const CObj * rSrcObject, float * pMoveX, float * pMoveY)
{
	// 1.사각형 두개의 x축으로의 반지름의 합을 구함. 
	float fRadiusSumX = static_cast<float>((pDstObject->Get_Info()->iCX >> 1) + (rSrcObject->Get_Info()->iCX >> 1));
	//2.사각형 두개의 y축으로의 반지름의 합을 구함. 
	float fRadiusSumY = static_cast<float>((pDstObject->Get_Info()->iCY >> 1) + (rSrcObject->Get_Info()->iCY >> 1));

	// x축과 y축의 거리 구함. 
	float fDistX = fabs(pDstObject->Get_Info()->fX - rSrcObject->Get_Info()->fX);
	float fDistY = fabs(pDstObject->Get_Info()->fY - rSrcObject->Get_Info()->fY);

	// 구한 두개의 거리와 반지름의 합을 각각 비교. 
	if (fDistX <= fRadiusSumX && fDistY <= fRadiusSumY)
	{
		*pMoveX = fRadiusSumX - fDistX;
		*pMoveY = fRadiusSumY - fDistY; 
		return true;
	}
	// 두개의 거리가 더 짧다라면 ? 충돌. 
	return false; 
}

bool CCollision_Manager::CheckRect(CMaps * pDstObject, const CObj * rSrcObject, float * pMoveX, float * pMoveY)
{
	// 1.사각형 두개의 x축으로의 반지름의 합을 구함. 
	float fRadiusSumX = static_cast<float>((pDstObject->Get_MapInfo()->tPoint.iCY >> 1) + (rSrcObject->Get_Info()->iCX >> 1));
	//2.사각형 두개의 y축으로의 반지름의 합을 구함. 
	float fRadiusSumY = static_cast<float>((pDstObject->Get_MapInfo()->tPoint.iCY >> 1) + (rSrcObject->Get_Info()->iCY >> 1));

	float fMapfX = pDstObject->Get_MapInfo()->tPoint.fX + pDstObject->Get_Speed() - pDstObject->Get_MapInfo()->tPoint.iCX;

	// x축과 y축의 거리 구함. 
	float fDistX = fabs(fMapfX - rSrcObject->Get_Info()->fX);
	float fDistY = fabs(pDstObject->Get_MapInfo()->tPoint.fY - rSrcObject->Get_Info()->fY);

	// 구한 두개의 거리와 반지름의 합을 각각 비교. 
	if (fDistX <= fRadiusSumX && fDistY <= fRadiusSumY)
	{
		*pMoveX = fRadiusSumX - fDistX;
		*pMoveY = fRadiusSumY - fDistY;
		return true;
	}
	// 두개의 거리가 더 짧다라면 ? 충돌. 
	return false;
}
