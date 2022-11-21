//Has functions for collision detection between lines
#include "line.h"
#include "vec3.h"

bool intersected(Vec3 A, Vec3 B, Vec3 C, Vec3 D)
{
    Vec3 E = B.sub(A);
    Vec3 F = D.sub(C);
    Vec3 P = Vec3(-E.y, E.x, E.z);
    float h = ((A.sub(C)).dot(P)) / ((F.dot(P)));
    if (h >= 0 && h <= 1)
        return true;
    return false;
}

bool pointOnLine(Vec3 A, Vec3 B, Vec3 pos, Vec3 pad)
{
    Vec3 line1 = Vec3(pos.x - pad.x, pos.y - pad.y, pos.z - pad.z);
    Vec3 line2 = Vec3(pos.x + pad.x, pos.y - pad.y, pos.z - pad.z);
    Vec3 line3 = Vec3(pos.x + pad.x, pos.y - pad.y, pos.z + pad.z);
    Vec3 line4 = Vec3(pos.x - pad.x, pos.y - pad.y, pos.z + pad.z);
    if (intersected(A, B, line1, line2) || intersected(A, B, line2, line3) || intersected(A, B, line3, line4) || intersected(A, B, line4, line1))
    {
        return true;
    }
    return false;
}
