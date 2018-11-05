#include "../stdafx.h"
#include "Vector.h"

namespace skEngine
{
	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3 Vector3::One() const
	{
		Vector3 v = { 1,1,1 };
		return v;
	}
	Vector3 Vector3::Zero() const
	{
		Vector3 v = { 0,0,0 };
		return v;
	}
	Vector3 Vector3::operator+(Vector3 v1)
	{
		Vector3 rv = Zero();
		rv.x = v1.x + x;
		rv.y = v1.y + y;
		rv.z = v1.z + z;
		return rv;
	}
	Vector3 Vector3::operator-(Vector3 v1)
	{
		Vector3 rv = Zero();
		rv.x = x - v1.x;
		rv.y = y - v1.y;
		rv.z = z - v1.z;
		return rv;
	}


	Vector4::Vector4()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}
	Vector4::Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	Vector4 Vector4::Zero()
	{
		Vector4 v = { 0,0,0,0 };
		return v;
	}
	Vector4 Vector4::One()
	{
		Vector4 v = { 1,1,1,1 };
		return v;
	}

	
	Quaternion::Quaternion()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 1;
	}
	Quaternion::Quaternion(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	Quaternion Quaternion::Identity()
	{
		Quaternion q = { 0,0,0,1 };
		return q;
	}
}