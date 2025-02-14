#include <iostream>
#include <Windows.h>


void printArr(int* arr, int size)
{
	for (int idx{}; idx < size; idx++)
	{
		std::cout << arr[idx] << " ";
	}
}

void swap(int& i1, int& i2)
{
	int tmp{ i2 };
	i2 = i1;
	i1 = tmp;
}

int pivoting(int* arr, int left, int right)
{
	int idxPivot{ left };
	int pivot{ arr[idxPivot] };

	while (true)
	{
		while (arr[left] < pivot) { left++; }
		while (pivot < arr[right]) { right--; }

		if (left >= right) { return left; }

		swap(arr[left], arr[right]);

		if (arr[left] != pivot) { left++; }
		if (arr[right] != pivot) { right--; }
	}
}

void quickSortRecoursive(int* arr, int left, int right)
{
	if (left < right)
	{
		int border = pivoting(arr, left, right);
		quickSortRecoursive(arr, left, border);
		quickSortRecoursive(arr, border + 1, right);
	}
}

void quickSort(int* arr, int size)
{
	quickSortRecoursive(arr, 0, size - 1);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr1[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr2[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 58, 90, 84, 60, 95, 61 };

	std::cout << "Исходный массив arr1: ";
	printArr(arr1, sizeof(arr1) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr2: ";
	printArr(arr2, sizeof(arr2) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr3: ";
	printArr(arr3, sizeof(arr3) / sizeof(int));
	std::cout << std::endl << std::endl;

	quickSort(arr1, sizeof(arr1) / sizeof(int));
	quickSort(arr2, sizeof(arr2) / sizeof(int));
	quickSort(arr3, sizeof(arr3) / sizeof(int));

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