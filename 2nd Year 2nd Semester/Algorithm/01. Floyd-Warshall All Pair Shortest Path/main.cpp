#include <iostream>
#include <fstream>

using namespace std;

void floyd(int **graph,int n)
{
    int dist[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for(int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout<<"Solution : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j] == 10000)
                cout<<"     INF    ";
            else
                cout<<"     "<<dist[i][j]<<"   ";
        }
        cout<<endl;
    }
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

    int row,col,val;
    while(iFile>>row>>col>>val)
    {
        if(val == -1)
            graph[row][col]=10000;
        else
            graph[row][col]=val;
    }

    floyd(graph,n);
    return 0;
}
