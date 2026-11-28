import java.util.Scanner;

public class Main {
    public static class Node {
        int val;
        Node next;
        Node(int val) {
            this.val = val;
        }
    }

    public static Node mergeNodes(Node head) {
        Node current = head;
        int sum = 0;
        while (current != null) {
            if (current.val == 0 && sum != 0) {
                current.val = sum;
                sum = 0;
            } else if (current.val != 0) {
                sum += current.val;
            }
            if (current.next == null || current.next.val == 0) {
                current.next = null;
            }
            current = current.next;
        }
        return head;
    }

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = new Node(0);
        Node current = head;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            if (val != 0) {
                current.next = new Node(val);
                current = current.next;
            }
        }
        current.next = new Node(0);
        head = mergeNodes(head.next);
        printList(head);
    }
}
