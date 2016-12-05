#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
double a,b,c;

string doProcess(string eqn)
{
    string upEqn;
    int length = eqn.length();

    for(int i=0;i<length;i++)
    {
        if(eqn[i]==' ')
            continue;
        else
            upEqn+=eqn[i];
    }

    eqn = "";
    eqn = upEqn ;
    upEqn = "" ;
    length = eqn.length();


    if(eqn[0]=='x')
    {
         upEqn+='1';
    }


    for(int i=0;i<length;i++)
    {
        if(eqn[i] == 'x')
        {
            if(eqn[i-1] == '+' || eqn[i-1] == '-')
            {
                upEqn+='1';
                upEqn+= eqn[i];
            }
            else
            {
                upEqn+= eqn[i];
            }
        }
        else{
            upEqn+=eqn[i];
        }
    }
    return upEqn;
}

double f(double x)
{
    return (a*x*x)+(b*x)+c;
}

int main()
{
    ifstream iFile;
    iFile.open("1.txt");
    string eqn,upEqn;
    getline(iFile,eqn);
    upEqn = doProcess(eqn);
    int p;

    char x;
    istringstream s(upEqn);
    s>>a>>x>>x>>p>>b>>x>>c;

    int xm;
    double xon,xoo,x1,x2,error,root,accuracy;
    double r1s,r1e,r2s,r2e;

    xm = sqrt(pow((b/a),2)-(2*(c/a))) ;



    for(int i=-xm;i<=xm;i++)
    {
        if( ( f((double)i)<0 && f((double)(i+1))>0) || (f((double)i)>0 && f((double)(i+1))<0) )
        {
            r1s = (double)i;
            r1e = (double)(i+1);
        }
    }

    x1 = r1s;
    x2 = r1e;

    for(int i=-xm;i<=xm;i++)
    {
        if ( ( f((double)i)>0 && f((double)(i+1))<0 ) || ( f((double)i)<0 && f((double)(i+1))>0) )
        {
            r2s = (double)i;
            r2e = (double)(i+1);
            break;
        }
    }

  //  cout<<r1s<<" "<<r1e<<" "<<r2s<<" "<<r2e<<endl;
    ofstream oFile;
    oFile.open("1.txt",ios_base::app);
    oFile<<endl<<endl;
    xoo = (x1 +x2)/2;
    accuracy = 0.0001 ;
    int i = 1;

    while(1)
    {
        if(f(xoo) == 0)
        {
            root = xoo;
            break;
        }

        if( f(x1) * f(xoo) < 0 )
        {
            x2 = xoo ;
        }
        else if( f(x2) * f(xoo) < 0 )
        {
            x1 = xoo ;
        }

        xon = (x1 +x2)/2;
        error = abs((xon - xoo)/xon);
        if(error <= accuracy)
        {
            root = xon ;
            break;
        }
        xoo = xon;
        cout<<i++<<"  = "<<xoo<<endl;
        oFile<<i++<<"  = "<<xoo<<endl;
    }
    cout<<"First Root is : "<<root<<endl;
    oFile<<"First Root is : "<<root<<endl;

    x1 = r2s;
    x2 = r2e;

    xoo = (x1 +x2)/2;
    accuracy = 0.0001 ;
    i = 1;

    while(1)
    {
        if(f(xoo) == 0)
        {
            root = xoo;
            break;
        }

        if( f(x1) * f(xoo) < 0 )
        {
            x2 = xoo ;
        }
        else if( f(x2) * f(xoo) < 0 )
        {
            x1 = xoo ;
        }

        xon = (x1 +x2)/2;
        error = abs((xon - xoo)/xon);
        if(error <= accuracy)
        {
            root = xon ;
            break;
        }
        xoo = xon;
        cout<<i++<<"  = "<<xoo<<endl;
        oFile<<i++<<"  = "<<xoo<<endl;
    }
    cout<<"Second Root is : "<<root<<endl;
    oFile<<endl;
    oFile<<"Second Root is : "<<root<<endl;
    oFile.close();
}
