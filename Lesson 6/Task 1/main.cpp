#include <iostream>
#include <string>
#include <Windows.h>


int simpleStringHash(std::string str)
{
	int hash{};

	for (int idx{}; idx < str.length(); idx++)
	{
		hash += static_cast<char>(str[idx]);
	}

	return hash;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string str{};

	while (true)
	{
		std::cout << "Введите строку: ";
		std::cin >> str;
		std::cout << "Наивный хэш строки " << str << " = " <<
			simpleStringHash(str) << std::endl;

		if (str == "exit")
		{
			break;
		}
	}

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}