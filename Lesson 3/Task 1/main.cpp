#include <iostream>
#include <Windows.h>


void printArr(int* arr, int size)
{
	for (int idx{}; idx < size; idx++)
	{
		std::cout << arr[idx] << " ";
	}
}


void merge(int* arr, int* destArr, int left, int mid, int right)
{
	int sizeLeft{ mid + 1 - left };
	int sizeRight{ right - mid };
	int idxLeft{}, idxRight{}, idxResult{};

	while ((idxLeft < sizeLeft) && (idxRight < sizeRight))
	{
		if (arr[left + idxLeft] <= arr[mid + 1 + idxRight])
		{
			destArr[idxResult] = arr[left + idxLeft];
			idxLeft++;
		}
		else
		{
			destArr[idxResult] = arr[mid + 1 + idxRight];
			idxRight++;
		}
		idxResult++;
	}
	while (idxLeft < sizeLeft)
	{
		destArr[idxResult] = arr[left + idxLeft];
		idxLeft++;
		idxResult++;

	}
	while (idxRight < sizeRight)
	{
		destArr[idxResult] = arr[mid + 1 + idxRight];
		idxRight++;
		idxResult++;
	}

	for (int idx{}; idx < right + 1 - left; idx++)
	{
		arr[left + idx] = destArr[idx];
	}
}

void mergeSortRecoursive(int* arr, int* destArr, int left, int right)
{
	if (left < right)
	{
		int mid{ (left + right) / 2 };

		mergeSortRecoursive(arr, destArr, left, mid);
		mergeSortRecoursive(arr, destArr, mid + 1, right);
		merge(arr, destArr, left, mid, right);
	}
}

void mergeSort(int* arr, int size)
{
	int* destArr = new int[size];
	mergeSortRecoursive(arr, destArr, 0, size - 1);
	delete[] destArr;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr1[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr2[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	std::cout << "Исходный массив arr1: ";
	printArr(arr1, sizeof(arr1) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr2: ";
	printArr(arr2, sizeof(arr2) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr3: ";
	printArr(arr3, sizeof(arr3) / sizeof(int));
	std::cout << std::endl << std::endl;

	mergeSort(arr1, sizeof(arr1) / sizeof(int));
	mergeSort(arr2, sizeof(arr2) / sizeof(int));
	mergeSort(arr3, sizeof(arr3) / sizeof(int));

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