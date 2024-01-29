//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
int ans(int &count,vector<int>&v,int i,int prev,int len, vector<vector<int>>&mp)
{
    if(i==len)
    {
      
        return mp[i][prev]=1;
    }
    if(mp[i][prev]!=-1)
    {
        return mp[i][prev];
    }
    int sum=0,a=0;
    for(int ii=i;ii<len;ii++)
    {
        sum+=v[ii];
        if(sum>=prev)
        {
          a+=ans(count,v,ii+1,sum,len,mp);
        }
    }
    return mp[i][prev]=a;
    
}
int TotalCount(string str){
    // Code here
    vector<vector<int>>mp(str.length()+2,vector<int>(1000,-1));
    int count=0;
    vector<int>v;
    for(int i=0;i<str.length();i++)
    {
        v.push_back(str[i]-'0');
    }
    return ans(count,v,0,0,str.length(),mp);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends