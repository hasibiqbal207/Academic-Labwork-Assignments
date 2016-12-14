#include <iostream>
#include <cmath>

using namespace std;

double func(double x,double y)
{
    double z;
    z = x + sqrt(y) ;
    return z;
}

int main()
{
    double upper,lower,x,y,h;

    cout<<"Enter Value of X : ";
    cin>>x;

    cout<<"Enter Value of Y : ";
    cin>>y;

    cout<<"Enter Upper Limit of x : ";
    cin>>upper;

    cout<<"Enter Lower Limit of x : ";
    cin>>lower;

    cout<<"Enter Value of h : ";
    cin>>h;

    double in = ((upper-lower)/h);
    int index = ceil(in);

    double yi[4];

    for(int i=0;i<in;i++)
    {
        cout<<"Step "<<i+1<<endl;
        for(int j=0;j<4;j++)
        {
            if(j==0)
            {
                yi[j]=y+h*func(x,y);
            }
            else{
                yi[j]=y+h*(func(x,y)+func(x+h,yi[j-1]))/2;
            }
            cout<<"Y["<<j+1<<"] :"<<yi[j]<<endl;
        }
        x+=h;
        y=yi[3];
        cout<<endl;
    }
}
