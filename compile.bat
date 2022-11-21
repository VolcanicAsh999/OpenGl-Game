@echo off
cd %USERPROFILE%\Documents\OpenGL-Game
echo Compiling...
g++ color.cpp cube.cpp keybinds.cpp line.cpp player.cpp playsound.cpp render.cpp rng.cpp room.cpp sphere.cpp triangle.cpp vec3.cpp main.cpp -o bin\Debug\main -lopengl32 -lglew32 -lglu32 -lfreeglut -lopenal32 -std=gnu++17
::if not "%~1"=="-all" g++ color.cpp cube.cpp keybinds.cpp player.cpp playsound.cpp render.cpp rng.cpp room.cpp sphere.cpp main.cpp -o bin\Debug\main -lopengl32 -lglew32 -lglu32 -lfreeglut -lopenal32 -std=gnu++17
echo Done.
cd %USERPROFILE%\Documents
::only compile triangle, vec3 and line if the `-all` option is present
