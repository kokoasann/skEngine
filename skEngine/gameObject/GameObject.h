#pragma once

namespace skEngine
{
	class GameObject
	{
	public:
		~GameObject();
		GameObject(const char* name);
		virtual bool Start() { return true; }
		virtual void Update() {}
		const char* GetName();
	private:
		const char* m_name = nullptr;

	};
}