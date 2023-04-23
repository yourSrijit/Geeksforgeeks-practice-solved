class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        int mini = INT_MAX;
        int gcd=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2!=0) return 1;
            mini = min(arr[i],mini);
            gcd=__gcd(gcd,arr[i]);
        }
     return mini;
        return gcd;
    }
};
