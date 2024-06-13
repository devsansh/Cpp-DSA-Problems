#include <iostream>
#include <string>
using namespace std;
int  main(){
    string A,B;
    cout<<"Enter string 1: ";
    getline(cin,A);
    cout<<"Enter string 2: ";
    getline(cin,B);
    int i{0},j{0};
    for(i = 0, j = 0; A[i] != '\0' and B[j] != '\0';i++,j++){
        if(A[i] != B[j]){
            break;
        }
    }
    if(A[i] == B[j]){
            cout<<"Strings are equal.";
        }else{
            cout<<"Strings are not equal.";
        }
    return 0;

}