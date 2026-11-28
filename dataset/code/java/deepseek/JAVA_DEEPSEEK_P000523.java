import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode removeNodes(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode prev = null;
        ListNode curr = head;
        int max = head.val;

        while (curr != null) {
            if (curr.val >= max) {
                max = curr.val;
                prev = curr;
                curr = curr.next;
            } else {
                prev.next = curr.next;
                curr = curr.next;
           }
        }

        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;

        for (int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }

        head = removeNodes(head);

        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}
