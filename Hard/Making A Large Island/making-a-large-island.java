//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];

        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }

        return mat;
    }

    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }

    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int n;
            n = Integer.parseInt(br.readLine());
            
            
            int[][] grid = IntMatrix.input(br, n, n);
            
            Solution obj = new Solution();
            int res = obj.largestIsland(n, grid);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution{
    
    static Map<Integer, Integer> unmap = new HashMap<>();
    static int dfs(int i, int j, int[][] grid, boolean[][] visited, int key) {
        int n = grid.length;
        if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        int count = 1 + dfs(i + 1, j, grid, visited, key)
                     + dfs(i - 1, j, grid, visited, key)
                     + dfs(i, j + 1, grid, visited, key)
                     + dfs(i, j - 1, grid, visited, key);
        grid[i][j] = key;
        return count;
    }
    
    public int largestIsland(int N,int[][] grid) 
    {
        int n = grid.length;
        int key = 2;
        boolean[][] visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int count = dfs(i, j, grid, visited, key);
                    unmap.put(key, count);
                    key++;
                }
            }
        }
 
        int result = -1;
        boolean[][] visited2 = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int a = (i + 1 < n) ? grid[i + 1][j] : 0;
                    int b = (i - 1 >= 0) ? grid[i - 1][j] : 0;
                    int c = (j + 1 < n) ? grid[i][j + 1] : 0;
                    int d = (j - 1 >= 0) ? grid[i][j - 1] : 0;
                    Set<Integer> st = new HashSet<>();
                    st.add(a);
                    st.add(b);
                    st.add(c);
                    st.add(d);
 
                    int res = 1;
                    for (int value : st) {
                        res += unmap.getOrDefault(value, 0);
                    }
                    result = Math.max(result, res);
                }
            }
        }
        if (result == -1) {
            return n * n;
        }
        return result;
    }
}
