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
        int value = scanner.nextInt();
        head = deleteNode(head, value);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static ListNode deleteNode(ListNode head, int value) {
        if (head == null) {
            return null;
        }
        if (head.val == value) {
            return head.next;
        }
        ListNode current = head;
        while (current.next != null) {
            if (current.next.val == value) {
                current.next = current.next.next;
                return head;
            }
            current = current.next;
        }
        return head;
    }
}
