#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


class OrientedGraph final
{
public:
	OrientedGraph(int v) : v(v)
	{
		matrix = new int*[v];

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			matrix[idxVertex] = new int[v];
		}
	}
	~OrientedGraph()
	{
		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			delete[] matrix[idxVertex];
		}

		delete[] matrix;
	}

	void loadFromFile(std::ifstream& file)
	{
		for (int idxRow{}; idxRow < v; idxRow++)
		{
			for (int idxCol{}; idxCol < v; idxCol++)
			{
				file >> matrix[idxRow][idxCol];
			}

			matrix[idxRow][idxRow] = 0;
		}
	}

	void printMatrix()
	{
		std::cout << v << std::endl;

		for (int idxRow{}; idxRow < v; idxRow++)
		{
			for (int idxCol{}; idxCol < v; idxCol++)
			{
				std::cout << matrix[idxRow][idxCol] << " ";
			}

			std::cout << std::endl;
		}
	}

	void print()
	{
		bool hasArc{ false };
		std::cout << "Текстовый вид орграфа:" << std::endl;

		for (int idxRow{}; idxRow < v; idxRow++)
		{
			hasArc = false;
			std::cout << (idxRow + 1) << ": ";

			for (int idxCol{}; idxCol < v; idxCol++)
			{
				if (matrix[idxRow][idxCol])
				{
					hasArc = true;
					std::cout << (idxCol + 1) << " ";
				}
			}

			if (!hasArc) 
			{
				std::cout << "нет";
			}

			std::cout << std::endl;
		}
	}


private:
	int v;
	int** matrix;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int v{};
	std::ifstream fileIn("input.txt");

	fileIn >> v;
	OrientedGraph orientedGraph(v);
	orientedGraph.loadFromFile(fileIn);
	orientedGraph.printMatrix();
	std::cout << std::endl;
	orientedGraph.print();
	std::cout << std::endl;

	std::cout << std::endl << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}