#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int vertices)
    {
        V = vertices;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void depth_first_search(int v)
    {
        bool *visited = new bool[V];
        memset(visited, false, sizeof(visited));
        dfs_recursive(v, visited);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                dfs_recursive(i, visited);
            }
        }
    }
    void dfs_recursive(int v, bool *visited)
    {
        vec.push_back(v);
        visited[v] = true;
        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[*it])
            {
                dfs_recursive(*it, visited);
            }
        }
    }
};
int main()
{
    clock_t tStart = clock();
    int n, e, a, b, c;
    int vstart;
    cout << "No. of vertices:";
    cin >> n;
    cout << "No. of edges:";
    cin >> e;
    Graph g(n);
    cout << "Enter the list of edges in the format : v1 v2 ";
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    cout << "Enter the start vertex:";
    cin >> vstart;
    g.depth_first_search(vstart);
    cout << "PATH: ";
    for (int i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[i] << "->";
    }
    auto it = vec.end() - 1;
    cout << *it << endl;
    cout << "Time taken: ";
    double ans = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << ans;
    return 0;
}
/*
10 
9
0 1
0 2
0 3
1 4
1 5
2 6
2 7
3 8
3 9
0
*/