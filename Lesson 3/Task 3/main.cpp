#include <iostream>
#include <Windows.h>


void printArr(int* arr, int size)
{
	for (int idx{}; idx < size; idx++)
	{
		std::cout << arr[idx] << " ";
	}
}


void countSort(int* arr, int size, int min, int max)
{
	int* counters = new int[max + 1 - min] {};
	int* sortedArr = new int[size] {};

	for (int idx{}; idx < size; idx++)
	{
		counters[arr[idx] - min]++;
	}

	int idxSorted{};
	for (int idx{}; idx < max + 1 - min; idx++)
	{
		for (int idxCounter{}; idxCounter < counters[idx]; idxCounter++)
		{
			if (idxSorted < size)
			{
				sortedArr[idxSorted] = min + idx;
				idxSorted++;
			}
			else break;
		}
	}

	for (int idx{}; idx < size; idx++)
	{
		arr[idx] = sortedArr[idx];
	}

	delete[] counters;
	delete[] sortedArr;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr1[]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11,
		20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
	int arr2[]{ 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16,
		17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
	int arr3[]{ 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20,
		12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

	std::cout << "Исходный массив arr1: ";
	printArr(arr1, sizeof(arr1) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr2: ";
	printArr(arr2, sizeof(arr2) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr3: ";
	printArr(arr3, sizeof(arr3) / sizeof(int));
	std::cout << std::endl << std::endl;

	countSort(arr1, sizeof(arr1) / sizeof(int), 10, 24);
	countSort(arr2, sizeof(arr2) / sizeof(int), 10, 24);
	countSort(arr3, sizeof(arr3) / sizeof(int), 10, 24);

	std::cout << "Отсортированный массив arr1: ";
	printArr(arr1, sizeof(arr1) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Отсортированный массив arr2: ";
	printArr(arr2, sizeof(arr2) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Отсортированный массив arr3: ";
	printArr(arr3, sizeof(arr3) / sizeof(int));
	std::cout << std::endl << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}