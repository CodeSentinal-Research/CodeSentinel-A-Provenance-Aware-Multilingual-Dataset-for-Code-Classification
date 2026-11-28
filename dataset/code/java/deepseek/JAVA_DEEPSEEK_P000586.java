import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        ListNode head = new ListNode(scanner.nextInt());
        ListNode current = head;

        for (int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
       }

        ListNode result = reverseKGroup(head, k);

        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }

    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode groupPrev = dummy;
        ListNode groupNext = dummy;

        while (true) {
            for (int i = 0; i < k; i++) {
                if (groupNext.next == null) {
                    return dummy.next;
                }
                groupNext = groupNext.next;
            }

            ListNode kthNode = groupPrev.next;
            ListNode nextGroupPrev = kthNode;
            ListNode nextGroupNext = kthNode;

            for (int i = 0; i < k; i++) {
                nextGroupNext = nextGroupPrev.next;
                nextGroupPrev.next = nextGroupNext.next;
                nextGroupNext.next = kthNode;
                kthNode = nextGroupNext;
            }

            groupPrev.next = kthNode;
            groupPrev = nextGroupPrev;
            groupNext = nextGroupPrev;
        }
    }

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}
