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
        cout<<"Enter Key of node "<<i+1<<" : ";
        cin>>key[i];

        cout<<"Enter frequency of node "<<i+1<<" : ";
        cin>>frequency[i];
    }

    int root[n+1];
    double cost[n+1];

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
/*

int main()
{
    int low;
    int countE;
    cout<<"Enter the count of elements"<<endl;
    cin>>countE;
    float prob[2][countE];
    for(int i=0; i<countE; i++)
    {
        prob[0][i]=i+1;
        cout<<"Enter the "<<i+1<<" no. element priority"<<endl;
        cin>>prob[1][i];
    }
    float cost[countE+1][countE+1];
    int root[countE][countE];
    float whole[countE][countE];
    float compare[countE];
    for(int i=0; i<countE; i++)
    {
        for(int j=0; j<countE; j++)
        {
            cost[i][j]=0;
            root[i][j]=0;
            whole[i][j]=0;
            cost[i+1][j+1]=0;
        }
        compare[i]=99;
    }
    for(int i=0; i<countE; i++)
    {
        cost[i][i+1]=prob[1][i];
        whole[i][i]=prob[1][i];
        root[i][i]=prob[0][i];
    }
    for(int i=1; i<countE; i++)
    {
        for(int j=0; j<countE-i-1; j++)
        {
            whole[j][j+i]=whole[j][j+i-1]+whole[j+1][j+i]-whole[j+1][j+i-1];
        }
    }
    for(int i=2; i<=countE; i++)
    {
        for(int j=0; j<=countE-i; j++)
        {
            for(int k=2; k<i+2; k++)
            {
                compare[k-2]=cost[j][j+k-2]+cost[j+k-1][j+i];
            }
            low=0;
            for(int k=0; k<countE-1; k++)
            {
                if(compare[k+1]<compare[low])
                {
                    low=k+1;
                }
            }
            cost[j][j+i]=whole[j][j+i-1]+compare[low];
            root[j][j+i-1]=j+low-2;
        }
    }
    cout<<endl<<endl;
    for(int i=0;i<=countE;i++)
    {
         for(int j=0;j<=countE;j++)
         {
              cout<<cost[i][j]<<"        ";
         }
         cout<<endl;
    }
    return 0;
}
*/
