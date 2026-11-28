import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
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
        int target = scanner.nextInt();
        System.out.println(search(head, target));
    }

    public static boolean search(ListNode head, int target) {
        while (head != null) {
            if (head.val == target) {
                return true;
            }
            head = head.next;
        }
        return false;
    }
}
