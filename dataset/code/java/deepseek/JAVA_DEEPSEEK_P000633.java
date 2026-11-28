import java.util.*;

public class Main {
    class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                return slow;
            }
       }

        return null;
    }

    public ListNode removeLoop(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode meetingPoint = detectCycle(head);
        if (meetingPoint == null) {
            return head;
        }

        ListNode p1 = head;
        ListNode p2 = meetingPoint;

        while (p1 != p2) {
            p1 = p1.next;
            p2 = p2.next;
        }

        while (p2.next != p1) {
            p2 = p2.next;
        }

        p2.next = null;

        return head;
    }
}
