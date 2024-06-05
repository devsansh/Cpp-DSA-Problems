#include <iostream>
#include <iomanip> // for setw()
using namespace std;
int main(){
    int Basic = 800, Allowance = 85, Total = 1045;
    cout<<"Without setw() ...\n";
    cout<<"Basic: "<<Basic<<endl;
    cout<<"Allowance: "<<Allowance<<endl;
    cout<<"Total: "<<Total<<endl;

    cout<<"Without setw() ...\n";
    cout<<setw(10)<<"Basic: "<<setw(10)<<Basic<<endl
        <<setw(10)<<"Allowance: "<<setw(10)<<Allowance<<endl
        <<setw(10)<<"Total: "<<setw(10)<<Total<<endl;
    return 0;
}