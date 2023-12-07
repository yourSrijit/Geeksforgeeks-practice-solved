//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;


class GFG {
	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		
		while(testcases-- > 0){
		    
		    String line1 = br.readLine();
		    String []element = line1.trim().split(" ");
		    int n = Integer.parseInt(element[0]);
		    int l = Integer.parseInt(element[1]);
		    int r = Integer.parseInt(element[2]);
		    
		    int arr[] = new int[n];
		    
		    
		    String line = br.readLine();
		    String[] elements = line.trim().split(" ");
		    
		    for(int index = 0;index < n; index++){
		        arr[index] = Integer.parseInt(elements[index]);
		    }
		    
		    Solution obj = new Solution();
		    
		    System.out.println(obj.countSubarrays(arr, n, l, r));
		        
		}
		
	}
}


// } Driver Code Ends


//User function Template for Java

class Solution{
     static long countLR(int arr[],int n,int x){
        long count=0;
        long sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>x){
                sum+=(count*(count+1))/2;
                count=0;
            }
            else{
                count++;
                
    }
        }
        sum+=(count*(count+1))/2;
        return sum;
    }
    
    
    static long countSubarrays(int a[], int n, int L, int R)  
    { 
        // Complete the function
       return countLR(a,n,R)-countLR(a,n,L-1);
    } 
}

