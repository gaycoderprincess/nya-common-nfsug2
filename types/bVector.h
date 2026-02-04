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
};

class bVector4 {
	float x, y, z, w;
};

class bMatrix4 {
	bVector3 x;
	float xw;
	bVector3 y;
	float yw;
	bVector3 z;
	float zw;
	bVector3 p;
	float pw;
};
#endif