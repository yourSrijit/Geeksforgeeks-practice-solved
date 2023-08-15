package Tree_BST;

public class IsValid_Bst {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
        }
    }
    public static boolean isValid(Node root,Node max,Node min){
        if(root==null){
            return true;
        }

        if(max!=null && root.data>=max.data){
            return false;
        }
        else if(min!=null && root.data<=min.data){
            return false;
        }
        return isValid(root.left,root,min) && isValid(root.right,max,root);
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
        int values[]={8,5,3,6,10,11,14};
        Node root=null;
        for(int i=0;i<values.length;i++){
            root=insert(root,values[i]);
        }
        if(isValid(root,null,null)){
            System.out.println("IS VALID");
        }
        else {
            System.out.println("IS NOT VALID");
        }

    }
}
