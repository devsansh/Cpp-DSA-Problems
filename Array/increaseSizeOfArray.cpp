#include <iostream>
using namespace std;
int main(){
    int* p = new int[5]; // Dynamic Allocation of Array
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;
    p[3] = 3;
    p[4] = 4;

    int* q = new int[10]; // New array declaration with greater size
    for(int i = 0; i < 5;i++){
        q[i] = p[i];
    }

    cout<<"Output with Array(p)"<<endl;
    for(int i = 0; i < 5;i++){
        cout<<p[i];    
    }
    cout<<endl;
    delete []p;
    p =q;
    cout<<"Output with Array(q)"<<endl;
    for(int i = 0; i < 5;i++){
        cout<<q[i];
    }
    delete []q;
    return 0;
}