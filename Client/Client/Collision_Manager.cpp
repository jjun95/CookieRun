#include "stdafx.h"
#include "Collision_Manager.h"
#include "Obj.h"
#include "Player.h"
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
				int coin = rDstObject->Get_Coin();
				int score = rDstObject->Get_Score();
				MAP::DETAILED_ID eDTID = rDstObject->Get_DTID();
				rSrcObject->Set_Coin(coin);
				rSrcObject->Set_Score(score);
				rDstObject->Set_Dead();
				switch (eDTID) {
				case MAP::SMALLHP:
					dynamic_cast<CPlayer*>(rSrcObject)->Set_Hp(20);
					break;
				case MAP::BIGHP:
					dynamic_cast<CPlayer*>(rSrcObject)->Set_Hp(50);
					break;
				case MAP::BOOSTER:
					break;
				case MAP::GIANT:
					break;
				case MAP::MAGNET:
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
				//rDstObject->Set_Dead();
				//rSrcObject->Set_Dead();
				if (!dynamic_cast<CPlayer*>(rSrcObject)->Get_isHit()) {
					dynamic_cast<CPlayer*>(rSrcObject)->Set_Hp(-30);
					dynamic_cast<CPlayer*>(rSrcObject)->Set_Hit();
				}
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
	// 1.�簢�� �ΰ��� x�������� �������� ���� ����. 
	float fRadiusSumX = static_cast<float>((pDstObject->Get_Info()->iCX >> 1) + (rSrcObject->Get_Info()->iCX >> 1));
	//2.�簢�� �ΰ��� y�������� �������� ���� ����. 
	float fRadiusSumY = static_cast<float>((pDstObject->Get_Info()->iCY >> 1) + (rSrcObject->Get_Info()->iCY >> 1));

	// x��� y���� �Ÿ� ����. 
	float fDistX = fabs(pDstObject->Get_Info()->fX - rSrcObject->Get_Info()->fX);
	float fDistY = fabs(pDstObject->Get_Info()->fY - rSrcObject->Get_Info()->fY);

	// ���� �ΰ��� �Ÿ��� �������� ���� ���� ��. 
	if (fDistX <= fRadiusSumX && fDistY <= fRadiusSumY)
	{
		*pMoveX = fRadiusSumX - fDistX;
		*pMoveY = fRadiusSumY - fDistY; 
		return true;
	}
	// �ΰ��� �Ÿ��� �� ª�ٶ�� ? �浹. 
	return false; 
}

bool CCollision_Manager::CheckRect(CMaps * pDstObject, const CObj * rSrcObject, float * pMoveX, float * pMoveY)
{
	// 1.�簢�� �ΰ��� x�������� �������� ���� ����. 
	float fRadiusSumX = static_cast<float>((pDstObject->Get_MapInfo()->tPoint.iCY >> 1) + (rSrcObject->Get_Info()->iCX >> 1));
	//2.�簢�� �ΰ��� y�������� �������� ���� ����. 
	float fRadiusSumY = static_cast<float>((pDstObject->Get_MapInfo()->tPoint.iCY >> 1) + (rSrcObject->Get_Info()->iCY >> 1));

	float fMapfX = pDstObject->Get_MapInfo()->tPoint.fX + pDstObject->Get_Speed() - pDstObject->Get_MapInfo()->tPoint.iCX;

	// x��� y���� �Ÿ� ����. 
	float fDistX = fabs(fMapfX - rSrcObject->Get_Info()->fX);
	float fDistY = fabs(pDstObject->Get_MapInfo()->tPoint.fY - rSrcObject->Get_Info()->fY);

	// ���� �ΰ��� �Ÿ��� �������� ���� ���� ��. 
	if (fDistX <= fRadiusSumX && fDistY <= fRadiusSumY)
	{
		*pMoveX = fRadiusSumX - fDistX;
		*pMoveY = fRadiusSumY - fDistY;
		return true;
	}
	// �ΰ��� �Ÿ��� �� ª�ٶ�� ? �浹. 
	return false;
}
