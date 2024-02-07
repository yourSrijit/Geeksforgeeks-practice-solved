//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if (root==nullptr || root == p || root == q) return root;
        Node* left = lowestCommonAncestor(root->left, p, q);
        Node* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr and right!=nullptr) return right;
        else if (right == nullptr and left!=nullptr) return left;
        else if (right != nullptr and left != nullptr) return root;
        else return nullptr;
    }
    Node* dfs(Node*root, int a){
        if (root == nullptr or root->data == a) return root;
        Node *left = dfs(root->left, a);
        Node *right = dfs(root->right, a);
        if (left!=nullptr) return left;
        else if (right!=nullptr) return right;
        else return nullptr;
    }
    void dis(Node *root, Node *node, int &ans, bool &ok){
        if (root==node) {ok=true; return;}
        ans++;
        if (root->left!=nullptr)dis(root->left, node, ans, ok);
        if (!ok){
            if (root->right!=nullptr)dis(root->right, node, ans, ok);
        }
        if (!ok) ans--;
    }
    int findDist(Node* root, int a, int b) {
        Node* p = dfs(root, a);
        Node *q = dfs(root, b);
        Node* lca = lowestCommonAncestor(root, p, q);
        int ans=0; bool ok=false;
        dis(lca, p, ans, ok); 
        int ans1=0;
        ok=false; 
        dis(lca, q, ans1, ok); 
        ans+=ans1;
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends