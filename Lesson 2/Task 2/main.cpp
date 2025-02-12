#include <iostream>
#include <Windows.h>


int fibonacciCalc(unsigned int n, unsigned int* arr, bool* calculated)
{
	if (n == 0) { arr[n] = 0; calculated[n] = true; return 0; }
	else if (n == 1) { arr[n] = 1; calculated[n] = true; return 1; }
	else if (calculated[n]) return arr[n];

	arr[n] = fibonacciCalc(n - 1, arr, calculated) + fibonacciCalc(n - 2, arr, calculated);
	calculated[n] = true;
	return arr[n];
}


int fibonacci(int n)
{
	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }

	unsigned int* arr{};
	bool* calculated{};
	arr = new unsigned int[n + 1];
	calculated = new bool[n + 1] {false};

	int result = fibonacciCalc(n, arr, calculated);

	delete[] arr;
	delete[] calculated;
	return result;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int n{};

	std::cout << "¬ведите n: ";
	std::cin >> n;

	std::cout << "Fn = " << fibonacci(n) << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}