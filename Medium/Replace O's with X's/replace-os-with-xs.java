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
            String a[] = in.readLine().trim().split(" ");
            int n = Integer.parseInt(a[0]);
            int m = Integer.parseInt(a[1]);
            char mat[][] = new char[n][m];
            for(int i=0; i<n; i++)
            {
                String S[] = in.readLine().trim().split(" ");
                for(int j=0; j<m; j++)
                {
                    mat[i][j] = S[j].charAt(0);
                }
            }
            
            Solution ob = new Solution();
            char[][] ans = ob.fill(n, m, mat);
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    System.out.print(ans[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    static char[][] fill(int n, int m, char[][] a) {
        // Iterate over the first and last columns and mark 'O's and their neighbors as visited.
        for (int i = 0; i < n; i++) {
            if (a[i][0] == 'O') {
                dfs(i, 0, a);
            }
            if (a[i][m - 1] == 'O') {
                dfs(i, m - 1, a);
            }
        }

        // Iterate over the first and last rows and mark 'O's and their neighbors as visited.
        for (int j = 0; j < m; j++) {
            if (a[0][j] == 'O') {
                dfs(0, j, a);
            }
            if (a[n - 1][j] == 'O') {
                dfs(n - 1, j, a);
            }
        }

        // Replace unvisited 'O's with 'X' and revert visited 'O's back to 'O'.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'O') {
                    a[i][j] = 'X';
                } else if (a[i][j] == '*') {
                    a[i][j] = 'O';
                }
            }
        }

        return a;
    }

    private static void dfs(int i, int j, char[][] a) {
        if (i < 0 || i >= a.length || j < 0 || j >= a[0].length || a[i][j] != 'O') {
            return;
        }

        // Mark 'O' as visited with '*'.
        a[i][j] = '*';

        // Recursively visit neighbors.
        dfs(i + 1, j, a);
        dfs(i - 1, j, a);
        dfs(i, j + 1, a);
        dfs(i, j - 1, a);
    }
}