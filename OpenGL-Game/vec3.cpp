#include "vec3.h"

Vec3::Vec3(float mx, float my, float mz)
    :x(mx), y(my), z(mz)
{

}

Vec3 Vec3::sub(Vec3 other)
{
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::add(Vec3 other)
{
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::div(Vec3 other)
{
    return Vec3(x / other.x, y / other.y, z / other.z);
}

float Vec3::dot(Vec3 other)
{
    return (x*other.x + y*other.y + z*other.z);
}
