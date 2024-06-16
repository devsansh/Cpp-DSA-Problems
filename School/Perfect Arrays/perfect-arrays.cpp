//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool isPerfect(int n, vector<int> &arr) {
        for(int i = 0; i < n; i++){
            if(arr[i] != arr[n-i-1]){
                return false;
            }
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        bool res = obj.isPerfect(n, arr);
        
        if (res) 
            cout<<"PERFECT"<<endl ;
        else 
            cout<<"NOT PERFECT"<<endl;
        
    }
}

// } Driver Code Ends