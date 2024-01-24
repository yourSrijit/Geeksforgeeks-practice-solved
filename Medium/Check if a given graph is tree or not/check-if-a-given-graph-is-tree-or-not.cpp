//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
bool dfs(int node, int parent, vector<bool>&vis, vector<int>arr[]){
        vis[node]=1;
        for(auto &it:arr[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, arr)==1) return 1;
            }else if(it!=parent) return 1;
        }
        return 0;
    }
  
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<int>arr[n];
        for(int i=0; i<m; i++){
            arr[adj[i][0]].push_back(adj[i][1]);
            arr[adj[i][1]].push_back(adj[i][0]);
        }
        
        vector<bool>vis(n, 0);
        if(dfs(0, -1, vis, arr)==1) return 0;
        for(int i=0; i<n; i++){
            if(vis[i]==0) return 0;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends