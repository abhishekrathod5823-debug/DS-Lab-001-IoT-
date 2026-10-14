
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 20;

int graph[MAX][MAX];
int visited[MAX];
int n;

// Depth First Search
void DFS(int vertex)
{
    visited[vertex] = 1;
    cout << vertex << " ";

    for (int i = 1; i <= n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Breadth First Search
void BFS(int start)
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 1; i <= n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int edges, u, v, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n < 1 || n >= MAX)
    {
        cout << "Invalid number of vertices!";
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    if (edges < 0 || edges > n * (n - 1) / 2)
    {
        cout << "Invalid number of edges!";
        return 0;
    }

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Input edges
    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        if (u < 1 || u > n || v < 1 || v > n || u == v)
        {
            cout << "Invalid edge!";
            return 0;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 1 || start > n)
    {
        cout << "Invalid starting vertex!";
        return 0;
    }

    // Perform DFS
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    cout << "\nDFS Traversal: ";
    DFS(start);

    // Perform BFS
    cout << "\nBFS Traversal: ";
    BFS(start);

    cout << endl;

    return 0;
}
