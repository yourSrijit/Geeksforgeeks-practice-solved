package Tree_BST;

public class PrintInrange {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
        }
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
    public static void printInrange(Node root,int n1,int n2){
        if(root==null){
            return;
        }
        if(n1>root.data && n2>root.data){
            printInrange(root.right,n1,n2);
        }
        else if(n1<root.data && n2< root.data){
            printInrange(root.left,n1,n2);
        }
        else {
            // when n1<= root.data <=n2
            printInrange(root.left,n1,n2);
            System.out.print(root.data + " ");
            printInrange(root.right,n1,n2);
        }
    }
    public static void main(String[] args) {
        int values[]={8,5,3,1,4,6,10,11,14};
      Node root=null;
        for(int i=0;i<values.length;i++){
            root=insert(root,values[i]);
        }
        printInrange(root,5,12);

    }
}
