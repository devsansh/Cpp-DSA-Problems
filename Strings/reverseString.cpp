#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    cout << "Enter a string: ";
    getline(cin, A);
    int n = A.size();
    char B[n + 1];
    for(int i = 0; i < n; i++) {
        B[i] = A[n - i - 1];
    }
    B[n] = '\0';   
    cout << "Reversed string: " << B << endl;
    
    return 0;
}
