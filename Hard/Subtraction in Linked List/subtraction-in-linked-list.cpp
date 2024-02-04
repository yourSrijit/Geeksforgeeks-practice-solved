//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   int reverse(Node* &head){
        while(head->next!=NULL && head->data==0){
            head = head->next;
        } // to manage leading zeroes
        
        Node* prev = NULL;
        Node* curr = head;
        int n = 0;
        while(curr){
            n++;
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return n; // returns size
    }
    
    Node* subtract(Node* head1, Node* head2){
        Node* prev = NULL;
        int borrow = 0; // indicates are we taking borrow from next step
        
        while(head1 && head2){
            Node* temp = new Node(0);
            int x = head1->data + borrow;
            borrow = 0;
            
            if((x-head2->data)<0){
                // if cant subtract take borrow so it becomes +10
                x += 10;
                borrow = -1;
            }
    
            temp->data = x-head2->data;
            temp->next = prev;
            prev = temp;
            head1 = head1->next;
            head2 = head2->next;
            
        }
        
        //put leftover nodes
        while(head1){
            Node* temp = new Node(0);
            temp->data = head1->data+borrow;
            borrow = 0;
            if(temp->data<0){
                temp->data += 10;
                borrow = -1;
            }
            temp->next = prev;
            prev = temp;
            head1 = head1->next;
        }
        return prev;
    }

    Node* subLinkedList(Node* head1, Node* head2) {
        
        int n1 = 0, n2 = 0;
        n1 = reverse(head1);
        n2 = reverse(head2);
        
        //storing greater number in head1 always
        if(n2>n1){
            swap(head1, head2);
        }
        else if(n1==n2){
            int cnt1 = 0, cnt2 = 0;
            Node* temp1 = head1;
            Node* temp2 = head2;
            while(temp1){
                if(temp1->data>temp2->data){
                    cnt1 = 1;
                    cnt2 = 0;
                }
                else if(temp1->data<temp2->data){
                    cnt2 = 1;
                    cnt1 = 0;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if(cnt2>cnt1) swap(head1, head2);
        }
        
        Node* ans = subtract(head1, head2);
        
        // to avoid leading zeroes
        while(ans->next!=NULL && ans->data==0) ans = ans->next;
        return ans;
        
        return NULL;
        
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends