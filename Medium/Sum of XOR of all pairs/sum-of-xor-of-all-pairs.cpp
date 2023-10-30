//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
   {
        vector<long long int> v(32,0); 
        for(int i=0;i<n;i++){
            bitset<32> bits(arr[i]);
            for(int j=0;j<32;j++){
                v[j]+=bits[j];
            }
        }
        long long int ans=0;
        for(int i=0;i<32;i++){
            ans+=(v[i]*(n-v[i]))*(1<<i);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends