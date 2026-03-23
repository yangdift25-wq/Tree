#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HPDataType;


typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPush(HP* php,HPDataType x);
void HPPop(HP* php);
void AdjustDown(HPDataType* a, int n, int parent);
void AdjustUp(HPDataType* a, int child);
HPDataType HPTop(HP* php);
bool HPEmpty(HP* php);
