import java.util.*;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode insertAtPosition(ListNode head, int position, int value) {
        ListNode newNode = new ListNode(value);
        if (position == 0) {
            newNode.next = head;
            return newNode;
        }
        ListNode current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current.next == null) {
                return head;
            }
            current = current.next;
       }
        newNode.next = current.next;
        current.next = newNode;
        return head;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode head = null;
        ListNode tail = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            if (head == null) {
                head = new ListNode(val);
                tail = head;
            } else {
                tail.next = new ListNode(val);
                tail = tail.next;
            }
        }
        int position = scanner.nextInt();
        int value = scanner.nextInt();
        head = insertAtPosition(head, position, value);
        printList(head);
    }
}
