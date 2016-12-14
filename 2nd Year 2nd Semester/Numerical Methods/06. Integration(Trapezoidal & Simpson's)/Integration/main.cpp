#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    double h,upper,lower,n,x,sum,oddsum,evensum;
    int index;
    double trap,simp1,simp3;

    cout<<"Enter Upper Limit : ";
    cin>>upper;

    cout<<"Enter Lower Limit : ";
    cin>>lower;

    cout<<"Enter Value of h : ";
    cin>>h;

    n = ((upper-lower)/h);
    index = (int)n;

    double y[index+1];

    x=4;
    sum=0;
    for(int i=0;i<=index;i++)
    {
        y[i]=tan(x*3.1416/180);
        sum+=y[i];
        x+=h;
        if(i%2==1)
            oddsum+=y[i];
        else if((i%2==0) && i!=0)
            evensum+=y[i];
    }

    trap = h*((.5*(y[0]+y[index]))+(sum-(y[0]+y[index])));
    simp1 = h*((y[0]+y[index])+4*(oddsum)+2*(evensum-y[index]))/3;
    simp3 = 3*h*((y[0]+y[index])+3*(sum-(y[0]+y[index])-y[3])+2*y[3])/8;

    cout<<"Trapezoidal method solution : "<<trap<<endl;
    cout<<"Simpson's one-third method solution : "<<simp1<<endl;
    cout<<"Simpson's three-third method solution : "<<simp3<<endl;
}
