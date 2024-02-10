//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
 long long numberOfPath(int n, int k, vector<vector<int>> &arr) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return traverse(arr, 0, 0, k, n, dp);
    }

private:
    int traverse(vector<vector<int>>& arr, int i, int j, int k, int n, vector<vector<vector<int>>>& dp) {
        if (i == n-1 && j == n-1) {
            return (k == arr[i][j]) ? 1 : 0;
        }
        if (k < arr[i][j]) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int res = 0;
        if (i < n-1) {
            res += traverse(arr, i+1, j, k-arr[i][j], n, dp);
        }
        if (j < n-1) {
            res += traverse(arr, i, j+1, k-arr[i][j], n, dp);
        }
        dp[i][j][k] = res;
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends