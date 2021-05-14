#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<int> *adj_list;
    vector<int> *weight;
    int *prev;

public:
    Graph(int V)
    {
        this->V = V;
        adj_list = new vector<int>[V];
        weight = new vector<int>[V];
        prev = new int[V];
    }
    void addEdge(int v, int w, int wt)
    {
        adj_list[v].push_back(w);
        weight[v].push_back(wt);
        adj_list[w].push_back(v);
        weight[w].push_back(wt);
    }
    void Breadth_First_Search(int start, int target)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i)
        {
            visited[i] = false;
        }
        list<int> queue;
        int current;
        visited[start] = true;
        prev[start] = -1;
        queue.push_back(start);
        vector<int>::iterator i;
        while (!queue.empty())
        {
            current = queue.front();
            queue.pop_front();

            for (i = adj_list[current].begin(); i != adj_list[current].end(); ++i)
            {
                if (!visited[*i])
                {
                    prev[*i] = current;
                    visited[*i] = true;
                    if (*i == target)
                    {
                        cout << "Target Not Found" << endl;
                        displayPath(target);
                    }
                    queue.push_back(*i);
                }
            }
        }
    }
    void displayPath(int node)
    {
        int path = node;
        int temp;
        int pos;
        int path_dis = 0;
        cout << "Path is: ";
        vector<int> vec;
        while (path != -1)
        {
            vec.push_back(path);
            temp = prev[path];
            if (temp != -1)
            {
                pos = find(adj_list[path].begin(), adj_list[path].end(), temp) - adj_list[path].begin();
                path_dis = path_dis + weight[path].at(pos);
            }
            path = temp;
        }
        for (int i = 0; i < vec.size() - 1; i++)
        {
            cout << vec[i] << "->";
        }
        auto it = vec.end() - 1;
        cout << *it;
        cout << endl;
        cout << "pathlength : " << path_dis;
    }
};

int main()
{
    clock_t tStart = clock();
    int n, e, a, b, c;
    int source, target;
    cout << "Enter the no. of vertices:";
    cin >> n;
    cout << "Enter the no. of edges:";
    cin >> e;
    Graph g(n);
    cout << "Enter the list of edges in the format : v1 v2 weight:";
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    cout << "Enter the source vertex:";
    cin >> source;
    cout << "Enter the target vertex:";
    cin >> target;
    g.Breadth_First_Search(target, source);
    cout << endl;
    cout << "Time taken: ";
    double ans = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << ans;
    return 0;
}
/*
10
9
0 1 12
0 2 8
0 3 7 
1 4 8 
1 5 7
2 6 6 
2 7 5
3 8 4 
3 9 3 
1 9
*/
