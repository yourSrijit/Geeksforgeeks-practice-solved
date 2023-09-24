//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            Solution g = new Solution();
            ArrayList<Integer> ans = g.duplicates(a, n);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends

class Solution {
    public static ArrayList<Integer> duplicates(int arr[], int n) {
        // code here
        Map<Integer,Integer> map=new HashMap<>();
        for(int num:arr){
            map.put(num,map.getOrDefault(num,0)+1);
        }
        ArrayList<Integer> ans=new ArrayList<>();
        int flag=0;
        for(Map.Entry<Integer,Integer>e:map.entrySet()){
            if(e.getValue()>=2){
              ans.add(e.getKey());
              flag=1;
            }
        }
        Collections.sort(ans);
        if(flag==0){
            ans.add(-1);
        }
        return ans;
    }
}
