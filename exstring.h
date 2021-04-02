// exstring.h
/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/
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
exString* exchr(const exString* ex, const char c); // strchr
exString* exstr(const exString* needle, const exString* haystack); // strstr
size_t exlen(const exString* ex); // strlen

#endif // EXSTRING_EX_H
