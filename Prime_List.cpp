
// You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one.

// Example 1:

// Input:
// 2 → 6 → 10
// Output:
// 2 → 5 → 11
// Explanation:
// The nearest prime of 2 is 2 itself.
// The nearest primes of 6 are 5 and 7,
// since 5 is smaller so, 5 will be chosen.
// The nearest prime of 10 is 11.

class Solution{
public:
    Node *primeList(Node *head){
        int arr[100002] = {0};
        vector<int> prime;
        for(int i=2;i*i<100001;i++){
            if(!arr[i]){
                prime.push_back(i);
                for(int j=i*i;j<100001;j+=i){
                    arr[j]=1;
                }
            }
        }
        for(int i=sqrt(100001);i<100001;i++){
            if(arr[i]==0){
                prime.push_back(i);
            }
        }
        Node *temp = head;
        while(temp != NULL){
            int val = temp->val;
            auto it = lower_bound(prime.begin(), prime.end(), val);
            if(it != prime.begin() && (*it + *(it-1)) >= 2*val) temp->val = *(it-1);
            else temp->val = *it;
            temp = temp->next;
        }
        return head;
    }
}; 
