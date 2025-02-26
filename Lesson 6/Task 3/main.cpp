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

int findSubstringLightRabinKarp(std::string sourceStr, std::string searchStr)
{
	int sourceStrLength = static_cast<int>(sourceStr.length());
	int searchStrLength = static_cast<int>(searchStr.length());
	int sourceSubstrHash{};
	int searchStrHash = simpleStringHash(searchStr);

	for (int idx{}; idx <= sourceStrLength - searchStrLength; idx++)
	{
		if (!idx)
		{
			sourceSubstrHash = simpleStringHash(sourceStr.substr(0, searchStrLength));
		}
		else
		{
			sourceSubstrHash -= static_cast<char>(sourceStr[idx - 1]);
			sourceSubstrHash += static_cast<char>(sourceStr[idx - 1 + searchStrLength]);
		}

		if (sourceSubstrHash == searchStrHash)
		{
			bool equal{ true };

			for (int idxInternal{}; idxInternal < searchStrLength; idxInternal++)
			{
				if (sourceStr[idx + idxInternal] != searchStr[idxInternal])
				{
					equal = false;
				}
			}

			if (equal) return idx;
		}
	}

	return -1;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string sourceStr{}, searchStr{};
	int idxEqual{};

	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> sourceStr;

	while (true)
	{
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::cin >> searchStr;

		idxEqual = findSubstringLightRabinKarp(sourceStr, searchStr);
		if (idxEqual < 0)
		{
			std::cout << "Подстрока " << searchStr << " не найдена" << std::endl;
		}
		else
		{
			std::cout << "Подстрока " << searchStr << " найдена по индексу " <<
				idxEqual << std::endl;
		}

		if (searchStr == "exit")
		{
			break;
		}
	}

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}