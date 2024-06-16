//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

// } Driver Code Ends
class Solution
{
  public:
    vector<int> findIndex(int arr[], int n, int key)
    {
        vector<int> result = {-1,-1}; // When key is not found
        
        for(int i = 0; i < n; i++){
            if(key == arr[i]){
                result[0] = i;
                break;
            }
        }
        
        for(int j = n - 1; j >= 0; j--){
            if(key == arr[j]){
                result[1] = j;
                break;
            }
        }
        return result;
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
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends