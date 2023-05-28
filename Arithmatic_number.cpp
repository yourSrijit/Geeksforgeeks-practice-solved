// Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' denoting the common difference of an arithmetic sequence and an integer 'B'. you need to tell whether 'B' exists in the arithmetic sequence or not. Return 1 if B is present in the sequence. Otherwise, returns 0.

// Example 1:

// Input: A = 1, B = 3, C = 2
// Output: 1
// Explaination: 3 is the second term of the 
// sequence starting with 1 and having a common 
// difference 2


//  Example 2:
// Input: A = 1, B = 2, C = 3
// Output: 0
// Explaination: 2 is not present in the sequence.


class Solution{
public:
    int inSequence(int A, int B, int C){
        if(A==B) return 1;
        if( C>0 && (B-A)>0 && ((B-A)% C)==0) return 1;
        if( C<0 && (B-A)<0 && ((B-A)% C)==0) return 1;
        return 0;
    }
};


