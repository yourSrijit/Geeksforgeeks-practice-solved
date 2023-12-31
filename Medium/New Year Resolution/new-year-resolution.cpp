//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
 
    public:
    int solve(int i,int coins[],int N,int sum,vector<vector<int>>&dp){
        if(sum==2024)return 1;
        if(sum!=0 and (sum%20==0 || sum%24==0)){
            return 1;
        }
        if(i>=N){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        return dp[i][sum]=solve(i+1,coins,N,sum,dp)||solve(i+1,coins,N,sum+coins[i],dp);
    }
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>>dp(N+1,vector<int>(2025,-1));
        return solve(0,coins,N,0,dp);
    }
    
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends