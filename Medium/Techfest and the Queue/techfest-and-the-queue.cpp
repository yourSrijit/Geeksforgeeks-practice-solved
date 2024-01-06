//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void PrimeFactors(int n,unordered_map<int,int>&mp)
    {
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                mp[i]++;
                n = n/i;
            }
        }
        if(n!=1)
        {
            mp[n]++;
        }
    }
public:
    int sumOfPowers(int a, int b){
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=a;i<=b;i++)
        {
            PrimeFactors(i,mp);
        }
        for(auto it : mp)
        {
            ans+=it.second;
        }
        return ans;
    }


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends