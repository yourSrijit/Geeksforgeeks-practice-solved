class Solution{
    //Function to return list containing elements of right view of binary tree.
    ArrayList<Integer> rightView(Node node) {

        Queue<Node> que=new LinkedList<>();//Declare a " Queue" of "Node" type.   
        ArrayList<Integer> arr=new ArrayList<Integer>();//Declare ArrayList to store the answer
        
        que.add(node);//Add the node
        que.add(null);//Add the "null" value
        while(que.peek()!=null)//while loop to check end of tree
        {
            while(que.peek()!=null)// while loop to traverse a level completely. 
            {
                Node n=que.remove();
                //Insert the left and then right node of the current Node "n" if not null
                if(n.left!=null)
                que.add(n.left);
                if(n.right!=null)
                {
                que.add(n.right);
                }
                //check if the current node in the Queue is null 
                //if so then add "n.data" into the ArrayList
                if(que.peek()==null)
                {
                    arr.add(n.data);
                }
                
            }
            // After the complete traversal remove the null node from the front and add a null node at the rear. 
            if(que.peek()==null)
            {
                que.remove();
                que.add(null);
            }
        }
        return arr;
        
    }
}
