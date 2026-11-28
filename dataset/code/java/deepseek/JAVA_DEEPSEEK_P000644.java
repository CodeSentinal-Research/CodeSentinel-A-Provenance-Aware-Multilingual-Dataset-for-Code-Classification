import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode swapNodes(ListNode head, int x, int y) {
        ListNode prevX = null, nodeX = head;
        ListNode prevY = null, nodeY = head;

        while (nodeX != null && nodeX.val != x) {
            prevX = nodeX;
            nodeX = nodeX.next;
        }

        while (nodeY != null && nodeY.val != y) {
            prevY = nodeY;
            nodeY = nodeY.next;
        }

        if (nodeX == null || nodeY == null) {
            return head;
        }

        if (prevX != null) {
            prevX.next = nodeY;
        } else {
            head = nodeY;
        }

        if (prevY != null) {
            prevY.next = nodeX;
        } else {
            head = nodeX;
        }

        ListNode temp = nodeX.next;
        nodeX.next = nodeY.next;
        nodeY.next = temp;

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
        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;
        for (int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        head = swapNodes(head, x, y);
        printList(head);
    }
}
