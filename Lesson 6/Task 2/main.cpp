#include <iostream>
#include <string>
#include <Windows.h>


int realStringHash(std::string str, int p, int n)
{
	long long hash{};

	for (int idx{}; idx < str.length(); idx++)
	{
		hash += pow(p, idx) * static_cast<char>(str[idx]);
	}

	return static_cast<int>(hash % n);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string str{};
	int p{}, n{};

	std::cout << "Введите p: ";
	std::cin >> p;
	std::cout << "Введите n: ";
	std::cin >> n;

	while (true)
	{
		std::cout << "Введите строку: ";
		std::cin >> str;
		std::cout << "Хэш строки " << str << " = " <<
			realStringHash(str, p, n) << std::endl;

		if (str == "exit")
		{
			break;
		}
	}

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}