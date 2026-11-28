import java.io.*;
import java.util.*;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode reverseEvenPos(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode prev = null;
        ListNode curr = head;
        ListNode next = null;
        int pos = 0;

        while (curr != null) {
            next = curr.next;
            if (pos % 2 == 0) {
                curr.next = prev;
                prev = curr;
           curr = next;
            } else {
                curr = next;
            }
            pos++;
        }

        return prev;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        ListNode result = reverseEvenPos(head);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}
