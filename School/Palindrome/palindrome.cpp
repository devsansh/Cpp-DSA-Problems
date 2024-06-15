//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        bool Palindrome(string digit, int size){
            for(int i = 0; i < size / 2; i++){
                if(digit[i] != digit[size - i - 1]){
                    return false;
                }
            }
            return true;
        }

        string is_palindrome(int n)
        {
            string digit = to_string(n);
            int size = digit.size();
            
            if(!Palindrome(digit, size)){
                return "No";
            } else {
                return "Yes";
            }
        }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends