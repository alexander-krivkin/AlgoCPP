#include <iostream>
#include <Windows.h>


int calc(int arr[], int size, int start)
{
	int left{}, right{ size - 1 }, middle{};

	while (left <= right)
	{
		middle = (left + right) / 2;
		if (start < arr[middle])
			right = middle - 1;
		else if (start >= arr[middle])
			left = middle + 1;
	}

	return size - right - 1;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[]{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int start{};

	std::cout << "Введите точку отсчёта: ";
	std::cin >> start;

	std::cout << "Количество элементов в массиве больших, чем " << start << ": ";
	std::cout << calc(arr, 9, start) << std::endl;

	return EXIT_SUCCESS;
}