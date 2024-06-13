#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    cout << "Enter a word: ";
    getline(cin, A);
    int n = A.size();
    for(int i = 0; i < n; i++) {
        if(A[i] != A[n - i - 1]){
            cout<<"FALSE";
            break;
        }
    } 
    cout<<"TRUE";
    return 0;
}
