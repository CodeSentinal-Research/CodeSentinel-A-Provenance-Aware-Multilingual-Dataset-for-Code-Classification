import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode head = new ListNode(0);
        ListNode current = head;
        for (int i = 1; i <= n; i++) {
            current.next = new ListNode(i);
            current = current.next;
        }
        head = deleteAlternateNodes(head.next);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static ListNode deleteAlternateNodes(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode prev = head;
        ListNode current = head.next;
        while (current != null) {
            prev.next = current.next;
            prev = current;
            if (current.next != null) {
                current = current.next.next;
            } else {
                current = null;
            }
        }
        return head;
    }
}
