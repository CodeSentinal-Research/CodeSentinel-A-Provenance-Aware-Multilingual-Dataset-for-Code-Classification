import java.util.PriorityQueue;

public class Main {
    public static class Node {
        public int val;
        public Node prev;
        public Node next;
        public Node child;
    }

    public static Node flatten(Node head) {
        if (head == null) {
            return null;
        }

        Node current = head;
        while (current != null) {
            if (current.child != null) {
                Node next = current.next;
                Node childHead = flatten(current.child);
                current.next = childHead;
                childHead.prev = current;
                current.child = null;

                while (current.next != null) {
                    current = current.next;
                }

                current.next = next;
                if (next != null) {
                    next.prev = current;
                }
            } else {
                current = current.next;
            }
        }

        return head;
    }

    public static void main(String[] args) {
        // Test the solution
        Node list1 = new Node();
        list1.val = 1;
        Node list2 = new Node();
        list2.val = 2;
        Node list3 = new Node();
        list3.val = 3;

        list1.next = list2;
        list2.prev = list1;
        list2.next = list3;
        list3.prev = list2;

        Node result = flatten(list1);

        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
