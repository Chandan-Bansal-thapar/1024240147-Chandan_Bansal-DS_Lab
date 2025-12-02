#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << ":";
            for (int n : l[i])
            {
                cout << n;
            }
            cout << endl;
        }
    }
    void bfs()
    {
        vector<bool> ve(V, false);
        queue<int> q;
        q.push(0);
        ve[0] = true;
        while (q.size() > 0)
        {
            int a = q.front();
            q.pop();
            cout << a << " ";
            for (int i : l[a])
            {
                if (!ve[i])
                {
                    ve[i] = true;
                    q.push(i);
                }
            }
        }
    }
    void dfshelp(int u, vector<bool> &vis)
    {
        cout << u<<" ";
        vis[u] = true;
        for (int i : l[u])
        {
            if (!vis[i])
            {
                dfshelp(i, vis);
            }
        }
    }
    void dfs()
    {
        vector<bool> vis(V, false);
        int src = 0;
        dfshelp(src, vis);
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.bfs();
    cout << endl;
    g.dfs();
    return 0;
}