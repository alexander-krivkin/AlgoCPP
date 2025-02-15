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

	int elem;
	while (true)
	{
		std::cout << "Введите элемент для добавления: ";
		std::cin >> elem;

		if (!elem)
		{
			std::cout << "Работа завершена. Спасибо! ";
			dynamicArray.print();
			break;
		}
		else
		{
			dynamicArray.append(elem);
			dynamicArray.print();
		}
	}

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}