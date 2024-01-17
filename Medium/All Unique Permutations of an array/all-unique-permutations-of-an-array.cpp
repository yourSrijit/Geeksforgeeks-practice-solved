//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
void solve(set<vector<int>> &sv, vector<int> arr, int ind, int n) {
        // base case
        if(ind == n) {
            sv.insert(arr);
            return ;
        }
        
        for(int j = ind;j < n; j++) {
            swap(arr[ind], arr[j]);
            solve(sv, arr, ind+1, n);  // recursive case
            swap(arr[ind], arr[j]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> sv;
        solve(sv, arr, 0, n);

        vector<vector<int>> ans(sv.begin(), sv.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends