#include "sort.h"
#include "../ais3/Heap.h"
#include <algorithm>


void show(int* array, size_t len) { //Вывод массива чисел
	cout << "Array: ";
	for (size_t index = 0; index < len; index++)
		cout << array[index] << " ";
	cout << endl;
}


void show(char* array, size_t len) { //Вывод массива символов
	cout << "Array: ";
	for (size_t index = 0; index < len; index++)
		cout << array[index] << " ";
	cout << endl;
}


bool is_sorted(int* array, size_t len) {//Проверка на упорядоченность массива чисел
	for (size_t index = 1; index < len; index++)
		if (array[index - 1] > array[index])
			return false;
	return true;
}

bool is_sorted(char* array, size_t len) { //Проверка на упорядоченность массива символов
	for (size_t index = 1; index < len; index++)
		if (array[index - 1] > array[index])
			return false;
	return true;
}


int binary_search(int* array, size_t len, int key) {//Двоичный поиск
	int left = -1, right = len, middle;
	while (right > left + 1) {
		middle = (left + right) / 2;
		if (array[middle] >= key)
			right = middle;
		else
			left = middle;
	}
	if (array[right] == key)
		return right;
	else
		throw out_of_range("Not have element");
}


void quick_sort(int *array, int left, int right) {//Быстрая сортировка
	int l = left;
	int r = right - 1;
	int size = right - left;
	if (size > 1) {
		int pivot = array[rand() % size + l];
		while (l < r) {
			while (array[r] > pivot && r > l)
				r--;
			while (array[l] < pivot && l <= r)
				l++;
			if (l < r) {
				swap(array[l], array[r]);
				l++;
			}
		}
		quick_sort(array, left, l);
		quick_sort(array, r, right);
	}

}


void bubble_sort(int* array, size_t len) {//Сортировка пузырьком
	for (size_t range = len - 1; range > 0; range--)
		for (size_t index = 0; index < range; index++)
			if (array[index] > array[index + 1])
				swap(array[index], array[index + 1]);
}


void heap_sort(int* array, size_t len) {//Сортировка кучей или пирамидальная сортировка 
	Heap *heap = new Heap();
	size_t index;
	for (index = 0; index < len; index++) 
		heap->add(array[index]);

	for (index = len; index > 0; index--) 
		array[index - 1] = heap->remove();

	delete heap;
}


void bogo_sort(int *array, size_t len) {// Глупая сортировка
	int index;
	bool correct = false;
	while (!correct) {
		correct = true;
		
		for (index = 0; index < len; index++)
			swap(array[index], array[(rand() % len)]);
		
		index = len;
		while (--index > 0 && correct)
			if (array[index - 1] > array[index])
				correct = false;
	}
}


void count_sort(char* array, size_t len) { //Сортировка подсчетом
	char * count_array = new char[256];
	size_t index;

	for (index = 0; index < 256; index++)
		count_array[index] = 0;

	for (index = 0; index < len; index++)
		count_array[array[index]]++;
	
	index = 0;
	size_t count_index = 0;

	while (count_index != 256) {
		if (count_array[count_index] != 0) {
			count_array[count_index]--;
			array[index++] = 'a' + count_index;
		}
		else
			count_index++;
	}
	
}