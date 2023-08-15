package Tree_BST;

import java.util.ArrayList;

public class RoottoLeaf {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
        }
    }
public static void PrintRootToLeaf(Node root, ArrayList<Integer> path){
        if(root==null){
            return;
        }
        path.add(root.data);
        if(root.left==null && root.right==null){
            for(int a: path){
                System.out.print(a+" ");
            }
            System.out.println();
        }
        PrintRootToLeaf(root.left,path);
        PrintRootToLeaf(root.right,path);
        path.remove(path.size()-1);

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
        int values[]={8,5,3,1,4,6,10,11,14};
        Node root=null;
        for(int i=0;i<values.length;i++){
            root=insert(root,values[i]);
        }
        ArrayList<Integer> path=new ArrayList<>();
        PrintRootToLeaf(root,path);

    }
}

