#include <iostream>
using namespace std;

long fact(int number){
    if (number == 0 or number == 1)
        return 1;
    return number * fact(number-1);
}

int main(){
    cout<<"Enter number, to finds its value: ";
    int number;
    cin>>number;
    cout<<fact(number);
    return 0;
}
