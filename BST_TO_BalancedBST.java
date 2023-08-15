package Tree_BST;

import java.nio.channels.InterruptedByTimeoutException;
import java.util.ArrayList;

public class BST_TO_BalancedBST {
    public static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
            left=null;
            right=null;
        }
    }
    public static void Preorder(Node root){
        if(root==null){
            return;
        }
        System.out.print(root.data+" ");
        Preorder(root.left);
        Preorder(root.right);
    }
    public static void getInorder(Node root,ArrayList<Integer> arr){
        if(root==null){
            return;
        }
        getInorder(root.left,arr);
        arr.add(root.data);
        getInorder(root.right,arr);
    }
    public static Node createBST(ArrayList<Integer> arr,int start,int end){
        if(start>end){
            return null;
        }
        int mid=(start+end)/2;
        Node root=new Node(arr.get(mid));
        root.left=createBST(arr,start,mid-1);
        root.right=createBST(arr,mid+1,end);
        return root;
    }
    public static Node balanceBST(Node root){
        ArrayList<Integer> arr=new ArrayList<>();
        // Inorder
        getInorder(root,arr);
//        System.out.println(arr);
        int start=0;
        int end=arr.size()-1;
        return createBST(arr,start,end);
    }
    public static void main(String[] args) {
        Node root=new Node(8);
        root.left=new Node(5);
        root.left.left=new Node(3);
        root.left.right=new Node(6);

        root.right=new Node(11);
        root.right.left=new Node(10);
        root.right.right=new Node(12);


        Node result=balanceBST(root);
        Preorder(result);
    }
}
