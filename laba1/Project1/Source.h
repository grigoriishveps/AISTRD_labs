#pragma once

void fill_array(int ** &array, const size_t len, int value);

void show(const int** const array, const size_t len);
int** onelinearray_to_dinamyc_array(const int* const array, size_t len);
bool equal(int** array1, const size_t array1_len, int** array2, const size_t array2_len);
void del_array(int ** &array, size_t l);