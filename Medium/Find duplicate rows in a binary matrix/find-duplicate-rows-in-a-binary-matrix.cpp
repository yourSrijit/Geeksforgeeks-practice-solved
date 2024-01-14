//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        vector<int> str,ans;
        unordered_map<int,int> mp;
        int mod = 1e9 + 7;
        
        for(int i=0;i<M;i++){
            int num = 0;
            int p = 1;
            for(int j=0;j<N;j++){
                num = num + p*matrix[i][j];
                p = (p*2)%mod;
            }
            str.push_back(num);
        }
        
        int n =str.size();
        
        for(int i=0;i<n;i++){
            if(mp.find(str[i])==mp.end()){
                mp[str[i]] = i;
            }else{
                ans.push_back(i);
            }
        }
        
        return ans;
      
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends