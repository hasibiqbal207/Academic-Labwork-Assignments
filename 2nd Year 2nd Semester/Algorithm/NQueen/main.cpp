#include <iostream>
#include <cmath>

using namespace std;
//int count=0

bool place(int x[],int y[],int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if((x[j] == i)||(abs(x[j]-i)==abs(j-k)) || (y[j+1]==i && ) || (y[j+1]==i))
        {
            return false;
        }
    }
    return true;
}

void nQueen(int x[],int y[],int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(x,y,k,i))
        {
            x[k]=i;
            y[k+1]=k+2;
            y[k+2]=k+1;
            if(k==n)
            {
                cout<<"Position's :"<<endl;
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(x[i]==j)
                        {
                            cout<<"Q ";
                            continue;
                        }
                        cout<<"* ";
                    }
                    cout<<endl;
                }
            }
            else
            {
                nQueen(x,y,k+1,n);
            }
        }
    }
}

int n;
int main()
{
    cout<<"Enter Number of Queen : ";
    cin>>n;

    int x[n+1];
    int y[n+1];
    for(int i=1;i<=n;i++)
        x[i]=0,y[i]=0;
    nQueen(x,y,1,n);
}
