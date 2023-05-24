gngngfn
class Solution {
    public static int getMaximum(int N, int[] arr) {
        long sum=0L;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        int j=N;
        while(j>0)
        {
            if(sum%j==0)
            return j;
            j--;
        }
        return -1;
        // code here
    }
}
