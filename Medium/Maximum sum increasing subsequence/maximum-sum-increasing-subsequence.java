//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
public int maxSumIS(int arr[], int n)  
    {  
        //code here.
       // {1, 101, 2, 3, 100} 
       // 1 + 101 = 102 x
       // 1 + 2 + 3 = 6
       // 1 + 2 + 3 + 100 = 106
       // yaha pr 101 k baad wala add nh hoga kiu k baki sb chhota h to isliye 101 drop hoga aur baki sb 
       // increasing me h aur 100 se chhota h isliye last wala answer sahi h 
       
       int[] dp = new int[n];
       int maxSum = 0;
       
       for(int i = 0; i < n; i++){
           dp[i] = arr[i];
       }
       
       for(int i = 0; i < n; i++){
           for( int j = 0; j < i; j++){
               if(arr[i] > arr[j]){
                   dp[i] = Math.max(dp[i],dp[j]+arr[i]);
               }
           }
           maxSum = Math.max(dp[i],maxSum);
       }
        
        return maxSum;
        
        
    }
}