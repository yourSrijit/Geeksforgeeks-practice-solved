class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        // we can use brute force approach 
        // like perform how it is to be by iterating one by one to elements and increace it by one
        
        
        // optimal way 
        //edit only the elements given in updates array by one
        // and then just perform the prefix-sum
        // take care of one based indexing😎
        // let's rock
        for(int i=0;i<k;i++){
            a[updates[i]-1]++;
        }
        
        // prefix
        for(int i=1;i<n;i++){
            a[i] += a[i-1];
        }
    }
};

