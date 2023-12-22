//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F)
    {
        //{f,index}
        vector<pair<int,int>>mp;
        int n=N;
        // only thing to note is that one meeting will start only if one meeting is ended
        // by seeing time complexity i get the idea of sorting according to finish time
        
        for(int i=0;i<n;++i)
        {
            mp.push_back({F[i],i});
        }
        //sort
        sort(mp.begin(),mp.end());
        vector<int>ans;
        ans.push_back(mp[0].second+1); // always able to finish first meeting
        int finish=mp[0].first;
        for(int i=1;i<n;++i)
        {
            
            //if starting time of second meeting is greater then ending of first
            if(S[mp[i].second]>finish)
            {
                ans.push_back(mp[i].second+1);
                finish=mp[i].first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends