#ifndef AK_DYNAMIC_ARRAY_H
#define AK_DYNAMIC_ARRAY_H

#include <iostream>


namespace ak
{
	class DynamicArray final
	{
	public:
		DynamicArray(int physicalSize, int logicalSize);
		~DynamicArray();

		int getPhysicalSize() const { return physicalSize; }
		int getLogicalSize() const { return logicalSize; }

		void fill();
		void print();
		void append(int elem);
		void removeHead();

	private:
		int* data;
		int physicalSize;
		int logicalSize;
	};
}

#endif