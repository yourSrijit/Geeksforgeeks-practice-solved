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
            long N = Long.parseLong(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.isPerfectNumber(N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static int isPerfectNumber(long N) {
        if (N <= 1) {
            return 0; // Perfect numbers are greater than 1.
        }

        long sumOfFactors = 1; // Initialize with 1 as 1 is always a factor.

        for (long i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                sumOfFactors += i;
                if (i != N / i) {
                    sumOfFactors += N / i;
                }
            }
        }

        if (sumOfFactors == N) {
            return 1; // N is a perfect number.
        } else {
            return 0; // N is not a perfect number.
        }
    }
}