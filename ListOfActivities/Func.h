
#pragma once

#include "FuncWithEntering.h";

bool Empty();
int Getlenght();
void DelayDisplaying();
Act* ElementAt(size_t index);

void Add(Act* p);
void AddRange(const Act sourceArr[], size_t size);

void Show(char buff1[], char buff2[], char buff[]);

typedef bool (Select)(Act* pObj);
void Filter(Select select);

typedef bool (*Compare) (Act* ptr1, Act* ptr);
void Sort(Compare compare);

void Clear();
void DeleteAt(size_t index);