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

    public int detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return 0;
        }

        ListNode slow = head;
        ListNode fast = head;

        // Detect cycle
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                break;
            }
       
           // If no cycle found
           return 0;
       }

       // Count the nodes in the cycle
       int cycleLength = 1;
       fast = fast.next;
       while (slow != fast) {
           fast = fast.next;
           cycleLength++;
       }

       return cycleLength;
    }
}
