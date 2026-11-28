import java.util.Scanner;

public class Main {
    public static class Node {
        int val;
        Node next;
        Node prev;
        Node(int x) { val = x; }
    }

    public static Node reversePairs(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        Node prev = null;
        Node curr = head;
        while (curr != null && curr.next != null) {
            Node nextNode = curr.next.next;
            Node second = curr.next;
            second.next = curr;
            curr.next = prev;
            curr.prev = second;
            second.prev = null;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    public static void printList(Node node) {
        while (node != null) {
            System.out.println(node.val);
            node = node.next;
        }
    }

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
                tail = node;
            } else {
                tail.next = node;
                node.prev = tail;
                tail = node;
            }
        }
        head = reversePairs(head);
        printList(head);
    }
}
