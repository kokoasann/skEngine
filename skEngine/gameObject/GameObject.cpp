#include "../stdafx.h"
#include "GameObject.h"

namespace skEngine
{
	GameObject::~GameObject()
	{
		delete[] m_name;
	}

	GameObject::GameObject(const char * name)
	{
		this->m_name = name;
	}

	const char* GameObject::GetName()
	{
		return m_name;
	}
}