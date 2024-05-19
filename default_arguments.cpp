#include <iostream>
using namespace std;
int main()
{
    float amount ;
    float value(float p, int n, float r = 0.15); // Function prototype
    void printline(char ch='*', int len = 40); // Function prototype

    printline(); // Use of default value for arguments

    amount = value(5000.00,5); // Deafualt for 3rd argument
    cout<<"\n Final value = "<<amount<<"\n\n";
    printline('='); // Default for 2nd argument
    return 0;
}

 float value(float p, int n, float r = 0.15){
    int year = 1;
    float sum = p;

    while(year <=n){
        sum = sum*(1+r);
        year = year+1;
    }
    return sum;
 }

void printline(char ch, int len){
    for(int i = 1; i<=len; i++)
    printf("%c",ch);
    printf("\n");
}