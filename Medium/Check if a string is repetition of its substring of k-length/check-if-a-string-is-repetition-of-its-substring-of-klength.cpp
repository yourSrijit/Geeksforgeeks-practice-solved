//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
public:
    
    int kSubstrConcat (int n, string s, int k)
    {
        
        if(n%k!=0)
        {
            return 0;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<=n-k;i=i+k){
            string temp = s.substr(i,k);
            mp[temp]++;
        }
      
       if(mp.size()<=2)
       {
           if(mp.size()==1) return 1;
           else
           {
               int ans=0;
               for(auto it:mp)
               {
                  if(it.second==1 ) ans++;
               }
               if(ans==1 || ans==2) return 1;
           }
       }
       return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends