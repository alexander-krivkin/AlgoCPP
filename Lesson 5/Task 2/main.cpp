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
	if (!index) return -1;
	else return ((index - 1) / 2);
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

	int arr[]{ 94, 67, 18, 44, 55, 12, 6, 42 };
	int size = sizeof(arr) / sizeof(int);

	std::cout << "Исходный массив arr2: ";
	printArr(arr, size);
	std::cout << std::endl;

	printPyramid(arr, size);
	std::cout << std::endl;

	int currentIdx{}, movetoIdx{};
	std::string choise{};

	while (true)
	{
		std::cout << "Введите команду: ";
		std::cin >> choise;

		if (choise == "exit")
		{
			break;
		}
		else if (choise == "up")
		{
			movetoIdx = getParentPyramidIndex(currentIdx);
			if (movetoIdx < 0)
			{
				std::cout << "Ошибка! Отсутствует родитель" << std::endl;
			}
			else
			{
				std::cout << "Ok" << std::endl;
				currentIdx = movetoIdx;
			}
		}
		else if (choise == "left")
		{
			movetoIdx = getLeftChildPyramidIndex(currentIdx);
			if (movetoIdx >= size)
			{
				std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
			}
			else
			{
				std::cout << "Ok" << std::endl;
				currentIdx = movetoIdx;
			}
		}
		else if (choise == "right")
		{
			movetoIdx = getRightChildPyramidIndex(currentIdx);
			if (movetoIdx >= size)
			{
				std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
			}
			else
			{
				std::cout << "Ok" << std::endl;
				currentIdx = movetoIdx;
			}
		}

		std::cout << "Вы находитесь здесь: ";
		printPyramidNode(arr, sizeof(arr) / sizeof(int), currentIdx);
		std::cout << std::endl;

	}


	system("pause");
	return EXIT_SUCCESS;
}