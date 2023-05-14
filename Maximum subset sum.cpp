long long findMaxSubsetSum(int n, vector<int> &a) {
        // code here
        long long dp[n][2];
        dp[0][0] = 0; 
        dp[0][1] = a[0];
        for (int i = 1; i<n; i++){
            dp[i][0] = dp[i-1][1]; 
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + a[i];
            
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
