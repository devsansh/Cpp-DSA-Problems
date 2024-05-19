// Infline functions decreases the function call overhead but increases program size
#include <iostream>
using namespace std;

inline float mul(float x,float y){
    return (x*y);
}

inline float div(float p,float q){
    return (p/q);
}

int  main(){

    float a = 12.35, b = 9.82;
    cout<<mul(a,b)<<endl;
    cout<<div(a,b)<<endl;
    return 0;
}