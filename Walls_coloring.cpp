There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year. Alexa can color each wall with either pink, black, or yellow. The cost associated with coloring each wall with a particular color is represented by a 2D array colors of size N*3 , where colors[i][0], colors[i][1], and colors[i][2] is the cost of painting ith wall with colors pink, black, and yellow respectively.

You need to find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Example 1:

Input:
N = 3
colors[][] = {{14, 2, 11},
             {11, 14, 5},
             {14, 3, 10}}
Output:
10
Explanation:
Color wall 0 with black. Cost = 2. 
Color wall 1 with yellow. Cost = 5. 
Color wall 2 with black. Cost = 3.
Total Cost = 2 + 5 + 3 = 10


class Solution{   
public:
    int minCost(vector<vector<int>> &C, int N) {
        // Write your code here.
        vector<vector<long long int>> dp(N,vector<long long int>(3,-1));
        dp[0][0]=C[0][0];
        dp[0][1]=C[0][1];
        dp[0][2]=C[0][2];
        for(int i=1;i<N;i++){
            dp[i][0]=C[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=C[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=C[i][2]+min(dp[i-1][0],dp[i-1][1]);
        }
        return min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
    }
};
