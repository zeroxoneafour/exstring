// exstring.c
// This file is licensed under the Boost Software License
// Copyright 2021 Vaughan Milliman

#include "exstring.h"

void deleteStr(char* str)
{
	free(str);
	str = NULL;
};
void deleteEx(exString* ex)
{
	free(ex->string);
	free(ex);
	ex = NULL;
};
void clearEx(exString* ex)
{
	free(ex->string);
	ex->size = 0;
	ex->string = NULL;
};
exString* strToEx(const char* str)
{
	exString* ex = malloc(sizeof(exString));
	ex->size = strlen(str);
	ex->string = malloc(ex->size);
	strncpy(ex->string, str, ex->size);
	return ex;
};
char* exToStr(const exString* ex)
{
	char* str = malloc(ex->size + 1);
	strncpy(str, ex->string, ex->size);
	str[ex->size] = '\0';
	return str;
};

exString* excat(exString* dest, const exString* src)
{
	dest->size += src->size;
	realloc(dest->string, dest->size);
	strncpy(dest->string + (dest->size - src->size), src->string, src->size);
	return dest;
};
exString* excpy(exString* dest, const exString* src)
{
	dest->size = src->size;
	dest->string = malloc(dest->size);
	strncpy(dest->string, src->string, dest->size);
	return dest;
};
exString* exchr(const exString* ex, const char c)
{
	int i = 1;
	exString* ret;
	ret->string = NULL;
	ret->size = 0;
	while(i <= ex->size && ret->size == 0 && ret->string == NULL)
	{
		if (*ret->string == c)
		{
			ret->size = ex->size - (i - 1);
			ret->string = malloc(ret->size);
			strncpy(ret->string, ex->string + (i - 1), ret->size);
		}
		else
			++i;
	};
	if (ret->string == NULL || ret->size == 0)
		return NULL;
	else
		return ret;
};
size_t exlen(const exString* ex)
{
	return ex->size;
};
