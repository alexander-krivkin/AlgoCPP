#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


class Graph final
{
public:
	Graph(int v) : v(v), visited(nullptr), previousVertex(0), isCyclic(false)
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

	void printIsCyclic()
	{
		visited = new int[v] {};

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			if (!visited[idxVertex])
			{
				SilentDFS(idxVertex);
			}
		}

		delete[] visited;

		if (isCyclic)
		{
			std::cout << "В графе есть цикл!";
		}
		else
		{
			std::cout << "В графе нет циклов";
		}
	}


private:
	int v;
	int** matrix;
	int* visited;
	int previousVertex;
	bool isCyclic;


	void SilentDFS(int vertex)
	{
		visited[vertex] = 1;

		for (int idxVertex{}; idxVertex < v; idxVertex++)
		{
			if ((matrix[vertex][idxVertex]) && (!visited[idxVertex]))
			{
				SilentDFS(idxVertex);
			}

			if ((matrix[vertex][idxVertex]) && (visited[idxVertex]) &&
				(vertex != previousVertex) && (idxVertex != previousVertex))
			{
				isCyclic = true;
			}

			previousVertex = vertex;
		}
	}

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

			if ((matrix[vertex][idxVertex]) && (visited[idxVertex]) &&
				(vertex != previousVertex) && (idxVertex != previousVertex))
			{
				isCyclic = true;
			}

			previousVertex = vertex;
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

	int v1{};
	int v2{};
	std::ifstream fileIn1("input1.txt");
	std::ifstream fileIn2("input2.txt");

	fileIn1 >> v1;
	Graph graph1(v1);
	graph1.loadFromFile(fileIn1);
	graph1.print();
	std::cout << std::endl;

	graph1.printIsCyclic();

	std::cout << std::endl << std::endl;

	fileIn2 >> v2;
	Graph graph2(v2);
	graph2.loadFromFile(fileIn2);
	graph2.print();
	std::cout << std::endl;

	graph2.printIsCyclic();

	std::cout << std::endl << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}