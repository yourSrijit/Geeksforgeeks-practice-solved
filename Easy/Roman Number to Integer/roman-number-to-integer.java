//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String roman = br.readLine().trim();
            Solution ob = new Solution();
            System.out.println(ob.romanToDecimal(roman));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    // Finds decimal value of a given roman numeral
    public int romanToDecimal(String s) {
        int l=s.length();
        int sum=0;
        for(int i=0;i<l;i++){
            char cur=s.charAt(i);
            if((i+1)<l && getVal(cur)< getVal(s.charAt(i+1))){
                sum-=getVal(cur);
            }
            else{
               sum+=getVal(cur);
            }
        }
        return sum;
        // code here
    }
    public static int getVal(char s){
        switch(s){
       case 'I': return 1;
       case 'V': return 5;
       case 'X': return 10;
       case 'L': return 50;
       case 'C': return 100;
       case 'D': return 500;
       case 'M': return 1000;
       default : return 0;
        }
    }
}