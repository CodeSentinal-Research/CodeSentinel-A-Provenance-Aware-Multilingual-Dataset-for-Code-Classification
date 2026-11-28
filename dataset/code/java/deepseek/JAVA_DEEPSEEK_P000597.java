public class Main {
    public static class Node {
        public int val;
        public Node prev;
        public Node next;
        public Node child;
    }

    public static Node flatten(Node head) {
        Node current = head;
        while (current != null) {
            if (current.child != null) {
                Node next = current.next;
                current.next = flatten(current.child);
                current.next.prev = current;
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
}
