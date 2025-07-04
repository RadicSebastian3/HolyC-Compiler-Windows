@echo off

REM Test build script for HolyC compiler on Windows

set HCC_PATH=..\build\Release\hcc.exe
set TEST_FILE=test.hc
set OUTPUT=test.exe

if not exist "%HCC_PATH%" (
    echo HolyC compiler not found at %HCC_PATH%
    echo Please build the compiler first
    pause
    exit /b 1
)

"%HCC_PATH%" "%TEST_FILE%" -o "%OUTPUT%"

if %errorlevel% neq 0 (
    echo Compilation failed
    pause
    exit /b %errorlevel%
)

echo.
echo Test compiled successfully!
echo Run %OUTPUT% to execute the test

pause