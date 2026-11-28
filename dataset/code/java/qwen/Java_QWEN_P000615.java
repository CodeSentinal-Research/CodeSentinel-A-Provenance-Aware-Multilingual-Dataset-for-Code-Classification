import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ListNode head = null, tail = null;
        for(int i=0; i<n; i++) {
            int val = sc.nextInt();
            ListNode node = new ListNode(val);
            if(head == null) head = tail = node;
            else { tail.next = node; tail = node; }
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prevGroupEnd = dummy;
        ListNode curr = head;
        int groupSize = 1;
        
        while(curr != null) {
            int count = 0;
            ListNode start = curr;
            ListNode end = curr;
            while(end != null && count < groupSize) {
                end = end.next;
                count++;
            }
            
            if(count == groupSize && count % 2 == 0) {
                // Reverse
                ListNode prev = end;
                ListNode node = start;
                for(int i=0; i<count; i++) {
                    ListNode next = node.next;
                    node.next = prev;
                    prev = node;
                    node = next;
                }
                prevGroupEnd.next = prev;
                prevGroupEnd = start;
            } else {
                prevGroupEnd = end == null ? findLast(start) : getPrev(start, end);
                // Actually just move prevGroupEnd to last node of this group
                ListNode last = start;
                for(int i=1; i<count; i++) last = last.next;
                prevGroupEnd = last;
            }
            curr = end;
            groupSize++;
        }
        
        ListNode c = dummy.next;
        while(c != null) {
            System.out.print(c.val + " ");
            c = c.next;
        }
    }
    static ListNode findLast(ListNode head) {
        while(head.next != null) head = head.next;
        return head;
    }
    static ListNode getPrev(ListNode start, ListNode end) {
        ListNode c = start;
        while(c.next != end) c = c.next;
        return c;
    }
}
