import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode[] splitListToParts(ListNode root, int k) {
        ListNode cur = root;
        int N = 0;
        while (cur != null) {
            cur = cur.next;
            N++;
        }

        int width = N / k, remainder = N % k;

        ListNode[] result = new ListNode[k];
        cur = root;
        for (int i = 0; i < k; ++i) {
            ListNode head = cur;
            for (int j = 0; j < width + (i < remainder ? 1 : 0) - 1; ++j) {
                if (cur != null) cur = cur.next;
            }
            if (cur != null) {
                ListNode prev = cur;
                cur = cur.next;
                prev.next = null;
            }
            result[i] = head;
        }
        return result;
    }

    public static void printList(ListNode[] lists) {
        for (ListNode list : lists) {
            while (list != null) {
                System.out.print(list.val + " ");
                list = list.next;
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        ListNode root = new ListNode(scanner.nextInt());
        ListNode cur = root;
        for (int i = 1; i < n; i++) {
            cur.next = new ListNode(scanner.nextInt());
            cur = cur.next;
        }
        printList(splitListToParts(root, k));
    }
}
