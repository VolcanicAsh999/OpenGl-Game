#pragma once
#include <math.h>

class Vec3 {
public:
    Vec3(float mx, float my, float mz);
    float x, y, z;
    Vec3 sub(Vec3 other);
    Vec3 add(Vec3 other);
    Vec3 div(Vec3 other);
    float dot(Vec3 other);
};
