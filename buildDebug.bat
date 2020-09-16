mkdir build
cd build

mkdir Debug
cd Debug

cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-mconsole" -G "MinGW Makefiles" ../..
mingw32-make

cd ../../bin/Debug
Rocket.exe