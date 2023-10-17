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
            int N = Integer.parseInt(in.readLine());
            int graph[][] = new int[N][N];
            
            for(int i = 0;i < N;i++)
                {String a[] = in.readLine().trim().split("\\s+");
                for(int j=0;j<N;j++)
                graph[i][j] = Integer.parseInt(a[j]);}
            
            Solution ob = new Solution();
            ArrayList<ArrayList<Integer>> ans = ob.transitiveClosure(N, graph);
            for(int i = 0;i < N;i++)
               { for(int j = 0;j < ans.get(i).size();j++)
                    System.out.print(ans.get(i).get(j) + " ");
            System.out.println();}
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static class Graph{
       public int v;
       public LinkedList<Integer>[] path;
       public Graph(int v){
           this.v = v;
            path = new LinkedList[v];
       }
       
       public void addPath(int graph[][]){
           for(int i = 0; i < v; i++){
               path[i] = new LinkedList<Integer>();
               path[i].add(i);
               for(int j = 0; j < v; j++){
                   if(graph[i][j] == 1){
                       path[i].add(j);
                   }
               } 
           }
       }
       
   }
   
   static ArrayList<ArrayList<Integer>> transitiveClosure(int N, int graph[][])
   {
       // code here
       boolean[] visited = new boolean[N];
       int[][] reached = new int[N][N];
       
       for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
            reached[i][j] = graph[i][j];
          } 
       }
       
       Graph graphObj = new Graph(N);
       graphObj.addPath(graph);
       
       for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
               visited[j] = false;
           }
           
           Queue<Integer> queue = new LinkedList<Integer>();
           queue.add(i);
           visited[i] = true;
           
           while(!queue.isEmpty()){
               int peek = queue.peek();
               queue.remove();
               
               reached[i][peek] = 1;
               
               for(int k = 0; k < graphObj.path[peek].size(); k++){
                   if(!visited[graphObj.path[peek].get(k)]){
                       queue.add(graphObj.path[peek].get(k));
                       visited[graphObj.path[peek].get(k)] = true;
                   }
               }
               
           }
       }
       
       ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
       for(int i = 0; i < N; i++){
           ArrayList<Integer> local = new ArrayList<Integer>();
          for(int j = 0; j < N; j++){
            local.add(reached[i][j]);
          } 
          
          result.add(local);
       }
       
       return result;
       
   }
}