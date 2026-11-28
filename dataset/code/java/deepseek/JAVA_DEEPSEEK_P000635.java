import java.io.*;
import java.util.*;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode cur = head;
        int count = 0;
        while (cur != null && count != k) {
            cur = cur.next;
            count++;
        }
        if (count == k) {
            cur = reverseKGroup(cur, k);
            while (count-- > 0) {
                ListNode tmp = head.next;
                head.next = cur;
                cur = head;
                head = tmp;
            }
            head = cur;
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int g = scanner.nextInt();
        ListNode head = new ListNode(scanner.nextInt());
        ListNode cur = head;
        for (int i = 1; i < n; i++) {
            cur.next = new ListNode(scanner.nextInt());
            cur = cur.next;
        }
        head = reverseKGroup(head, g);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}
