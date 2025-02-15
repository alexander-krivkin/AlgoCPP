#include <iostream>
#include <Windows.h>

#include "DynamicArray.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int physicalSize;
	int logicalSize;

	std::cout << "������� �������c��� ������ �������: ";
	std::cin >> physicalSize;
	std::cout << "������� ���������� ������ �������: ";
	std::cin >> logicalSize;

	if (physicalSize < logicalSize)
	{
		std::cout << "������! ���������� ������ ������� �� ����� ��������� �����������!" << std::endl << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}

	ak::DynamicArray dynamicArray(physicalSize, logicalSize);
	dynamicArray.fill();
	dynamicArray.print();

	std::string choice{};
	while (true)
	{
		std::cout << "������� ������ �������? ";
		std::cin >> choice;

		if (choice == "���")
		{
			std::cout << "������ ���������. �������! ";
			dynamicArray.print();
			break;
		}
		else if (choice == "��")
		{
			if (!dynamicArray.getLogicalSize())
			{
				std::cout << "���������� ������� ������ �������, ��� ��� ������ ������. �� ��������!" << std::endl;
				std::cout << std::endl;
				system("pause");
				return EXIT_SUCCESS;
			}

			dynamicArray.removeHead();
			dynamicArray.print();
		}
	}

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}