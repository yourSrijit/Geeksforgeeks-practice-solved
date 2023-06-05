  int minDiff(Node *root, int K)
    {
        return !root?K:min(abs(root->data-K),(root->data>K)?minDiff(root->left,K):minDiff(root->right,K));
    }
