//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   string findLargest(int N, int S){
        string ans;
        if(S == 0 && N>1 || S>N*9)return "-1";
            
        while(S>=9){
            ans+="9";
            S-=9;
        }
        
        if(S)ans+=to_string(S);

        while(ans.size()<N)ans+="0";
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends