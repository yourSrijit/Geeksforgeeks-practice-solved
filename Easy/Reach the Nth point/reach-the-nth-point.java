//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.nthPoint(n);
            System.out.println(ans);            
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
  public int nthPoint(int n)
    {
        // Code here
       int prev = 1;
       int prev2 = 1;
        int mod = (int)1e9 + 7;
       for(int i=2;i<=n;i++){
          int current = (prev2+prev)%mod;
          prev2 = prev%mod;
          prev = current%mod;
       }
       return prev;
    }
}