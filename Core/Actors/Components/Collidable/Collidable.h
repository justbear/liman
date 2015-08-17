#pragma once

#include "../../Actor.h"
#include "../ActorComponent.h"
#include "../../../Collisions/CollisionSide.h"

#include "../../../Maths/Maths.h"

namespace liman {

	class Actor;

	class Collidable : public ActorComponent
	{
	public:
		Collidable(Actor*);
		~Collidable();

		// TIP: reaction to collision
		maths::Vec2f Collide(Actor* pPairedActor, CollisionSide side);
	private:
	
	protected:
		// TIP: ingame changes to collision effect (events) 
		void OnCollision();

	};
}