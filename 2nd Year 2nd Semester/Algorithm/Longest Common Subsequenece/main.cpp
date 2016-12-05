#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <sstream>

using namespace std;

string refine(string s)
{
    int l = s.length();
    string us;
    for(int i=0;i<l;i++)
    {
        if(((int)s[i]>=65 && (int)s[i]<=90) ||  ((int)s[i]>=97 && (int)s[i]<=122))
            us+=s[i];
    }
    return us;
}

int main()
{
    string x,y,ux,uy;
    int xLength,yLength;
    int arr[20];
    queue<int>wl;
    while(1)
    {
        int count =1;
        cout<<"Enter 1st Line : ";
        getline(cin,x);

        cout<<"Enter 2nd Line : ";
        getline(cin,y);

        int k,in=0;
        istringstream s(y);
        string s1;
        while(s>>s1)
        {
            k=s1.length();
            arr[in++]=k;
        }

        x=refine(x);
        y=refine(y);

        xLength = x.length();
        yLength = y.length();

        if(xLength==0 || yLength==0)
        {
            cout<<count<<". Blank!"<<endl;
            continue;
        }

        int lcs[xLength+1][yLength+1];

        for(int i=0;i<xLength+1;i++)
            lcs[0][i]=0;

        for(int i=0;i<yLength+1;i++)
            lcs[i][0]=0;

        for(int r=0;r<xLength+1;r++)
        {
            for(int c=0;c<yLength+1;c++)
            {
                lcs[r][c]=0;
            }
        }



        for(int r=1;r<xLength+1;r++)
            for(int c=1;c<yLength+1;c++)
        {
            if(x[r-1]==y[c-1])
            {
                lcs[r][c] = lcs[r-1][c-1]+1;
            }

            else
            {
                lcs[r][c] = max(lcs[r][c-1],lcs[r-1][c]);
            }
        }
       // vector<int> = iterator *it;

        int uc = lcs[xLength][yLength];
        int match=0;
        int pv;
        int i2=0;

        while(i2!=in)
        {
            pv = arr[i2++];
                uc-=pv;
                match++;

        }
        cout<<count++<<". Length of longest match : "<<match<<endl;
    }
}
