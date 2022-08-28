#include "Source.h"
#include <iostream>
#include <iomanip>

using namespace std;

void fill_array(int ** &array, const size_t len, int value) {
	size_t i, j, q = 0, half= len / 2, even = len % 2;

	array = new int*[len];
	for (i = 0; i < len; i++)
		array[i] = new int[len];

	//Первая половина часов
	for (i = 0; i < half; i++) {
		for (j = 0; j < i + 1; j++) 
			array[j][i] = value++;
	
		for ( j = i + 1; j < len - i - 1; j++) 
			array[j][i] = 0;
		
		for (j = len - i - 1; j < len; j++)
			array[j][i] = value++;
			
	}

	//Середина часов
	if (even) {
	//	for (int i = half; i == half; i++)
			for ( j = 0; j < len; j++){
				array[j][half] = value++;
				
			}
	}
	
	//Вторая половина часов
	for ( i = half + even; i < len; i++) {
		for ( j = 0; j < len - i; j++)
			array[j][i] = value++;
			
		for ( j = len - i ; j < i; j++)
			array[j][i] = 0;
		
		for ( j = i ; j < len; j++) 
			array[j][i] = value++;
			
		
	}
}


bool equal( int ** array1, const size_t array1_len, int ** array2, const size_t array2_len) { 
	if (array1_len != array2_len)
		return false;
	for(size_t i = 0; i < array1_len; i++)
		for (size_t j = 0; j < array1_len; j++) 
			if (array1[i][j] != array2[i][j])
				return false;	
	return true;
}

void del_array(int ** &array, size_t len) {
	for (size_t i = 0; i < len; i++)
		delete[] array[i];
	delete[] array;
}

void show( const int** const array, const size_t len) {
	cout << "array = " << endl;
	for (size_t i = 0; i < len; i++) {
		for (size_t j = 0; j < len; j++) {
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
}

int** onelinearray_to_dinamyc_array(const int const *array, const size_t len) {
	int**new_array = new int*[len];
	for (size_t i = 0; i < len; i++) {
		new_array[i] = new int[len];
		for (size_t j = 0; j < len; j++)
			new_array[i][j] = array[i * len + j];
	}
	return new_array;
}
