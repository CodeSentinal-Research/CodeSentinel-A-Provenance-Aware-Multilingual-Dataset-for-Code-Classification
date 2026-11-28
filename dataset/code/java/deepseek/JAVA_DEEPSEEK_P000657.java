import java.util.Scanner;

class Node {
    int val;
    Node next;
    Node prev;
    Node(int val) {
        this.val = val;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = null;
        Node tail = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            Node node = new Node(val);
            if (head == null) {
                head = node;
            } else {
                tail.next = node;
                node.prev = tail;
           }
            tail = node;
        }
        head = sort(head);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    private static Node sort(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        Node slow = head;
        Node fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        Node secondHalf = slow.next;
        slow.next = null;
        return merge(sort(head), sort(secondHalf));
    }

    private static Node merge(Node a, Node b) {
        if (a == null) {
            return b;
        }
        if (b == null) {
            return a;
        }
        if (a.val < b.val) {
            a.next = merge(a.next, b);
            a.next.prev = a;
            return a;
        } else {
            b.next = merge(a, b.next);
            b.next.prev = b;
            return b;
        }
    }
}
