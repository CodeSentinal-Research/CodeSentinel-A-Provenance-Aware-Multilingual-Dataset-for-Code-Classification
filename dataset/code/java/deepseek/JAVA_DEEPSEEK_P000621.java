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
        int threshold = scanner.nextInt();

        ListNode head = null;
        ListNode tail = null;
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            if (head == null) {
                head = new ListNode(value);
                tail = head;
            } else {
                tail.next = new ListNode(value);
                tail = tail.next;
            }
        }

        head = removeElements(head, threshold);

        for (ListNode node = head; node != null; node = node.next) {
            System.out.print(node.val + " ");
        }
    }

    public static ListNode removeElements(ListNode head, int threshold) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        while (curr != null) {
            if (curr.val > threshold) {
                prev.next = curr.next;
           } else {
                prev = curr;
            }
            curr = curr.next;
        }
        return dummy.next;
    }
}
