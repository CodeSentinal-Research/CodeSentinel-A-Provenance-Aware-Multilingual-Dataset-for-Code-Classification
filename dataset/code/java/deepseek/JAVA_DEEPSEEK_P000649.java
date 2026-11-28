import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
    }

    public static boolean isIdentical(ListNode headA, ListNode headB) {
        while (headA != null && headB != null) {
            if (headA.val != headB.val) {
                return false;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return headA == null && headB == null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode headA = new ListNode(scanner.nextInt());
        ListNode current = headA;
        for (int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        int m = scanner.nextInt();
        ListNode headB = new ListNode(scanner.nextInt());
        current = headB;
        for (int i = 1; i < m; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        System.out.println(isIdentical(headA, headB) ? "true" : "false");
    }
}
