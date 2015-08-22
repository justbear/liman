#include "Rectangle.h"

namespace liman {

	const char* Rectangle::g_Name = "CollidableComponent";

	Rectangle::Rectangle(Actor* pOwner) : Collidable(pOwner)
	{

	}

	bool Rectangle::Init(tinyxml2::XMLElement* pComponentNode)
	{
		return true;
	}

	tinyxml2::XMLElement* Rectangle::GenerateXML(tinyxml2::XMLDocument* outDoc)
	{
		tinyxml2::XMLElement* pRendNode = outDoc->NewElement(Rectangle::g_Name);
		
		return pRendNode;
	}

	void Rectangle::SetSize(float x, float y)
	{
		m_size.x = x;
		m_size.y = y;
	}
	void Rectangle::SetSize(maths::Vec2f vec2)
	{
		m_size = vec2;
	}
	void Rectangle::OffSetSize(float x, float y)
	{
		m_size.x += x;
		m_size.y += y;
	}
	void Rectangle::OffSetSize(maths::Vec2f vec2)
	{
		m_size.x += vec2.x;
		m_size.y += vec2.y;
	}
	maths::Vec2f Rectangle::GetSize()
	{
		return m_size;
	}
	float Rectangle::GetSizeX()
	{
		return m_size.x;
	}
	float Rectangle::GetSizeY()
	{
		return m_size.y;
	}

}