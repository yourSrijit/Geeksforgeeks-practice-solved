//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Driverclass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            int k = sc.nextInt();

            System.out.println(new Solution().countOccurence(arr, n, k));
        }
    }
}

// } Driver Code Ends


class Solution 
{
    //Function to find all elements in array that appear more than n/k times.
public int countOccurence(int[] arr, int n, int k) 
    {
      HashMap<Integer,Integer> h=new HashMap<>();
      
      for(int i:arr){
          h.put(i,h.getOrDefault(i,0)+1);
      }
      int ans=0;
      for(int i:arr){
          if(h.containsKey(i)&&h.get(i)>n/k){
              h.remove(i);
             ans++;
          }
      }
      return ans;
    }
}
