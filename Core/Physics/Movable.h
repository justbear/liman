#pragma once
// Movable.h - movable component class

#include "../Actors/Actor.h"
#include "../Actors/ActorComponent.h"

#include "../Maths/Maths.h"

#include <tinyxml2/tinyxml2.h>

namespace liman {

	class Movable : public ActorComponent
	{
		friend class Actor;

	public:
		static const char* g_Name;
		virtual const char* GetName() const override { return g_Name; }
		virtual ComponentId GetId(void) const override { return GetIdFromName(GetName()); }

		static float g_gravity;

	public:
		Movable(Actor* pOwner);
		~Movable();

		virtual bool Init(tinyxml2::XMLElement* pComponentNode) override;
		void OnUpdate(float deltaTime);

		virtual tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) override;

		// TODO: add func below realization
		void Move(maths::Vec2f offset) {}
		void MoveX(float offset);
		void MoveY(float offset);

		float GetVelocityX() { return m_vel.x; }
		float GetVelocityY() { return m_vel.y; }

		void SetVelocity(float x, float y) { m_vel.x = x; m_vel.y = y; }
		void SetVelocityX(float x) { m_vel.x = x; }
		void SetVelocityY(float y) { m_vel.y = y; }

		float GetAccelX() { return m_accel.x; }
		float GetAccelY() { return m_accel.y; }

		void SetAccel(float x, float y) { m_accel.x = x; m_accel.y = y; }
		void SetAccelX(float x) { m_accel.x = x; }
		void SetAccelY(float y) { m_accel.y = y; }

		void SetStatic(bool isStatic) { m_isStatic = isStatic; }
		bool IsStatic() { return m_isStatic; }

		void SetFalling(bool isFalling) { m_isFalling = isFalling; }
		bool IsFalling(void) { return m_isFalling; }

	private:
		// TIP: moves (true)
		bool m_isStatic;
		// TIP: affected by the Earth gravity
		bool m_isFalling;

		maths::Vec2f m_vel;
		maths::Vec2f m_accel;

	};

}