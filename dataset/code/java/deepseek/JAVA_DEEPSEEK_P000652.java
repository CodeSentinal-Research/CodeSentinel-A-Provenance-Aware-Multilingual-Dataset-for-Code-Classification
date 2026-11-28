import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode insert(ListNode head, int value) {
        ListNode newNode = new ListNode(value);
        if (head == null || head.val >= newNode.val) {
            newNode.next = head;
            return newNode;
        } else {
            ListNode current = head;
            while (current.next != null && current.next.val < newNode.val) {
                current = current.next;
            }
            newNode.next = current.next;
            current.next = newNode;
       }
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
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            head = insert(head, value);
        }
        int insertValue = scanner.nextInt();
        head = insert(head, insertValue);
        printList(head);
    }
}
