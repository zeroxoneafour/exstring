// exstring.h
// This file is licensed under the Boost Software License
// Copyright 2021 Vaughan Milliman

#ifndef EXSTRING_EXSTRING_H
#define EXSTRING_EXSTRING_H

#include <string.h>
#include <stdlib.h>

void deleteStr(char* str); // A function to free a string, because it's easier to write this

typedef struct exString_struct {
	char* string;
	size_t size;
} exString;

void deleteEx(exString* ex); // Free a pointer exString
void clearEx(exString* ex); // Clear a non-pointer or pointer exString

#ifdef EXSTRING_USE_STRING

typedef struct exString_struct string; // Easier to call than exString

#endif // EXSTRING_USE_STRING

// C string / Ex String conversions

exString* strToEx(const char* str); // C string to Ex String
char* exToStr(const exString* exStr); // Ex String to C string

// Ex String Operations

exString* excat(exString* dest, const exString* src); // strcat
exString* excpy(exString* dest, const exString* src); // strcpy
exString* exchr(const exString* ex, char c); // strchr
size_t exlen(const exString* ex); // strlen

#endif // EXSTRING_EX_H
