//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        function<int()> checkOdd = [&]()->int{
            int flag = 0;
            for(int i =0; i< N; i++) flag ^=arr[i];
            return flag & 1;
        };
        if(checkOdd()) return 0;
        
        
        int target = 0;
        for(int i =0; i< N; i++) target += arr[i];
        target /=2;
        vector<int> subsets(target+1, 0);
        subsets[0]=1;
        for (int i =0; i<N; i++){
            if(arr[i] > target) return 0;
            for(int j = target; j >= arr[i]; j--){
                subsets[j] += subsets[j-arr[i]];
            }
        }
        return (subsets[target] != 0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends