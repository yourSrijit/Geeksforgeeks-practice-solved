//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n&1) return false;
        
        for(int &x:nums) x = x%k;
        
        sort(begin(nums), end(nums));
        
        int zero = 0;
        for(int x:nums) if(!x) zero++;
        if(zero&1) return false;
        else if(zero == n) return true;
    
        int ans = 0;
        
        for(int i = 0; i<(n-zero)/2; i++){
            if(nums[zero+i] + nums[n-i-1] != k) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends