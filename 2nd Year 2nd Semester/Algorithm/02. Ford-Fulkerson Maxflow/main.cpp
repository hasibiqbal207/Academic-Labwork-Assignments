#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <fstream>

using namespace std;

bool bfs(int **residual,int n,int s, int t, int parent[])
{
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<n; v++)
        {
            if (visited[v]==false && residual[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson(int **graph,int n,int s,int t)
{
    int **residual;
    residual = new int *[n];
    for(int i=0;i<n;i++)
        residual[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            residual[i][j] = graph[i][j];
        }
    }

    int parent[n];
    int max_flow = 0,v,u;

    while(bfs(residual,n,s,t,parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    int n;
    ifstream iFile;
    iFile.open("1.txt");
    iFile>>n;

    int **graph;
    graph = new int *[n];
    for(int i=0;i<n;i++)
        graph[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }

    int r,c,v;
    while(iFile>>r>>c>>v)
    {
        graph[r][c]=v;
    }

    cout << "The maximum possible flow is " << fordFulkerson(graph,n,0,5);
    return 0;
}
