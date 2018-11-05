#pragma once

#include "Vector.h"

namespace skEngine
{
	class Matrix
	{
	public:
		union
		{
			DirectX::XMFLOAT4X4 mat;
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			Vector4 v[4];
			float m[4][4];
		};
		Matrix();
		
	};
}