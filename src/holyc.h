#ifndef HOLYC_H
#define HOLYC_H

// Windows-specific type definitions
typedef signed char I8;
typedef unsigned char U8;
typedef short I16;
typedef unsigned short U16;
typedef int I32;
typedef unsigned int U32;
typedef long long I64;
typedef unsigned long long U64;

typedef float F32;
typedef double F64;

typedef int Bool;
#define TRUE 1
#define FALSE 0

// Memory management
void* MAlloc(size_t size);
void Free(void* ptr);
void MemCpy(void* dest, const void* src, size_t n);

// I/O functions
void Print(const char* str);

// Windows initialization
void InitHolyCLib();

#endif // HOLYC_H