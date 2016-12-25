#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;

    double key[n+1];
    double frequency[n+1];

    for(int i=1;i<=n;i++)
    {
        cout<<"Enter Key of node "<<i<<" : ";
        cin>>key[i];

        cout<<"Enter frequency of node "<<i<<" : ";
        cin>>frequency[i];
    }

    int root[n+1][n+1];
    double cost[n+1][n+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)
                root[i][i]=i;
            else{
                root[i][j]=0;
            }

            if((i+1)==j)
                cost[i][j]=frequency[j];
            else
                cost[i][j]=0;
        }
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=n-i; j++)
        {
            double sum = 0;
            for(int u=j+1;u<=j+i;u++)
                sum+=frequency[u];

            double min = INT_MAX;
            int min_index;
            for(int u=j;u<j+i;u++)
            {
                if(min > (cost[j][u]+cost[u+1][j+i]))
                {
                    min = cost[j][u]+cost[u+1][j+i];
                    min_index=u+1;
                }
            }


            cost[j][j+i] = sum + min;
            root[j+1][j+i] = min_index;
        }
    }

    cout<<"Root Matrix : "<<endl;
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=n;j++)
         {
              cout<<"   "<<root[i][j]<<"    ";
         }
         cout<<endl;
    }

    cout<<"Cost Matrix : "<<endl;
    for(int i=0;i<=n;i++)
    {
         for(int j=0;j<=n;j++)
         {
              cout<<"   "<<cost[i][j]<<"    ";
         }
         cout<<endl;
    }
}
