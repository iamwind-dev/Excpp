#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// Function to create a graph using adjacency matrix
void createGraph(int **&matrix, int n)
{
    matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices
void addEdge(int **matrix, int u, int v)
{
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

// Function to perform breadth-first search (BFS) traversal
void BFS(int **matrix, int n, int startVertex)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    queue<int> queue;
    visited[startVertex] = true;
    cout << "BFS traversal starting from vertex " << startVertex << ": ";

    queue.push(startVertex);
    while (!queue.empty())
    {
        int currentVertex = queue.front();
        cout << currentVertex << " ";
        queue.pop();

        for (int i = 0; i < n; i++)
        {
            if (matrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue.push(i);
            }
        }
    }

    delete[] visited;
    cout << endl;
}

// Function to perform depth-first search (DFS) traversal
void DFS(int **matrix, int n, int startVertex)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    stack<int> stack;
    visited[startVertex] = true;
    cout << "DFS traversal starting from vertex " << startVertex << ": ";

    stack.push(startVertex);
    while (!stack.empty())
    {
        int currentVertex = stack.top();
        cout << currentVertex << " ";
        stack.pop();

        for (int i = 0; i < n; i++)
        {
            if (matrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                stack.push(i);
            }
        }
    }

    delete[] visited;
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    int **matrix;
    createGraph(matrix, n);

    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Add an edge\n";
        cout << "2. Perform BFS traversal\n";
        cout << "3. Perform DFS traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int u, v;
            cout << "Enter the vertices (u and v) to add an edge: ";
            std::cin >> u >> v;
            addEdge(matrix, u, v);
            break;
        }
        case 2:
        {
            int startVertex;
            std::cout << "Enter the starting vertex for BFS traversal: ";
            std::cin >> startVertex;
            BFS(matrix, n, startVertex);
            break;
        }
        case 3:
        {
            int startVertex;
            std::cout << "Enter the starting vertex for DFS traversal: ";
            std::cin >> startVertex;
            DFS(matrix, n, startVertex);
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    // Deallocate memory
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
