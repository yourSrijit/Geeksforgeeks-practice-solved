class Solution{
    public static int kthSmallest(int[] arr, int l, int r, int k) 
    { 
        PriorityQueue<Integer> pq=new PriorityQueue<Integer>(Comparator.reverseOrder());
        //Your code here
        for(int i=0;i<=r;i++){
            pq.add(arr[i]);
            if(pq.size()>k){
                pq.remove();
            }
        }
        return pq.peek();
    } 
}
