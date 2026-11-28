import java.util.*;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode deleteNodes(ListNode head, int M, int N) {
        ListNode current = head;
        while (current != null) {
            for (int i = 1; i < M && current != null; i++) {
                current = current.next;
            }
            ListNode temp = current;
            for (int i = 0; i <= N && temp != null; i++) {
                temp = temp.next;
            }
            if (current != null) {
                current.next = temp;
            }
            current = current.next;
        }
        return head;
    }

    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;
        for (int i = 1; i < size; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        int M = scanner.nextInt();
        int N = scanner.nextInt();
        head = deleteNodes(head, M, N);
        printList(head);
    }
}
