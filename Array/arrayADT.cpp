#include <iostream>
using namespace std;

class Array{
    public:
    int *A;
    int size;
    int length;

    void Display();

};

void Array::Display(){
    for(int i = 0; i < size;i++){
        cout<<A[i]<<" ";
    }

}
int main(){
    Array arra = Array();
    cout<<"Enter size of Array: ";
    cin>>arra.size;
    arra.A = new int[arra.size];
    arra.length = 0;
    for(int i = 0; i < arra.size;i++){
        arra.A[i] = rand();
    }
    arra.length = arra.size;

    arra.Display();
    return 0;
}