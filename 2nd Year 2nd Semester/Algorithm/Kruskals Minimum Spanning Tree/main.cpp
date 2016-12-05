#include <iostream>
#include <fstream>

using namespace std;

int n;

struct MST
{
    int src;
    int des;
    int wet;
};

void findMST(int graph[][7],int n)
{
   int setCheck[n];
   for(int i=0;i<n;i++)
   {
       setCheck[i]=-(i+1);
   }

   struct MST f[n];

   int min = 100000;
   int r_i,c_i;
   int e=0,cost=0,o=0,index;

   int row[11],col[11],data[11];
   for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
       {
           if(graph[i][j]!=0)
           {
               row[o]=i;
               col[o]=j;
               data[o]=graph[i][j];
               graph[i][j]=0;
               o++;
           }
       }

  /*  for(int i=0;i<11;i++)
        cout<<row[i]<<" "<<col[i]<<"    "<<data[i]<<endl;
  */

   for(int x=0;x<15;x++)
   {
       int min = 100000;
       for(int i=0;i<11;i++)
       {
           if(data[i]!=0 && data[i]<min)
           {
               min=data[i];
               index = i;
           }
       }
       data[index]=0;

       if(setCheck[row[index]] == setCheck[col[index]])
       {
           continue;
       }

           f[e].src=row[index];
           f[e].des=col[index];
           f[e].wet=min;
           cost+=f[e].wet;
           for(int i=0;i<7;i++)
           {
               if(setCheck[i]==setCheck[col[index]])
                setCheck[i]=setCheck[row[index]];
           }
           cout<<f[e].src<<" -> "<<f[e].des<<" = "<<f[e].wet<<endl;

           e++;

   }
   cout<<" cost = "<<cost;
}

int main()
{
    ifstream g;
    g.open("1.txt");
    g>>n;
    int graph[7][7];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    int r,c,v;
    while(g>>r>>c>>v)
    {
        graph[r][c]=v;
    }
    g.close();
    findMST(graph,n);
    return 0;
}


/*
 for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j];
        }
    }
*/
