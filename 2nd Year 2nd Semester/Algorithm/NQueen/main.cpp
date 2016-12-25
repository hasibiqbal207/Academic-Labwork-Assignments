#include <iostream>
#include <cmath>

using namespace std;

int count = 0;
bool place(int x[],int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if((x[j] == i)||(abs(x[j]-i)==abs(j-k)))
        {
            return false;
        }
    }
    return true;
}

void nQueen(int x[],int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(x,k,i))
        {
            x[k]=i;
            if(k==n)
            {
                count++;
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
                nQueen(x,k+1,n);
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
    for(int i=1;i<=n;i++)
        x[i]=0;
    nQueen(x,1,n);
    cout<<"Possible Solution : "<<count;
}
