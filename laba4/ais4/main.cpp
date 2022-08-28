#include "sort.h"
#include <time.h>
#include <windows.h>

int main() {
	SetConsoleOutputCP(65001);
	size_t len = 1;
	float startTime;
	srand(time(nullptr));
	cin >> len;
	while (len) {


		int*array = new int[len];
		for (int index = 0; index < len; index++)
			//cin >> array[index];
			array[index] = rand() % 10000;
		/*
		char *array = new char[len];
		for (int index = 0; index < len; index++)
			cin >> array[index];*/

			//show(array, len);

		startTime = clock();
		quick_sort(array, 0, len);
		//bubble_sort(array, len);
		//heap_sort(array, len);
		//bogoSort(array, len);
		//count_sort(array, len);

		cout << "Время работы алгоритма: " << ((double) clock() - startTime) / CLOCKS_PER_SEC << endl;

		//show(array, len);

		delete[] array;
		cin >> len;
	}
	system("pause");
	return 0;
}