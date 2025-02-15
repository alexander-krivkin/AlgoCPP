#include <iostream>
#include <Windows.h>

#include "DynamicArray.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int physicalSize;
	int logicalSize;

	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> physicalSize;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logicalSize;

	if (physicalSize < logicalSize)
	{
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}

	ak::DynamicArray dynamicArray(physicalSize, logicalSize);
	dynamicArray.fill();
	dynamicArray.print();

	std::string choice{};
	while (true)
	{
		std::cout << "Удалить первый элемент? ";
		std::cin >> choice;

		if (choice == "нет")
		{
			std::cout << "Работа завершена. Спасибо! ";
			dynamicArray.print();
			break;
		}
		else if (choice == "да")
		{
			if (!dynamicArray.getLogicalSize())
			{
				std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
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