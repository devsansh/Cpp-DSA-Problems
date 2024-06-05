#include <iostream>
using namespace std;
int main(){

    cout<<"2D array in Stack: \n";
    int A[2][2] = {{1,2},{3,4}}; // Array in stack

    for(int i = 0; i < 2;i++){
        for(int j = 0; j < 2;j++){
            cout<<"\t"<<A[i][j]<<" ";
        }cout<<"\n";
    }
    cout<<"\n2D array in Heap: \n";
    int* q[3]; // Array of pointer
    q[0] = new int[3];
    q[1] = new int[3];
    q[2] = new int[3];
    q[0][0] = 5;
    q[0][1] = 6;
    q[0][2] = 7;

    q[1][0] = 8;
    q[1][1] = 9;
    q[1][2] = 10;
    
    q[2][0] = 11;
    q[2][1] = 12;
    q[2][2] = 13;

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            cout<<"\t"<<q[i][j]<<" ";
        }cout<<"\n";
    }
    cout<<"2D array in Stack using double poniter: \n";

    int** B;
    B = new int*[3];
    B[0] = new int[3];
    B[1] = new int[3];
    B[2] = new int[3];

    B[0][0] = 5;
    B[0][1] = 6;
    B[0][2] = 7;

    B[1][0] = 8;
    B[1][1] = 9;
    B[1][2] = 10;
    
    B[2][0] = 11;
    B[2][1] = 12;
    B[2][2] = 13;

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            cout<<"\t"<<B[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}