#include <iostream>
using namespace std;

int main()
{
    int start[] =  {1, 3, 0, 5, 8, 5};
    int finish[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(start)/sizeof(start[0]);
    int i=0, j;

    cout<<"Selected Activity Numbers are : "<<i<<" ";

    for (j = 1; j < n; j++)
    {
      if (start[j] >= finish[i])
      {
          cout<<j<<" ";
          i = j;
      }
    }
    return 0;
}
