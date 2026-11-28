import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode head = new ListNode(0);
        ListNode cur = head;
        for (int i = 1; i <= n; i++) {
            cur.next = new ListNode(scanner.nextInt());
            cur = cur.next;
        }
        int left = scanner.nextInt();
        int right = scanner.nextInt();
        head = reverseBetween(head.next, left, right);
        while (head != null) {
            System.out.println(head.val);
            head = head.next;
        }
    }

    public static ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null)
            return null;

        ListNode cur = head, prev = null;
        while (left > 1) {
            prev = cur;
            cur = cur.next;
            left--;
            right--;
        }

        ListNode con = prev, tail = cur;
        while (right > 0) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
            right--;
       }

        if (con != null)
            con.next = prev;
        else
            head = prev;
        tail.next = cur;

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
