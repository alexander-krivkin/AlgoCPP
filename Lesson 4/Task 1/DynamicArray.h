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

		void fill();
		void print();

	private:
		int* data;
		int physicalSize;
		int logicalSize;
	};
}

#endif