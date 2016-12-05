#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

string bePrepare(string eqn)
{
    string upEqn;
    int length =eqn.length();
    for(int i=0;i<length;i++)
    {
        if(eqn[i]==' ')
            continue;
        upEqn+=eqn[i];
    }
    eqn = upEqn ;
    upEqn = "";
    length =eqn.length();
    if(eqn[0]=='x')
    {
        upEqn+='1';
    }

    for(int i=0;i<length;i++)
    {
        if(eqn[i]=='x' || eqn[i]=='y' || eqn[i]=='z' )
        {
            if(eqn[i-1]=='+' || eqn[i-1]=='-')
            {
                upEqn+='1';
                upEqn+=eqn[i];
                continue;
            }
            else{
                upEqn+=eqn[i];
                continue;
            }
        }
        upEqn+=eqn[i];
    }
    return upEqn;
}

int main()
{
    double xn,yn,zn,xo,yo,zo,error,range;
    double a[3],b[3],c[3],d[3];
    char x;
    int i=0;

    ifstream myFile("p1.txt");
    string eqn,upEqn;

    while(getline(myFile,eqn))
    {
        upEqn = bePrepare(eqn);
        stringstream s(upEqn);
        s>>a[i]>>x>>b[i]>>x>>c[i]>>x>>x>>d[i];
        i++;
        upEqn="";
    }
    myFile.close();
    xo = 0;
    yo = 0;
    zo = 0;
    range = 0.01 ;

    while(1)
    {
        xn = (d[0] - (b[0] * yo) - (c[0] * zo))/a[0];

        error = xn-xo;
        xo = xn ;
        if(error < 0)
            error = (-1)*error;
        if( error <= range )   break ;

        yn = (d[1] - (a[1] * xo) - (c[1] * zo))/b[1];

        error = yn-yo;yo = yn ;
        if(error < 0) error = (-1)*error;
        if( error <= range )   break ;

        zn = (d[2] - (a[2] * xo) - (b[2] * yo))/c[2];

        error = zn-zo;zo = zn ;
        if(error < 0) error = (-1)*error;
        if( error <= range )   break ;
    }
    cout<<"X = "<<xo<<endl<<"Y = "<<yo<<endl<<"Z = "<<zo;
    ofstream yourFile;
    yourFile.open("p1.txt",ios_base::app);
    yourFile<<"X = "<<xo<<endl<<"Y = "<<yo<<endl<<"Z = "<<zo<<endl;
    yourFile.close();
}
