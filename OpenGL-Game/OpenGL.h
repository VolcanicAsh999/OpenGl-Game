#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
//#include <GL/glu.h> // Automatically included with glew
//#include <GL/gl.h> // Automatically included with freeglut
#include <GL/glext.h> // Just has some extra functions that make GL work better
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

#define USE_SOUND // Whether or not to have sound, comment out for IDE compiling as it can't link with this version of OpenAL
