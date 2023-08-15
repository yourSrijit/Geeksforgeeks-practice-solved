package Tree_BST;
public class Binar_serach_tree_Delete_Node {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
        }
    }
    public static Node insert(Node root,int val){
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
    public static void Inorder(Node root){
        if(root ==null){
            return;
        }
        Inorder(root.left);
        System.out.print(root.data+" ");
        Inorder(root.right);
    }
    public static boolean search(Node root ,int key){  //O(H)
        if(root ==null){
            return false;
        }
        if(root.data==key){
            return true;
        }
        if(root.data >key){
            return search(root.left,key);
        }
        else {
            return search(root.right ,key);
        }
    }
    public static Node delete(Node root,int val){
        if(root.data>val){
            root.left=delete(root.left,val);
        }
        else if(root.data<val){
            root.right=delete(root.right,val);
        }
        else{
            //case 1: leaf child
            if(root.left==null && root.right==null){
                return null;
            }
            //case 2:One child
            if(root.left==null){
                return root.right;
            }
            else if(root.right==null){
                return root.left;
            }
            // case 3: Two child
            Node IS= findInorderSuccessor(root.right);
            root.data=IS.data;
            root.right=delete(root.right,IS.data);
        }
        return root;
    }
    public static Node findInorderSuccessor(Node root){
        while(root.left!=null){
            root=root.left;
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
//        if (search(root,5)){
//            System.out.println("Found");
//        }else {
//            System.out.println("Not found");
//        }
        delete(root,3);
        System.out.println("After delete a noode");
        Inorder(root);
    }
}

