#include <iostream>
using namespace std;
int main(){

    int *arr;
    int size;

    cout<<"Enter the size of the integer array: ";
    cin>>size;
    cout<<"Creating an array of size "<<size<<"..";
    arr = new int[size];
    //Check if memory avalable for memory allocation
    //In c++, 'bad_alloc' exception will be thrown
    if(!arr){
        cout<<"\nAllocation failed\n";
    }
    cout<<"\nDyanzmic allocation of memory for array 'arr' is successfull.";
    delete arr;
    return 0;
}