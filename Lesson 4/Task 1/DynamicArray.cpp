#include "DynamicArray.h"


ak::DynamicArray::DynamicArray(int physicalSize, int logicalSize) :
	physicalSize(physicalSize), logicalSize(logicalSize)
{
	data = new int[physicalSize] {};
}

ak::DynamicArray::~DynamicArray()
	
{
	physicalSize = 0;
	logicalSize = -1;
	delete[] data;
}

void ak::DynamicArray::fill()
{
	for (int idx{}; idx < logicalSize; idx++)
	{
		std::cout << "Введите arr[" << idx << "]: ";
		std::cin >> data[idx];
	}
}

void ak::DynamicArray::print()
{
	std::cout << "Динамический массив: ";

	for (int idx{}; idx < logicalSize; idx++)
	{
		std::cout << data[idx] << " ";
	}

	for (int idx{ logicalSize }; idx < physicalSize; idx++)
	{
		std::cout << "_ ";
	}

	std::cout << std::endl;
}