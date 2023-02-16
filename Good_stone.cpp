// Geek is in a geekland which have a river and some stones in it. Initially geek can step on any stone. Each stone has a number on it representing the value of exact step geek can move. If the number is +ve then geeks can move right and if the number is -ve then geeks can move left. Bad Stones are defined as the stones in which if geeks steps, will reach a never ending loop whereas good stones are the stones which are safe from never ending loops. Return the number of good stones in river.

// Example 1:

// Input: [2, 3, -1, 2, -2, 4, 1]
// Output: 3
// Explanation: Index 3, 5 and 6 are safe only. As index 1, 4, 2 forms a cycle and from index 0 you can go to index 2 which is part of cycle.

// Example 2:

// Input: [1, 0, -3, 0, -5, 0]
// Output: 2
// Explanation: Index 2 and 4 are safe only. As index 0, 1, 3, 5 form cycle.
class Solution{
public:
    int goodStones(int n,vector<int> &arr){
        vector<bool>reached(n,false);
        set<int>s;
        vector<int>tmp;
        for(int i=0;i<n;i++){
            if(reached[i])
                continue;
            int j=i;
            while(!reached[j]){
                reached[j]=true;
                tmp.push_back(j);
                j=j+arr[j];
                if(j>=n || j<0){
                    for(auto k:tmp){
                        s.insert(k);
                    }
                    tmp.clear();
                    break;
                }
            }
            if(tmp.size() && s.count(j)){
                for(auto k:tmp){
                    s.insert(k);
                }
            }
            tmp.clear();
        }
        return s.size();
    }  
};
