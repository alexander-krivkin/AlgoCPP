#include <iostream>
#include <Windows.h>

#include "DynamicArray.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int physicalSize;
	int logicalSize;

	std::cout << "¬ведите фактичеcкий размер массива: ";
	std::cin >> physicalSize;
	std::cout << "¬ведите логический размер массива: ";
	std::cin >> logicalSize;

	if (physicalSize < logicalSize)
	{
		std::cout << "ќшибка! Ћогический размер массива не может превышать фактический!" << std::endl << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}

	ak::DynamicArray dynamicArray(physicalSize, logicalSize);
	dynamicArray.fill();
	dynamicArray.print();

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}