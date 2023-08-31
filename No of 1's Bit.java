class Solution {
   static int setBits(int N) {
        int count=0;
        while(N>=1){
            if (N%2 == 1){
                count++;
            }
            N/=2;
        }
        return count;
    }
}
