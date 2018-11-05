#pragma once

namespace skEngine
{
	class Vector3
	{
	public:
		union
		{
			DirectX::XMFLOAT3 vec;
			struct { float x, y, z; };
			float v[3];

		};
		Vector3();
		Vector3(float x, float y, float z);

		Vector3 One() const;
		Vector3 Zero() const;

		Vector3 operator+(Vector3 v1);
		Vector3 operator-(Vector3 v1);
		
	};

	class Vector4
	{
	public:
		union
		{
			DirectX::XMFLOAT4 vec;
			struct { float x, y, z, w; };
			float v[4];
		};
		Vector4();
		Vector4(float x, float y, float z, float w);

		Vector4 Zero();
		Vector4 One();

	};

	class Quaternion :public Vector4
	{
	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);

		Quaternion Identity();

	};
}