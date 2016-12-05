#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream iFile;
    ofstream oFile;
    iFile.open("input.txt");
    oFile.open("output.txt");
    string s,word1,word2;
    int index1,index2,min;
    vector<string> v;

    while(iFile>>s)
    {
        v.push_back(s);
    }

    cout<<"Enter First Word : ";
    cin>>word1;

    cout<<"Enter Second Word : ";
    cin>>word2;

    vector<string>::iterator it1;
    vector<string>::iterator it2;

    index1 = 0,index2 = 0,min = INT_MAX;
    for(it1 = v.begin();it1!=v.end();++it1)
    {
        if(word1==*it1)
        {
            for(it2 = v.begin();it2!=v.end();++it2)
            {
                if(word2==*it2 && (abs(index2-index1)<min))
                {
                    min = abs(index2-index1);
                }
                index2++;
            }
        }
        index1++;
        index2=0;
    }
    oFile<<"Shortest Distance is : "<<min;
}
