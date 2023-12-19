//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
  int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        int pos = 1;
        bitset<32> a(m);
        bitset<32> b(n);
        for(int i = 0;i<31;i++) {
            if(a[i] ^ b[i])
            return pos;
            pos++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends