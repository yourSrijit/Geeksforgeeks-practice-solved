package Tree_BST;

//1.Leaf Node (NO CHILD)
//2.One Child
//3.Two Child

public class Delete_Node_BST {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
        }
    }
    public static Node DeleteNode(Node root,int val){
        if (root.data > val) {
            root.left=DeleteNode(root.left,val);
        }
        else if(root.data<val){
            root.right=DeleteNode(root.right,val);
        }
        else {
//            Type 1 no child
            if(root.left==null && root.right==null){
                return null;
            }
            //Type 2 one child
            if(root.left==null){
                return root.right;
            }
            else if(root.right==null){
                return root.left;
            }
            // Type 3 Two child
            Node IS=findInorderSuccessor(root.right);
            root.data=IS.data;
            root.right=DeleteNode(root.right,root.data);
        }
        return root;
    }
    public static Node findInorderSuccessor(Node root){
        while (root.left!=null){
            root=root.left;
        }
return root;
    }
    public static void Inorder(Node root){
        if(root==null){
            return;
        }
        Inorder(root.left);
        System.out.print(root.data+" ");
        Inorder(root.right);
    }
    public static Node insert(Node root, int val){
        if(root ==null){
            root =new Node(val);
            return root;
        }
        if(root.data>val){
            root.left=insert(root.left,val);
        }
        if(root.data<val){
            root.right =insert(root.right,val);
        }
        return root;
    }
    public static void main(String[] args) {
        int values[]={5,1,3,4,2,7};
        Node root=null;
        for(int i=0;i<values.length;i++){
            root=insert(root,values[i]);
        }
        Inorder(root);
        DeleteNode(root,1);
        System.out.println("After deletion");
        Inorder(root);


    }
}
