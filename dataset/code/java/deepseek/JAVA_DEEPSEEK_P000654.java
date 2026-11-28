import java.util.Scanner;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;
        for (int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        partition(head, scanner.nextInt());
    }

    public static ListNode partition(ListNode head, int x) {
        ListNode lessHead = new ListNode(0), moreHead = new ListNode(0);
        ListNode less = lessHead, more = moreHead;
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
        more.next = null;
        less.next = moreHead.next;
        return lessHead.next;
    }
}
