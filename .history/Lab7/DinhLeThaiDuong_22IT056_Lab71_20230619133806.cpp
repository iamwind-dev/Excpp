#include <iostream>

// Function to create a graph using adjacency matrix
int** createGraph(int n) {
    int** adjMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    int source, destination;

    std::cout << "Enter edges in the graph (source destination):" << std::endl;
    std::cout << "(Enter -1 -1 to stop)" << std::endl;

    while (true) {
        std::cin >> source >> destination;
        if (source == -1 && destination == -1) {
            break;
        }
        if (source < 0 || source >= n || destination < 0 || destination >= n) {
            std::cout << "Invalid vertex. Try again." << std::endl;
        } else {
            adjMatrix[source][destination] = 1;
            adjMatrix[destination][source] = 1;
        }
    }

    return adjMatrix;
}

// Function to perform Breadth-First Search traversal
void BFS(int** adjMatrix, int n, int startVertex) {
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int* queue = new int[n];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    std::cout << "BFS traversal starting from vertex " << startVertex << ": ";

    while (front < rear) {
        int vertex = queue[front++];

        std::cout << vertex << " ";

        for (int i = 0; i < n; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    std::cout << std::endl;

    delete[] visited;
    delete[] queue;
}

// Function to perform Depth-First Search traversal
void DFSUtil(int** adjMatrix, int n, int vertex, bool* visited) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(adjMatrix, n, i, visited);
        }
    }
}

void DFS(int** adjMatrix, int n, int startVertex) {
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    std::cout << "DFS traversal starting from vertex " << startVertex << ": ";
    DFSUtil(adjMatrix, n, startVertex, visited);
    std::cout << std::endl;

    delete[] visited;
}

int main() {
    int n, source, destination;

    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> n;

    int** adjMatrix = createGraph(n);

    std::cout << "Enter the starting vertex for traversal: ";
    std::cin >> source;

    BFS(adjMatrix, n, source);
    DFS(adjMatrix, n, source);

    // Free the memory allocated for adjacency matrix
    for (int i = 0; i < n; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
