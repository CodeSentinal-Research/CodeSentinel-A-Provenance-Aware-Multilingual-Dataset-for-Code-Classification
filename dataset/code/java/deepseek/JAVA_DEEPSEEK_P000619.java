import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode deleteMiddle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head, fast = head, prev = null;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = slow.next;
        return head;
    }

    public static void printList(ListNode node) {
        while (node != null) {
            System.out.println(node.val);
            node = node.next;
        }
    }

    public static ListNode buildList(int n) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        for (int i = 1; i <= n; i++) {
            curr.next = new ListNode(i);
            curr = curr.next;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode head = buildList(n);
        head = deleteMiddle(head);
        printList(head);
    }
}
