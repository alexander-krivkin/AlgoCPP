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

	void printBFS(int vertex)
	{
		visited = new int[v] {};
		int queue[]{ vertex };

		visited[vertex] = 1;
		std::cout << (vertex + 1) << " ";

		BFS(queue, 1);

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

	void BFS(int* queue, int queueCounter)
	{
		if (!queueCounter) return;

		int* queueNext = new int[v] {};
		int queueCounterNext{};

		for(int idxQueue{}; idxQueue < queueCounter; idxQueue++)
		{
			for (int idxVertex{}; idxVertex < v; idxVertex++)
			{
				if ((matrix[queue[idxQueue]][idxVertex]) && (!visited[idxVertex]))
				{
					visited[idxVertex] = 1;
					std::cout << (idxVertex + 1) << " ";

					queueNext[queueCounterNext++] = idxVertex;
				}
			}
		}

		BFS(queueNext, queueCounterNext);

		delete[] queueNext;
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

	int vertex{};
	do
	{
		std::cout << "В графе " << v << " вершин.Введите номер вершины, с которой начнётся обход: ";
		std::cin >> vertex;
	} while ((vertex < 1) || (vertex > v));

	std::cout << std::endl << "Порядок обхода вершин (BFS): ";
	graph.printBFS(vertex - 1);

	std::cout << std::endl << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}