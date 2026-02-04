class bVector2 {
	float x, y;
};

#ifdef NYA_MATH_H
class bVector3 : public NyaVec3 {
	float pad;
};
typedef NyaVec4 bVector4;
typedef NyaMat4x4 bMatrix4;
#else
class bVector3 {
	float x, y, z;
	float pad;
};

class bVector4 {
	float x, y, z, w;
};

class bMatrix4 {
	bVector4 x;
	bVector4 y;
	bVector4 z;
	bVector4 p;
};
#endif