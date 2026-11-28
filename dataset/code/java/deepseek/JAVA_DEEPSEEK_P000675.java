import java.util.*;

public class Main {
    class Node {
        public int val;
        public Node prev;
        public Node next;
        public Node child;
    };

    public Node flatten(Node head) {
        if (head == null) {
            return null;
        }

        Node current = head;
        while (current != null) {
            if (current.child != null) {
                Node next = current.next;
                Node childHead = flatten(current.child);
                current.child = null;

                current.next = childHead;
                childHead.prev = current;

                Node tail = childHead;
                while (tail.next != null) {
                    tail = tail.next;
                }

                tail.next = next;
                if (next != null) {
                    next.prev = tail;
               }

                return head;
            }
            current = current.next;
        }

        return head;
    }
}
