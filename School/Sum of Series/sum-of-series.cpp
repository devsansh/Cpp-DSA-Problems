//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
	// function to return sum of  1, 2, ... n
	long long seriesSum(int n) {
	    // code here
	    long long sum{0};
	    
	   sum = ((long long)n*((long long)n+1))/2;
	   return (long long)sum;
	}
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        Solution obj;
        long long res = obj.seriesSum(n);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends