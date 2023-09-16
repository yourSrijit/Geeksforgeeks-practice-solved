//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class GFG implements Runnable {
    public void run() {
        try {
            BufferedReader in;
            PrintWriter out;
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            int t = Integer.parseInt(in.readLine());

            while (t-- > 0) {
                int n = Integer.parseInt(in.readLine().trim());

                Solution g = new Solution();
                out.println(g.countWays(n));
            }
            out.close();
        } catch (Exception e) {
            ;
        }
    }

    public static void main(String args[]) throws IOException {
        new Thread(null, new GFG(), "whatever", 1 << 26).start();
    }
}
// } Driver Code Ends


//User function Template for Java


class Solution
{
    //Function to count the number of ways in which frog can reach the top.
    static long countWays(int n){
        if(n==1) return 1L;
        
        int[] dp=new int[n+1];
        dp[0]=1;
        
        int mod=1000000007;
        
        for(int i=1;i<=n;i++){
            int one=dp[i-1];
            int two=0,three=0;
            if(i>=2) two=dp[i-2];
            if(i>=3) three=dp[i-3];
            dp[i]=((one%mod+two%mod)%mod+three%mod)%mod;
        }
        
        return dp[n];
    }
}
  


