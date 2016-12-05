#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;

    while(N--)
    {
        int k,m;
        cin>>k>>m;

        int w[m];
        int v[m];
        for(int i=0;i<m;i++)
            cin>>w[i]>>v[i];

        int value[m+1][k+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(i==0 || j==0)
                    value[i][j]=0;
                else if(w[i-1]<=j)
                {
                    value[i][j]=max(v[i-1] + value[i-1][j-w[i-1]],  value[i-1][j]);
                }
                else
                    value[i][j] = value[i-1][j];
            }
        }
        cout<<"Hey stupid robber, you can get "<<value[m][k]<<endl;
    }
}
