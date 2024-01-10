//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
  int longSubarrWthSumDivByK(int arr[], int n, int k) {
        unordered_map<int,int> pre;
        int presum = 0;
        int maxi = 0;
        pre[0] = -1;  // Initializing with a dummy entry for easier calculation

        for(int i = 0; i < n; i++) {
            presum += arr[i];
            int remainder = (presum % k + k) % k; 

            if(pre.count(remainder))
                maxi = max(maxi, i - pre[remainder]);

            if(!pre.count(remainder))
                pre[remainder] = i;
        }

        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends