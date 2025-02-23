#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>


void printArr(int* arr, int size)
{
	for (int idx{}; idx < size; idx++)
	{
		std::cout << arr[idx] << " ";
	}
}

int getParentPyramidIndex(int index)
{
	return ((index - 1) / 2);
}

int getLeftChildPyramidIndex(int index)
{
	return (2 * index + 1);
}

int getRightChildPyramidIndex(int index)
{
	return (2 * index + 2);
}

void printPyramidNode(int* arr, int size, int index)
{
	int level = static_cast<int>(std::log2(static_cast<double>(index + 1)));

	if (!index)
	{
		std::cout << level << " root " << arr[index++] << std::endl;
	}
	else if (!(index % 2))
	{
		std::cout << level << " right (" <<
			arr[getParentPyramidIndex(index)] << ") " <<
			arr[index] << std::endl;
	}
	else
	{
		std::cout << level << " left (" <<
			arr[getParentPyramidIndex(index)] << ") " <<
			arr[index] << std::endl;
	}
}

void printPyramid(int* arr, int size)
{
	for (int idx{}; idx < size; idx++)
	{
		printPyramidNode(arr, size, idx);
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr1[]{ 1, 3, 6, 5, 9, 8 };
	int arr2[]{ 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr3[]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	std::cout << "Исходный массив arr1: ";
	printArr(arr1, sizeof(arr1) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr2: ";
	printArr(arr2, sizeof(arr2) / sizeof(int));
	std::cout << std::endl;
	std::cout << "Исходный массив arr3: ";
	printArr(arr3, sizeof(arr3) / sizeof(int));
	std::cout << std::endl << std::endl;

	printPyramid(arr1, sizeof(arr1) / sizeof(int));
	std::cout << std::endl;
	printPyramid(arr2, sizeof(arr2) / sizeof(int));
	std::cout << std::endl;
	printPyramid(arr3, sizeof(arr3) / sizeof(int));
	std::cout << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}