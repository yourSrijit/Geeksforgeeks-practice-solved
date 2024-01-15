//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
 vector<vector<int>>dp;
    int solve(int ind,int n,int total,vector<int> &cost){
       if(ind==n || total==0) return 0;
       
       if(dp[ind][total]!=-1) return dp[ind][total];
       
       if(cost[ind]<=total){
            return dp[ind][total]=max(1+solve(ind+1,n,total-cost[ind]+floor(0.9*cost[ind]),cost),solve(ind+1,n,total,cost));
        }
        else{
            return dp[ind][total]=solve(ind+1,n,total,cost);
        }
    }
    int max_courses(int n, int total, vector<int> &cost)
    {   dp.resize(n+1,vector<int>(total+1,-1));
        int ind=0;
        return solve(ind,n,total,cost);
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends