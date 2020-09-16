mkdir build
cd build

mkdir Release
cd Release

cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-mwindows" -G "MinGW Makefiles" ../..
mingw32-make
pause