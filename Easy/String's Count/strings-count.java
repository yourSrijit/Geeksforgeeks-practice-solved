//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
  
        
        int t = Integer.parseInt(br.readLine().trim()); 

        while(t > 0){
        	long n = Integer.parseInt(br.readLine().trim()); 
            Solution ob = new Solution();
            System.out.println(ob.countStr(n)); 
            t--;
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java
class Solution 
{ 
    static long countStr(long n)
	{
	    // code here
	    if(n==1) return 3;
	    else if(n==2) return 8;
	    
	    // All a
	    long res=1l;
	    
	    // One b or One c
	    res+=2l*n;
	    
	    // One b and One c
	    res+=n*1l*(n-1);
	    
	    // Two c
	    res+=n*1l*(n-1)*0.5;
	    
	    // One b and Two c and remaining A
	    res+=(n-1)*1l*(n-2)*n*0.5;
	    return res;
	}
}  