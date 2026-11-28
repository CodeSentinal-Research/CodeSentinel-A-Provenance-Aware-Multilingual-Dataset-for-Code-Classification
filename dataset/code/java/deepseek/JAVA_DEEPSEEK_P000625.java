import java.util.*;

public class Main {
    public static class Node {
        int val;
        Node next;
        Node prev;
        Node(int x) { val = x; }
    }

    public static Node rotateRight(Node head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        Node cur = head;
        int len = 1;
        while (cur.next != null) {
            cur = cur.next;
            len++;
        }

        cur.next = head;
        head.prev = cur;

        k = k % len;
        k = len - k;

        while (k-- > 0) {
            cur = cur.next;
        }

        cur.next.prev = null;
        cur.next = null;
        return cur.next;
    }

    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        Node head = null;
        Node tail = null;

        for (int i = 0; i < n; i++) {
            Node node = new Node(scanner.nextInt());
            if (head == null) {
                head = node;
            }
            if (tail != null) {
                tail.next = node;
                node.prev = tail;
            }
            tail = node;
        }

        head = rotateRight(head, k);
        printList(head);
    }
}
