
class Solution{
    static int setSetBit(int x, int y, int l, int r){
        // code here
      
       for(int i=l-1;i<r;i++) // because 1 based indexing 
       {
           int bit = (y>>i)&1;  // right shift to find if 1 is present at binary rep of y
           x |= bit << i;  // set bit to 1 if above condition holds
           
       }
       return x;
       
    }
}
