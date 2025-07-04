#include <windows.h>
#include <stdio.h>

// Windows implementation of basic HolyC functions
void Print(const char* str) {
    printf("%s", str);
}

// Main compiler entry point
int main(int argc, char** argv) {
    if (argc < 2) {
        Print("Usage: hcc <file.hc>\n");
        return 1;
    }

    // TODO: Implement Windows file handling
    // TODO: Implement lexer/parser for Windows
    // TODO: Implement code generation for Windows

    Print("HolyC compiler for Windows - Work in progress\n");
    return 0;
}