import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;
        for (int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        head = partition(head, x);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static ListNode partition(ListNode head, int x) {
        ListNode lessHead = new ListNode(0);
        ListNode moreHead = new ListNode(0);
        ListNode less = lessHead;
        ListNode more = moreHead;
        while (head != null) {
            if (head.val < x) {
                less.next = head;
                less = less.next;
            } else {
                more.next = head;
                more = more.next;
            }
            head = head.next;
        }
        more.next = null; // to avoid cycle
        less.next = moreHead.next; // concatenate two lists
        return lessHead.next;
    }

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }
}
