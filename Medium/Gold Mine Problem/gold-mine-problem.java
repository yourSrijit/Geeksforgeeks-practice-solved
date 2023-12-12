//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String inline[] = in.readLine().trim().split("\\s+");
            int n = Integer.parseInt(inline[0]);
            int m = Integer.parseInt(inline[1]);
            String inline1[] = in.readLine().trim().split("\\s+");
            int M[][] = new int[n][m];
            for(int i = 0;i < n*m;i++){
                M[i/m][i%m] = Integer.parseInt(inline1[i]);
            }
            
            Solution ob = new Solution();
            System.out.println(ob.maxGold(n, m, M));
        }
    }
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int maxGold(int n, int m, int M[][])
    {
        int ans = 0;
        for(int j = 1; j < m; j += 1) {
            for(int i = 0; i < n; i += 1) {
                int a = 0;
                if(i - 1 >= 0) {
                    a = M[i-1][j-1];
                }
                
                int b = M[i][j-1];
                
                int c = 0;
                if(i + 1 < n) {
                    c = M[i+1][j-1];
                }
                M[i][j] += Math.max(a, Math.max(b, c));
                if(M[i][j] > ans) {
                    ans = M[i][j];
                }
            }
        }
        return ans;
    }
}