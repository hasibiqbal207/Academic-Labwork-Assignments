#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int mini(int dist[], bool visit[],int n)
{
   int min = INT_MAX, min_index;
   for (int i=0;i<n;i++)
   {
       if (visit[i] == false && dist[i] <= min)
         min = dist[i], min_index = i;
   }
   return min_index;
}

void dijkstra(int **graph,int n,int s)
{
    int dist[n];
    bool visit[n];

    for(int i=0;i<n;i++)
        dist[i]=INT_MAX,visit[i]=false;

    dist[s] = 0;
    for(int i=0;i<n-1;i++)
    {
        int u = mini(dist,visit,n);
        visit[u]=true;

        for(int j=0;j<n;j++)
        {
            if(graph[u][j] && !visit[j] && dist[j]>dist[u]+graph[u][j] && dist[u]!=INT_MAX)
                dist[j]=dist[u]+graph[u][j];
        }
    }
    ofstream oFile;
    oFile.open("output.txt");
    oFile<<"Shortest Distance From Node "<<s<<" to Other Node is : "<<endl;
    for(int i=0;i<n;i++)
        oFile<<"Node "<<i<<" : "<<dist[i]<<endl;
}

int main()
{
    ifstream iFile;
    iFile.open("input.txt");

    int n;
    iFile>>n;

    int **graph;
    graph = new int *[n];
    for(int i=0;i<n;i++)
        graph[i] = new int[n];

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

    int s;
    cout<<"Enter Source Node : ";
    cin>>s;

    dijkstra(graph,n,s);
}
