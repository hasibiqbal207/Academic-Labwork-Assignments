#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter Data Point : ";
    cin>>n;

    double findfnc[n+1][n+1];
    double x[n+1];
    double f[n+1];

    for(int i=0;i<=n;i++)
    {
        cout<<"Enter Value of X"<<i<<" : ";
        cin>>x[i];

        cout<<"Enter Value of f"<<i<<" : ";
        cin>>f[i];
        cout<<endl;
    }

    for(int i=n;i>=0;i--)
    {
        for(int j=0;j<=n;j++)
        {
            if(i>=j)
                findfnc[i][j]=0;
            else{
                if((j-i) == 1 )
                {
                    findfnc[i][j]=(f[j]-f[i])/(x[j]-x[i]);
                }
                else if((j-i)>=1)
                {
                    findfnc[i][j]=(findfnc[i+1][j] - findfnc[i][j-1])/(x[j]-x[i]);
                }
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<findfnc[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    double X;
    cout<<"Enter Value of X : ";
    cin>>X;

    findfnc[0][0] = f[0];
    double pa;
    for(int i=0;i<=n;i++)
    {
        double additional=1;
        for(int j=0;j<i;j++)
        {
            additional*=X-x[j];
        }
        pa+= findfnc[0][i]*additional;
    }
    cout<<"Solution  : "<<pa;
}
