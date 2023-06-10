class Solution
{
    private:
        void merge(int arr[], int low, int mid, int high){
            /*
            -1 -2 -3 1 2 3 -5 -6 -7 9 8 7
                     -----|--------
                       Lp    Rn 

            Reversing Lp and Rn individually
            -1 -2 -3 3 2 1 -7 -6 -5 9 8 7
                     -----|--------
                       Lp    Rn       
            
            Reversing (Lp + Rn)
            -1 -2 -3 -5 -6 -7 1 2 3 9 8 7
                     --------|-----
                         Rn    Lp   
            
            Above is the required merged array, maintaining order + (negative on left, and positive on right)
            */
            
            int Lp = low;
            while(Lp <= mid & arr[Lp] < 0)
                Lp++;
                
            reverse(arr + Lp, arr + mid + 1);
                
            int Rn = mid+1;
            while(Rn <= high && arr[Rn] < 0)
                Rn++;
                
            reverse(arr + mid + 1, arr + Rn);
            
            reverse(arr + Lp, arr + Rn);
        }
    
        void mergeSort(int arr[], int low, int high){
            if(low < high)
            {
                int mid = low + (high-low)/2;
                mergeSort(arr, low, mid);
                mergeSort(arr, mid + 1, high);
                merge(arr, low, mid, high);
            }
        }
    
    public:
        void Rearrange(int arr[], int n)
        {
            mergeSort(arr, 0, n-1);
        }
};
