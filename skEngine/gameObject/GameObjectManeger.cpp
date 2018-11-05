#include "../stdafx.h"
#include "GameObjectManeger.h"
//#include "GameObject.h"

namespace skEngine
{
	GameObjectManeger::~GameObjectManeger()
	{
		for (auto obj : m_gameObjectList)
		{
			delete obj;
		}
	}

	void GameObjectManeger::DeleteGO(const char * name)
	{
		for (GameObject* obj : m_gameObjectList)
		{
			if (strcmp(obj->GetName(), name) == 0)
			{
				std::vector<GameObject*>::iterator it = std::find(m_gameObjectList.begin(), m_gameObjectList.end(), obj);
				m_gameObjectList.erase(it);
				delete obj;
			}
		}
	}

	template<class T>
	inline T * GameObjectManeger::NewGO(const char * name)
	{
		T* obj = new T(name);
		m_gameObjectList.push_back(obj);
		return nullptr;
	}

	template<class T>
	inline T * GameObjectManeger::FindGO(const char * name)
	{
		for (auto obj : m_gameObjectList)
		{
			if (strcmp(obj->GetName(), name) == 0)
			{
				T* t = dynamic_cast<T*>(obj);
				return t;
			}
		}
		return nullptr;
	}

	template<class T>
	inline void GameObjectManeger::QueryGOs(const char * name, std::function<bool(T*obj)> func)
	{
		for (auto obj : m_gameObjectList)
		{
			if (strcmp(obj->GetName(), name) == 0)
			{
				T* t = dynamic_cast<T*>(obj);
				if (!func(t))
				{
					return;
				}
			}
		}
	}
}