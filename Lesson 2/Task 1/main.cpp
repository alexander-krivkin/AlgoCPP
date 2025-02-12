#include <iostream>
#include <Windows.h>


int fibonacci(unsigned int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
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