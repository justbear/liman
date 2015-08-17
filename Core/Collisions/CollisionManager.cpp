#include "CollisionManager.h"

#include "../Subsystems/BaseGameLogic.h"
#include "../Subsystems/Application.h"
#include "../Levels/LevelManager.h"

#include "../Maths/Maths.h"
#include "../Actors/Actor.h"

#include <iostream>
#include <bitset>

#include "../Game.h"

namespace liman {

	extern BaseGameLogic* g_pBGL;
	extern Application* g_pApp;

	bool IsPointInsideActor(maths::Vec2f point, Actor* pActor);
	bool CompareActors(Actor* pAnalized, Actor* pActor2, CollisionSide& side);

	CollisionManager::CollisionManager()
	{

	}

	CollisionManager::~CollisionManager()
	{

	}

	void CollisionManager::UpdateCollision()
	{
		for (ActorId id1 = 1; (signed int)id1 < g_pBGL->GetLevelManager()->GetNumActors() + 1; id1++)
		{
			Collidable* ColComp1;
			g_pBGL->GetLevelManager()->GetActor(id1)->GetComponent(COLLIDING, &ColComp1);

			if (ColComp1 != NULL)
			{
				for (ActorId id2 = id1 + 1; (signed int)id2 < g_pBGL->GetLevelManager()->GetNumActors() + 1; id2++)
				{
					Collidable* ColComp2;
					g_pBGL->GetLevelManager()->GetActor(id2)->GetComponent(COLLIDING, &ColComp2);

					if (ColComp2 != NULL)
					{
						CheckCollision(g_pBGL->GetLevelManager()->GetActor(id1), g_pBGL->GetLevelManager()->GetActor(id2));
					}
				}
			}
		}
	}



	void CollisionManager::CheckCollision(Actor* pActor1, Actor* pActor2)
	{
		bool isCollDetected = false;
		CollisionSide side1 = NULL_SIDE;
		CollisionSide side2 = NULL_SIDE;

		isCollDetected = CompareActors(pActor1, pActor2, side1);
		if (!isCollDetected)
		{
			isCollDetected = CompareActors(pActor2, pActor1, side2);
		}

		if (!isCollDetected)
		{
			return;
		}
		else
		{
			if (side1 == NULL_SIDE) printf("Error: side not detected.\n");
		
			if (side1 > 12) side2 = CollisionSide(side1 - 12);
			else side2 = CollisionSide(side1 + 12);

			Collidable *ColComp1, *ColComp2;
			pActor1->GetComponent(COLLIDING, &ColComp1);
			pActor2->GetComponent(COLLIDING, &ColComp2);
			
			ColComp1->Collide(pActor2, side1);
			ColComp2->Collide(pActor1, side2);
		}
	}

	const std::bitset<4> topRightSet(std::string("0001"));
	const std::bitset<4> bottomRightSet(std::string("0010"));
	const std::bitset<4> bottomLeftSet(std::string("0100"));
	const std::bitset<4> topLeftSet(std::string("1000"));

	bool CompareActors(Actor* pAnalized, Actor* pActor2, CollisionSide& side)
	{
		bool isCollDetected = false;

		bool collTopRight = false;
		bool collTopLeft = false;
		bool collBottomRight = false;
		bool collBottomLeft = false;

		float right = pAnalized->GetPos().x + pAnalized->GetSize().x / 2;
		float left = pAnalized->GetPos().x - pAnalized->GetSize().x / 2;
		float bottom = pAnalized->GetPos().y - pAnalized->GetSize().y / 2;
		float top = pAnalized->GetPos().y + pAnalized->GetSize().y / 2;

		maths::Vec2f topRigthPoint1(right, top);
		maths::Vec2f topLeftPoint1(left, top);
		maths::Vec2f bottomRightPoint1(right, bottom);
		maths::Vec2f bottomLeftPoint1(left, bottom);
	
		std::bitset<4> pointsSet(std::string("0000"));

		if (IsPointInsideActor(topRigthPoint1, pActor2))
		{
			collTopRight = true;
			pointsSet |= topRightSet;
		}
		if (IsPointInsideActor(topLeftPoint1, pActor2))
		{
			collTopLeft = true;
			pointsSet |= topLeftSet;
		}
		if (IsPointInsideActor(bottomRightPoint1, pActor2))
		{
			collBottomRight = true;
			pointsSet |= bottomRightSet;
		}
		if (IsPointInsideActor(bottomLeftPoint1, pActor2))
		{
			collBottomLeft = true;
			pointsSet |= bottomLeftSet;
		}

		if (pointsSet == topRightSet) side = TOP_RIGHT;
		if (pointsSet == (topRightSet | bottomRightSet)) side = RIGHT;
		if (pointsSet == bottomRightSet) side = BOTTOM_RIGHT;
		if (pointsSet == (bottomLeftSet | bottomRightSet)) side = BOTTOM;
		if (pointsSet == bottomLeftSet) side = BOTTOM_LEFT;
		if (pointsSet == (bottomLeftSet | topLeftSet)) side = LEFT;
		if (pointsSet == topLeftSet) side = TOP_LEFT;
		if (pointsSet == (topRightSet | topLeftSet)) side = TOP;

		if (pointsSet == (topRightSet | bottomRightSet | bottomLeftSet | topLeftSet)) printf("Error: penetration of actor %d into actor %d\n", pAnalized->GetId(), pActor2->GetId());

		isCollDetected = collBottomLeft | collBottomRight | collTopLeft | collTopRight;

		return isCollDetected;
	}

	bool IsPointInsideActor(maths::Vec2f point, Actor* pActor)
	{
		float right = pActor->GetPos().x + pActor->GetSize().x / 2;
		float left = pActor->GetPos().x - pActor->GetSize().x / 2;
		float bottom = pActor->GetPos().y - pActor->GetSize().y / 2;
		float top = pActor->GetPos().y + pActor->GetSize().y / 2;

		// left <= x <= right & bottom <= y <= top
		if ((left <= point.x) && (point.x <= right) && (top >= point.y) && (point.y >= bottom))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}