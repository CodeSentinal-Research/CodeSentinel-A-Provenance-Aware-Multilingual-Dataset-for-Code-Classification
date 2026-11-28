import java.io.*;

class Node {
    public int val;
    public Node next;
    public Node() {}
    public Node(int _val,Node _next) {
        val = _val;
        next = _next;
    }
}

public class Main {
    public static Node insert(Node head, int insertVal) {
        if (head == null) {
            Node newNode = new Node(insertVal, null);
            newNode.next = newNode;
            return newNode;
        }

        Node curr = head;
        while(true){
            if(curr.val <= insertVal && insertVal <= curr.next.val){
                break;
            }
            if(curr.val > curr.next.val){
                if(insertVal >= curr.val || insertVal <= curr.next.val){
                    break;
                }
           
               curr = curr.next;
            }
        }
        curr.next = new Node(insertVal, curr.next);
        return head;
    }

    public static void main(String[] args) {
        // Test the function
        Node head = new Node(3, null);
        head.next = new Node(4, null);
        head.next.next = new Node(1, null);
        head.next.next.next = head;
        insert(head, 2);
    }
}
