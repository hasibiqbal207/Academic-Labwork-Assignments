#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Number of data : ";
    cin>>n;

    double x[n+1],y[n+1],xx[n+1],xy[n+1];
    int in=0;
    int ind=n;
    while(ind--)
    {
        cout<<"Enter value of x : ";
        cin>>x[in];

        cout<<"Enter value of y : ";
        cin>>y[in++];
    }

    double sum1=0,sum2=0,sum3=0,sum4=0;

    for(int i=0;i<n;i++)
    {
        xx[i]=x[i]*x[i];
        xy[i]=x[i]*y[i];

        sum1+=x[i];
        sum2+=y[i];
        sum3+=xx[i];
        sum4+=xy[i];
    }
    x[n]=sum1;
    y[n]=sum2;
    xx[n]=sum3;
    xy[n]=sum4;

    double a,b;

    b = (n*xy[n] - x[n]*y[n]);
    b/=(n*xx[n] - x[n]*x[n]);
    a = ((y[n]/n)-(b*x[n])/n);

    cout<<"y = "<<a<<"+ "<<b<<"i"<<endl;
}
