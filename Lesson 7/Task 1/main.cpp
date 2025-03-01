#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


class Graph final
{
public:
	Graph(int v) : v(v), visited(nullptr)
	{
		matrix = new int*[v];

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			matrix[idxVertex] = new int[v];
		}
	}
	~Graph()
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

	void print()
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

	void printDFS()
	{
		visited = new int[v] {};

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			if (!visited[idxVertex])
			{
				DFS(idxVertex);
			}
		}

		delete[] visited;
	}


private:
	int v;
	int** matrix;
	int* visited;


	void DFS(int vertex)
	{
		visited[vertex] = 1;
		std::cout << (vertex + 1) << " ";

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			if ((matrix[vertex][idxVertex]) && (!visited[idxVertex]))
			{
				DFS(idxVertex);
			}
		}
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int v{};
	std::ifstream fileIn("input.txt");

	fileIn >> v;
	Graph graph(v);
	graph.loadFromFile(fileIn);
	graph.print();
	std::cout << std::endl;

	std::cout << "Порядок обхода вершин (DFS): ";
	graph.printDFS();

	std::cout << std::endl << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}