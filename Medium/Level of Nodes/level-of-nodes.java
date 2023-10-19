//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for(int i = 0; i < V+1; i++)
                list.add(i, new ArrayList<Integer>());
            for(int i = 0; i < E; i++)
            {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
                list.get(v).add(u);
            }
            int X = sc.nextInt();
            
            Solution ob = new Solution();
            
            System.out.println(ob.nodeLevel(V,list,X));
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/

class Solution {
    int nodeLevel(int V, ArrayList<ArrayList<Integer>> adj, int X){
        
        boolean[] visited=new boolean[V];
        int level=-1;
        Queue<Integer> queue=new LinkedList<>();
        queue.add(0);
        while(!queue.isEmpty()) {
            int size=queue.size();
            level++;
            for(int i=0; i<size; i++) {
                int current=queue.poll();
                visited[current]=true;
                if(current==X) return level;
                for(int neighbour:adj.get(current)) {
                    if(!visited[neighbour]) {
                        queue.add(neighbour);
                    }
                }
            }
        }
        return -1;
    }
}