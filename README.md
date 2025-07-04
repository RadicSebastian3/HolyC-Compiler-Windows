# HolyC Compiler for Windows

Native Windows implementation of the HolyC compiler without requiring WSL.

## Features

- Native Windows compilation
- Supports most HolyC language features
- Visual Studio solution for easy development
- Windows installer package

## Installation

1. Run the installer from `installer\HolyC-Compiler-Setup.exe`
2. Follow the installation wizard
3. The compiler will be added to your system PATH

## Building from Source

### Requirements
- Visual Studio 2022 with C++ tools
- CMake 3.15+

### Build Steps
```cmd
:: Configure and build
build.bat

:: Run tests
cd test
build_test.bat
```

## Usage
```cmd
hcc source.hc -o output.exe
```

## Documentation

See [HolyC Language Reference](https://holyc-lang.com/docs)