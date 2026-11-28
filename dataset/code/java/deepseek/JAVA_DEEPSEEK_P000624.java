import java.util.Scanner;

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
        head = segregateEvenOdd(head);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static ListNode segregateEvenOdd(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;
        while (even != null && odd != null) {
            odd.next = even.next;
            if (even.next != null) {
                even.next = even.next.next;
            }
            odd = odd.next;
            if (even.next != null) {
                even = even.next;
            }
        }
        odd = head;
        while (odd.next != null) {
            odd = odd.next;
        }
        odd.next = evenHead;
        return head;
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
