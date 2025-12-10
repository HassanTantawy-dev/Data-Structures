#include <iostream>
#include <vector>

using namespace std;

class GraphMatrix
{
    int numVertices;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int vertices)
    {
        numVertices = vertices;
        matrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int src, int dest, bool directed = false)
    {
        matrix[src][dest] = 1;
        if (!directed)
        {
            matrix[dest][src] = 1;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
    int numVertices;
    vector<list<int>> adjList;

public:
    Graph(int vertices)
    {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest, bool directed = false)
    {
        adjList[src].push_back(dest);
        if (!directed)
        {
            adjList[dest].push_back(src);
        }
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << ":";
            for (int neighbor : adjList[i])
            {
                cout << " -> " << neighbor;
            }
            cout << endl;
        }
    }

    void DFS(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adjList[v])
        {
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};
int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    g.DFS(0);
    g.BFS(0);

    return 0;
}