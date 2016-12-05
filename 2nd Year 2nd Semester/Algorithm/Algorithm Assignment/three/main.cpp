#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        char c1,c2;
        int length,check=0;
        vector<string> v;
        string s;
        while(n--)
        {
            cin>>s;
            v.push_back(s);
        }

        vector<string>::iterator it;
        for(it=v.begin();it!=v.end()-1;++it)
        {
            s = *it;
            length = s.length();
            c1 = s[length-1];

            s = *(it+1);
            c2 = s[0];

            if(c1!=c2)
            {
                check=1;
                break;
            }
        }

        if(check==1)
            cout<<"The door cannot be opened."<<endl;
        else
            cout<<"Ordering is possible."<<endl;
        v.clear();
    }
}
