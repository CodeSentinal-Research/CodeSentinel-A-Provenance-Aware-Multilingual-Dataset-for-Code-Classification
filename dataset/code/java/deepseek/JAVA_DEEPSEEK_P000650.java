import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        int n = scanner.nextInt();
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;
        for (int i = 1; i < size; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        System.out.println(getNthFromStart(head, n));
    }

    public static int getNthFromStart(ListNode head, int n) {
        ListNode current = head;
        for (int i = 1; current != null; i++) {
            if (i == n) {
                return current.val;
            }
            current = current.next;
        }
        return -1;
    }

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}
