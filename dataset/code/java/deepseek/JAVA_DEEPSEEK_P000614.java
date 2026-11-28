import java.util.*;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static ListNode swapNodes(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;
        ListNode end = dummy;

        // Move first pointer k nodes ahead
        for(int i=0; i<=k; i++){
            if(first.next == null) return head;
            first = first.next;
        }

        // Move first and second pointers together until the end
        while(first != null){
            first = first.next;
            second = second.next;
        }

        // Swap values
        int temp = second.val;
        second.val = end.val;
        end.val = temp;

        return dummy.next;
    }

    public static void printList(ListNode head) {
        while(head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        int k = 2;
        ListNode result = swapNodes(head, k);
        printList(result);
    }
}
