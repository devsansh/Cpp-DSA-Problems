//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include <string>
class Solution {
public:
    
    // This function checks if a given string is a palindrome.
    bool Palindrome(string number, int size) {
        for(int i = 0; i < size / 2; i++) {
            if(number[i] != number[size - i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    // This function checks if all the numbers in the array are palindromes.
    int PalinArray(int a[], int n) {
        for(int i = 0; i < n; i++) {
            string numStr = to_string(a[i]); // Convert the integer to a string
            if(!Palindrome(numStr, numStr.size())) { // Check if the string is a palindrome
                return 0; // Return 0 if any number is not a palindrome
            }
        }
        return 1; // Return 1 if all numbers are palindromes
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends