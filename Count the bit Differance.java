class Solution{
    
    // Function to find number of bits needed to be flipped to convert A to B
    public static int countBitsFlip(int a, int b){
        
        // Your code here
        int c=a^b;
        int count=0;
        while(c>=1){
            if(c%2==1){
                count++;
            }
            c/=2;
        }
        return count;
        
    }
    
    
}
