@echo off

REM Windows build script for HolyC compiler

set BUILD_TYPE=Release
set GENERATOR="Visual Studio 17 2022"

if not exist build mkdir build

cd build

cmake -G %GENERATOR% -A x64 -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ..
cmake --build . --config %BUILD_TYPE%

cd ..

echo.
echo Build completed successfully!
echo Executable is in: build\%BUILD_TYPE%\

pause