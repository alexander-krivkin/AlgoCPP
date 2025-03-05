#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


class OrientedGraph final
{
public:
	OrientedGraph(int v) : v(v), visited(nullptr), sortedTopologicalReverse(nullptr), idxTopological(0)
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

	void printSortedTopological()
	{
		visited = new int[v] {};
		sortedTopologicalReverse = new int[v] {};

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			if (!visited[idxVertex])
			{
				DFS(idxVertex, idxVertex);
			}
		}

		for (int idxVertex{ v - 1 }; idxVertex >= 0; idxVertex--)
		{
			std::cout << (sortedTopologicalReverse[idxVertex] + 1) << " ";
		}

		delete[] visited;
		delete[] sortedTopologicalReverse;
	}


private:
	int v;
	int** matrix;
	int* visited;
	int* sortedTopologicalReverse;
	int idxTopological;


	void DFS(int vertex, int from)
	{
		bool hasArc = false;

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			if ((matrix[vertex][idxVertex]) && (!visited[idxVertex]))
			{
				hasArc = true;
				DFS(idxVertex, vertex);
			}
		}

		if ((!hasArc))
		{
			visited[vertex] = 1;
			sortedTopologicalReverse[idxTopological++] = vertex;
		}

		if (!visited[vertex])
		{
			DFS(from, from);
		}
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int v1{}, v2{};
	std::ifstream fileIn1("input1.txt");
	std::ifstream fileIn2("input2.txt");

	fileIn1 >> v1;
	OrientedGraph orientedGraph1(v1);
	orientedGraph1.loadFromFile(fileIn1);
	orientedGraph1.printMatrix();
	std::cout << std::endl;

	std::cout << "Топологический порядок вершин: ";
	orientedGraph1.printSortedTopological();
	std::cout << std::endl << std::endl;

	fileIn2 >> v2;
	OrientedGraph orientedGraph2(v2);
	orientedGraph2.loadFromFile(fileIn2);
	orientedGraph2.printMatrix();
	std::cout << std::endl;

	std::cout << "Топологический порядок вершин: ";
	orientedGraph2.printSortedTopological();
	std::cout << std::endl << std::endl;

	system("pause");
	return EXIT_SUCCESS;
}