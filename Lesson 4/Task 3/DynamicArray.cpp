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

void ak::DynamicArray::append(int elem)
{
	if (physicalSize > logicalSize)
	{
		data[logicalSize] = elem;
		logicalSize++;
	}
	else
	{
		int tmpPhysicalSize = 2 * physicalSize;
		int* tmpData = new int[tmpPhysicalSize] {};

		for (int idx{}; idx < logicalSize; idx++)
		{
			tmpData[idx] = data[idx];
		}
		if (tmpPhysicalSize > logicalSize)
		{
			tmpData[logicalSize] = elem;
		}

		physicalSize = tmpPhysicalSize;
		logicalSize++;
		delete[] data;
		data = new int[physicalSize] {};

		for (int idx{}; idx < logicalSize; idx++)
		{
			data[idx] = tmpData[idx];
		}

		delete[] tmpData;
	}
}

void ak::DynamicArray::removeHead()
{
	if ((logicalSize - 1) > (physicalSize / 3))
	{
		for (int idx{}; idx < logicalSize - 1; idx++)
		{
			data[idx] = data[idx + 1];
		}
		logicalSize--;
	}
	else
	{
		int tmpPhysicalSize = physicalSize / 3;
		int* tmpData = new int[tmpPhysicalSize] {};

		for (int idx{}; idx < (logicalSize - 1); idx++)
		{
			tmpData[idx] = data[idx + 1];
		}

		physicalSize = tmpPhysicalSize;
		logicalSize--;
		delete[] data;
		data = new int[physicalSize] {};

		for (int idx{}; idx < logicalSize; idx++)
		{
			data[idx] = tmpData[idx];
		}

		delete[] tmpData;
	}
}