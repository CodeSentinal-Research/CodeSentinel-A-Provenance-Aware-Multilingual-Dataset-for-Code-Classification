import java.util.PriorityQueue;

class Node {
    int val;
    Node next;
    Node bottom;

    Node(int val) {
        this.val = val;
        next = null;
        bottom = null;
    }
}

public class Main {
    public static Node flatten(Node head) {
        PriorityQueue<Node> queue = new PriorityQueue<>((a, b) -> a.val - b.val);
        Node current = head;

        while (current != null) {
            queue.add(current);
            current = current.next;
        }

        if (queue.isEmpty()) {
            return null;
        }

        Node dummy = new Node(0);
        Node tail = dummy;

        while (!queue.isEmpty()) {
            Node smallest = queue.poll();
            if (smallest.bottom != null) {
                queue.add(smallest.bottom);
            }
            tail.bottom = smallest;
            tail = smallest;
        }

        return dummy.bottom;
    }

    public static void main(String[] args) {
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);
        Node node5 = new Node(5);
        Node node6 = new Node(6);

        node1.next = node2;
        node2.next = node3;
        node2.bottom = node4;
        node3.bottom = node5;
        node4.bottom = node6;

        Node flattened = flatten(node1);
        while (flattened != null) {
            System.out.print(flattened.val + " ");
            flattened = flattened.bottom;
        }
    }
}
