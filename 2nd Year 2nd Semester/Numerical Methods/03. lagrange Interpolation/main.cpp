#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double value[10]={1,2,3,4,5,6,7,8,9,10};
    double fValue[10]={1,1.414,1.732,2,2.236,2.449,2.646,2.828,3,3.162};

    double x;
    cout<<"Enter Value of X : ";
    cin>>x;

    int n;
    cout<<"Enter Order : ";
    cin>>n;

    double res;
    double l_find=1;
    double ac_va = sqrt(x);
    double error;

    for(int k=1;k<=n;k++)
    {
        res = 0;
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(i==j)    continue;
                l_find *= ((x-value[j])/(value[i]-value[j]));
            }
            res += fValue[i]*l_find;
            l_find=1;
        }
        error = ac_va-res;
        if(error<0)
            error = -error;
        cout<<"For Order "<<k<<" Approximate Error is "<<error<<endl;
    }
    cout<<"Result is : "<<res;
}
