#pragma once

#include "GameObject.h"

namespace skEngine
{
	class GameObjectManeger
	{
	public:
		~GameObjectManeger();

		template<class T>
		T* NewGO(const char* name = nullptr);

		void DeleteGO(const char* name);

		template<class T>
		T* FindGO(const char* name);

		template<class T>
		void QueryGOs(const char* name, std::function<bool(T* obj)> func);


	private:
		std::vector<GameObject*> m_gameObjectList;

	};
}

