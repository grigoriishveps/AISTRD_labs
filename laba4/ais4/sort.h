#pragma once
#include <iostream>

using namespace std;


void show(int* array, size_t len);
void show(char* array, size_t len);
bool is_sorted(int* array, size_t len);
bool is_sorted(char* array, size_t len);


int binary_search(int* array, size_t len, int value);

void quick_sort(int *array, int left, int right);

void bubble_sort(int* array, size_t len);

void heap_sort(int* array, size_t len);

void bogo_sort(int *array, size_t len);

void count_sort(char* array, size_t len);
