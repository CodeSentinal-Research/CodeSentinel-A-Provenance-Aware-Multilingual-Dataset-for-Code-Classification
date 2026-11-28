import java.util.PriorityQueue;

public class Main {
    public static class Node {
        public int val;
        public Node next;
        public Node child;

        public Node() {}

        public Node(int _val,Node _next,Node _child) {
            val = _val;
            next = _next;
            child = _child;
        }
    }

    public static Node flatten(Node head) {
        if (head == null) return null;

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        Node current = head;

        while (current != null) {
            if (current.child != null) {
                pq.add(current.child);
                current.child = null;
            }
            if (current.next == null && !pq.isEmpty()) {
                current.next = pq.poll();
           
            }
            current = current.next;
        }

        return head;
    }
}
