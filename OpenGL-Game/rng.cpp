#include "OpenGL.h"
#include "cube.h"
#include "rng.h"

Rand::Rand(int mseed)
    :seed(mseed)
{

}

Rand::Rand()
    :seed(time(0))
{

}

int Rand::randint()
{
    seed = (214013 * seed + 2531011);
    return (seed >> 16) & 0x7FFF;
}

int Rand::randrange(int mmax)
{
    int n = randint() % mmax;
    return n;
}

int Rand::randint(int mmin, int mmax)
{
    int n = randrange(mmax - mmin) + mmin;
    return n;
}

Rand r;

void initRand()
{
    r = Rand(time(0));
}

int randrange(int mmax)
{
    return r.randrange(mmax);
}

int genRandNum(int mmin, int mmax)
{
    return r.randint(mmin, mmax);
}
