//In this program, we will see how to use scope resolution operator (::)
#include <iostream>
using namespace std;

int m = 10; // Global variable 1

int main(){
    int m = 20; // Variable m redeclared 2
    {
        int k = m;
        int m = 30; // m declared again 34
                    // Local to innner block
        cout<<"Inner  Block \n";
        cout<<"k = "<<k<<"\n";
        cout<<"m = "<<m<<"\n";
        
            cout<<"::m with scope resolution operator = "<<::m<<"\n";
    }
        cout<<"Outer  Block \n";
        cout<<"m = "<<m<<"\n";
        cout<<"::m with scope resolution operator = "<<::m<<"\n";
        // Note that :: will always refer to global m declaration.
    return 0;
}