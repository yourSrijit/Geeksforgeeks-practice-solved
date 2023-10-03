//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
import java.lang.*; 
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
    		System.out.println (new Solution().colName (n));
        }
        
    }
}

// Contributed By: Pranay Bansal 

// } Driver Code Ends


//User function Template for Java

class Solution
{
    String colName (long n) {
        String col = "";
        
        while(n != 0){
            long index = n % 26;
            
            if(index == 0) {
                col += 'Z';
                n -= 1;
            } else
                col += (char) ((index - 1) + 'A');
            
            n /= 26;
        }
        
        String rev = col;
        col = "";
        
        for(int i = rev.length() - 1; i >= 0; i--)
            col += rev.charAt(i);
        
        return col;
    }
}