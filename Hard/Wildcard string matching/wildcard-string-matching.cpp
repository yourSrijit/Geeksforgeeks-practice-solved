//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
  bool f(int i,int j,string wild,string pattern,vector<vector<int>> &dp){
        if(i == wild.size()){
            if(j == pattern.size()) return true;
            else return false;
        }
        if(j == pattern.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(wild[i] == pattern[j] || wild[i] == '?'){
           return dp[i][j] = f(i+1,j+1,wild,pattern,dp);
        }
        if(wild[i] == '*'){
            return dp[i][j] = f(i,j+1,wild,pattern,dp)||f(i+1,j+1,wild,pattern,dp);
        }
    }
    bool match(string wild, string pattern)
    {
        // code here
        vector<vector<int>>dp(wild.size(),vector<int>(pattern.size(),-1));
        return f(0,0,wild,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends