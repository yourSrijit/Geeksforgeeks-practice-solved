//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(br.readLine());
        while (testcases-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(a1[i]);
            }
            Solution ob = new Solution();
            int ans=ob.minNumber(a,n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java


class Solution
{
    public int minNumber(int a[], int n)
    {
        int s = 0;
        for(int i = 0; i<n ; i++)
        {
            s +=a[i];
        }
        
        for(int i = 0; i<1000001;i++)
        {
        if(isPrime(s+i))
        return i;
        }
        return -1;
    }
    
    public Boolean isPrime(int a)
    {
        if(a==1)
        return false;
        
        if(a == 2 || a == 3)
        return true;
        
        if(a%2 == 0 || a%3 == 0)
        return false;
        
        for (int i = 5; i < Math.sqrt(a); i = i + 6) 
            if (a % i == 0 || a % (i + 2) == 0) 
                return false; 
                
                
        return true;
    }
    
    
    
    
    
}
