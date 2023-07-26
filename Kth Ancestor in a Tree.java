class Solution
{
    int ans = -1;
    public int kthAncestor(Node root, int k, int node)
    {
        //Write your code here
        trv(root, k, node);
        return ans;
    }
    void trv(Node root, int k, int node){
        if(root == null || ans != -1)
            return;
        kans(root, root, 0, k , node);
        trv(root.left, k, node);
        trv(root.right, k, node);
        
    }
    void kans(Node root, Node n, int lvl, int k, int node){
        if(n == null || ans != -1)
            return;
        if(lvl == k && n.data == node)
            ans = root.data;
        kans(root, n.left, lvl+1, k, node);
        kans(root, n.right, lvl+1, k, node);
    }
}
