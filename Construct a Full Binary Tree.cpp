class Solution{
  public:

    Node* help(int pre[], int st, int en){
        if(st==en) return new Node(pre[st]);
        Node* node = new Node(pre[st]);
        int mid = (en+(st+1))/2;
        node->left = help(pre, st+1,mid);
        node->right = help(pre, mid+1, en);
        return node;
    }
  
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        Node* node = help(pre,0,size-1);
        return node;
    }
};
