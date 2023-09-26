//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
 vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int x = j+1;
                int y = n-1;
                while(x < y)
                {
                    int temp = arr[i] + arr[j] + arr[x] + arr[y];
                    if(temp == k) 
                    {
                        if(st.find({arr[i], arr[j], arr[x], arr[y]}) == st.end()) ans.push_back({arr[i], arr[j], arr[x], arr[y]});
                        st.insert({arr[i], arr[j], arr[x], arr[y]});
                        x++;
                        y--;
                    }
                    else if(temp > k) y--;
                    else x++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends