#include <iostream>

using namespace std;

int n=0;
int minElement(int di[],bool visited[])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && di[i]<=min)
        {
            min = di[i];
            min_index = i;
        }
    }
    return min_index;
}

int main()
{

    int m,src,des;
    cout<<"Enter Number of Server : ";
    cin>>n;
    cout<<"Enter Number of Cable : ";
    cin>>m;

    cout<<"Enter Source : ";
    cin>>src;
    cout<<"Enter Destination : ";
    cin>>des;

    int graph[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        graph[i][j]=0;
    }

    int s,ds,weight;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter source server :";
        cin>>s;

        cout<<"Enter des server : ";
        cin>>ds;

        cout<<"Enter Weight :";
        cin>>weight;

        graph[s][ds]=graph[ds][s] = weight;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
    {
        cout<<graph[i][j]<<" ";
    }
    cout<<endl;
    }




    int d[n];
    bool visited[n];

    for(int i=0;i<n;i++)
    {
        visited[i]=false,d[i]=INT_MAX;
    }

    d[src]=0;

    for(int i=0;i<n-1;i++)
    {
        int u = minElement(d,visited);
        visited[u]=true;

        for(int j=0;j<n;j++)
        {
            if(!visited[j] && d[u]!=INT_MAX && graph[u][j] && (d[j]>d[u]+graph[u][j]))
                d[j]=d[u]+graph[u][j];
        }
    }

    cout<<"Shortest Distance From "<<src<<" To "<<des<<" is "<<d[des];
}
