#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// Windows implementation of HolyC memory functions
void* MAlloc(size_t size) {
    return HeapAlloc(GetProcessHeap(), 0, size);
}

void Free(void* ptr) {
    if (ptr) HeapFree(GetProcessHeap(), 0, ptr);
}

// Windows implementation of HolyC string functions
void MemCpy(void* dest, const void* src, size_t n) {
    memcpy(dest, src, n);
}

// Windows implementation of HolyC I/O functions
void Print(const char* str) {
    printf("%s", str);
}

// Windows-specific initialization
void InitHolyCLib() {
    // Initialize any Windows-specific resources
}