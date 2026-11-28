import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode head = new ListNode(0);
        ListNode cur = head;
        for (int i = 0; i < n; i++) {
            cur.next = new ListNode(scanner.nextInt());
            cur = cur.next;
        }
        deleteDuplicates(head.next);
        while (head.next != null) {
            System.out.println(head.next.val);
            head = head.next;
        }
    }

    public static ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode current = head;
        while (current.next != null) {
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
           }
        }
        return head;
    }

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}
