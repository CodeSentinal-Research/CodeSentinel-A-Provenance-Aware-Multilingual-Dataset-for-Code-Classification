import java.util.PriorityQueue;

class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}

public class Main {
    public static Node flatten(Node root) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.data - b.data);
        Node curr = root;
        while(curr != null) {
            pq.add(curr);
            curr = curr.bottom;
        }
        if(pq.isEmpty()) return null;
        Node head = pq.poll();
        Node tail = head;
        if(!pq.isEmpty()) tail.bottom = pq.poll();
        while(!pq.isEmpty()) {
            tail.next = pq.poll();
            tail = tail.next;
            if(tail.bottom != null) pq.add(tail.bottom);
        }
        return head;
    }

    public static void main(String[] args) {
        Node n1 = new Node(1);
        n1.bottom = new Node(3);
        n1.bottom.bottom = new Node(5);

        Node n2 = new Node(2);
        n2.bottom = new Node(4);
        n2.bottom.bottom = new Node(6);

        n1.next = n2;

        Node result = flatten(n1);
        while(result != null) {
            System.out.print(result.data + " ");
            result = result.next;
        }
    }
}
