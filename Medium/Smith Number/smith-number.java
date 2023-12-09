//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.smithNum(n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int smithNum(int n) {
        // code here
        int sum =0 ;
        int k = n;
        int temp = digitsum(n);
        
        // finding prime factor of number
        for(int i=2;i<=Math.sqrt(n);i++){
            while( n % i == 0){
                sum += digitsum(i);
                n  /= i;
            }
        }
        if(n>1 && n !=k){
            sum += digitsum(n);
        }
        return sum == temp ? 1:0;
    }
        
        // finding addition of number 
        static int digitsum(int n){
            int temp = n ;
            int ans =0;
            while(temp != 0){
                ans += temp % 10;
                temp /= 10;
            }
            return ans ;
        }
}