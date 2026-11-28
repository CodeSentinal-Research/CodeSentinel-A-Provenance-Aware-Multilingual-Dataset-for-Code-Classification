import java.util.*;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode groupPrev = dummy;
        while (true) {
            ListNode kth = getKth(groupPrev, k);
            if (kth == null) {
                break;
            }
            ListNode nextGroupPrev = groupPrev.next;
            reverse(groupPrev, groupPrev.next, kth);
            groupPrev = nextGroupPrev;
        }
        return dummy.next;
    }

    private static ListNode getKth(ListNode start, int k) {
        ListNode current = start;
        while (k > 0 && current != null) {
            current = current.next;
            k--;
        }
        return current;
    }

    private static void reverse(ListNode start, ListNode end, ListNode kth) {
        ListNode prev = start;
        ListNode curr = start.next;
        while (curr != end) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        start.next = kth;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        int k = 2;
        ListNode result = reverseKGroup(head, k);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
