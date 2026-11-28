import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode removeZeroSumSublists(ListNode head) {
        Deque<ListNode> stack = new ArrayDeque<>();
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        stack.push(dummy);
        int prefix = 0;
        while (!stack.isEmpty()) {
            ListNode node = stack.peek();
            if (node.next != null) {
                prefix += node.next.val;
                if (prefix == 0) {
                    stack.pop();
                    node.next = null;
                } else {
                    stack.push(node.next);
                }
                prefix = 0;
           } else {
                stack.pop();
            }
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(-3);
        head.next.next.next = new ListNode(3);
        head.next.next.next.next = new ListNode(1);

        ListNode result = removeZeroSumSublists(head);

        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }
}