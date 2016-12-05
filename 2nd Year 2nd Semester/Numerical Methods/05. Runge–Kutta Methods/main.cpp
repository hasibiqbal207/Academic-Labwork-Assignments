#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double func(double x,double y)
{
    double z,w;
    w=x+y;
    z=((5*x*x-y)/exp(w));
    return z;
}

int main()
{
    double x,y,h,lim1,lim2,dy,k1,k2,k3,k4;

    cout<<"Enter Value of x : ";
    cin>>x;

    cout<<"Enter Value of y : ";
    cin>>y;

    cout<<"Enter Value of h: ";
    cin>>h;

    cout<<"Enter Value of Lower Limit of x : ";
    cin>>lim1;

    cout<<"Enter Value of Upper Limit of x: ";
    cin>>lim2;

    while(x<=lim2)
    {
        k1 = h*func(x,y);
        k2 = h*func(x+h/2,y+k1/2);
        k3 = h*func(x+h/2,y+k2/2);
        k4 = h*func(x+h,y+k3);

        dy = (k1 + 2*k2 + 2*k3 + k4)/6;
        x+=h;
        y+=dy;
    }
    cout<<"Value of X is : "<<x<<endl;
    cout<<"Value of Y is : "<<y<<endl;

}
