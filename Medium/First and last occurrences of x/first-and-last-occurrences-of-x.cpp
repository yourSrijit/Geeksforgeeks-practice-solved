//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int getfirst(int arr[],int n,int x){
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(arr[mid] == x){
                ans = mid;
                end = mid - 1;
            }
            else if(arr[mid] > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
    
        int getlast(int arr[],int n,int x){
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(arr[mid] == x){
                ans = mid;
                start = mid + 1;
            }
            else if(arr[mid] > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        int first = -1;
        int second = -1;
        bool exist = false;
        first = getfirst(arr,n,x);
        second = getlast(arr,n,x);
        if(second == -1 && first == -1 ) return {-1,-1};
        else if(second == -1) {
            second = first;
        }
        return {first,second};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends