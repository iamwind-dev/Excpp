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
    std::cout << "(Enter -1 -1 to stop)#include <iostream>
#include <iomanip>
#include <fstream>
        using namespace std;
    //----------------------------------------------------------------Khai báo cấu trúc dữ liệu
    int A[20][20];
    int n, top = 0, R = 0, F = 0;
    int X[20], S[20], Q[20];
    //----------------------------------------------------------------Viết hàm nhập xuất đồ thị
    void INP(int M[20][20], int &n)
    {
        for (int d = 1; d <= n; d++)
        {
            for (int c = 1; c <= n; c++)
            {
                cout << "A[" << d << "," << c << "]=";
                cin >> M[d][c];
            }
        }
    }
    //----------------------------------------------------------------Viết hàm xuất đồ thị
    void OUT(int M[20][20], int &n)
    {
        cout << " ";
        for (int i = 1; i <= n; i++)
        {
            cout << setw(4) << i;
        }
        cout << endl;
        for (int d = 1; d <= n; d++)
        {
            cout << d;
            for (int c = 1; c <= n; c++)
            {
                cout << setw(4) << M[d][c];
            }
            cout << endl;
        }
    }
    //----------------------------------------------------------------Viết hàm đánh dấu
    void DD(int X[20], int n)
    {
        for (int i = 1; i <= n; i++)
        {
            X[i] = 1;
        }
    }
    //----------------------------------------------------------------
    void Push(int S[20], int &dinh, int k)
    {
        if (dinh < 19)
        {
            dinh++;
            S[dinh] = k;
        }
    }
    //----------------------------------------------------------------
    void Pop(int S[20], int &dinh)
    {
        int k = -1; // Đặt giá trị mặc định cho k
        if (dinh > 0)
        {
            k = S[dinh];
            dinh--;
        }
        if (k != -1)
            cout << setw(4) << k;
    }

    //----------------------------------------------------------------Viết hàm duyệt sâu
    void DS(int M[20][20], int n)
    {
        cout << "1" << setw(4);
        X[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= 1; j--)
                if ((M[i][j] == 1) && (X[j] == 1))
                {
                    Push(S, top, j);
                    X[j] = 0;
                }
            Pop(S, top);
        }
    }
    //----------------------------------------------------------------
    void AddQ(int Q[20], int &R, int &F, int k)
    {
        if (R == 0 && F == 0)
        {
            R = F = 1;
            Q[R] = Q[F] = k;
        }
        else
        {
            R++;
            Q[R] = k;
        }
    }
    //----------------------------------------------------------------
    void DeleteQ(int Q[20], int &R, int &F)
    {
        int k;
        if (F <= R)
        {
            k = Q[F];
            F++;
            if (k != 0)
            {
                cout << setw(4) << k;
            }
            if (F > R)
            {
                F = R = 0;
            }
        }
    }

    //----------------------------------------------------------------Viết hàm duyệt rộng
    void DR(int M[20][20], int n)
    {
        cout << "1" << setw(4);
        X[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if ((M[i][j] == 1) && (X[j] == 1))
                {
                    AddQ(Q, R, F, j);
                    X[j] = 0;
                }
            DeleteQ(Q, R, F);
        }
    }
    //================================================================
    int main()
    {
        cout << "Số đỉnh= ";
        cin >> n;
        INP(A, n);
        // Mở tệp đầu ra

        // Chuyển luồng đầu ra sang tệp

        cout << "\n Đô thị vừa nhập:\n";
        OUT(A, n);
        DD(X, n);
        cout << "\n Duyệt sâu:\n";
        DS(A, n);
        cout << "\n";
        DD(X, n);
        cout << "\n Duyệt rộng:\n";
        DR(A, n);
        cout << "\n";

        system("pause");
        return 0;
    }
    " << std::endl;

        while (true)
    {
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
