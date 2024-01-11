//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      string removeKdigits(string S, int k) {
        stack<char> ch;
        for(auto it:S)
        {
            while(k and !ch.empty() and ch.top()>it)
            {
                ch.pop();
                k--;
            }
            
            if(ch.empty() and it=='0')
            continue;
        
            ch.push(it);
        }
        
        //k is not zero, 
        while(!ch.empty() and k)
        {
            ch.pop();
            k--;
        }
        
        //making ans string
        string ans="";
        while(!ch.empty())
        {
            ans+=ch.top();
            ch.pop();
        }
        
        if(ans.size()==0)
        return "0";
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends