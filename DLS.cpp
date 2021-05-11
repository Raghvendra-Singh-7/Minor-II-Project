#include <bits/stdc++.h>
using namespace std;
vector<int> res;
class Graph
{
    int V;
    unordered_map<int, vector<pair<int, int>>> adjlst;
public:
    
    void addEdge(int v, int w, int wt , bool bidrc)
    {
        adjlst[v].push_back(make_pair(w,wt));
        if(bidrc){
            adjlst[w].push_back(make_pair(v,wt));
        }
    }
    bool DLS(int src, int target, int limit){
    if (src == target){
        return true;
    }
    if (limit <= 0){
        return false;
    }
    for (auto i : adjlst[src])
       if (DLS(i.first, target, limit-1) == true){
          res.push_back(src);
          return true;
       }
     return false;
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
    Graph g;
    cout << "Enter the list of edges in the format : v1 v2 weight:";
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g.addEdge(a, b, c,true);
    }
    cout << "Enter the source vertex:";
    cin >> source;
    cout << "Enter the target vertex:";
    cin >> target;
    int limit;
    cout << "Enter the limit:";
    cin>>limit;
    cout << endl;
    res.push_back(source);
    if(g.DLS(target, source,limit)){
        cout<<"True"<<endl;
        cout<<"Path is : ";
        for(auto it : res){
            cout<<it<<"->";
        }
    }
    else{
        cout<<"False"<<endl;
    }
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