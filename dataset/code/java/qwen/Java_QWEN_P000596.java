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
        
        if(head == null || head.next == null) {
             ListNode curr = head;
             while(curr != null) { System.out.print(curr.val + " "); curr = curr.next; }
             return;
        }
        
        // Merge Sort
        ListNode mid = getMid(head);
        ListNode right = mid.next;
        mid.next = null;
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(right);
        ListNode merged = merge(l1, l2);
        
        ListNode curr = merged;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
    static ListNode getMid(ListNode head) {
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    static ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode mid = getMid(head);
        ListNode right = mid.next;
        mid.next = null;
        return merge(sortList(head), sortList(right));
    }
    static ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) { curr.next = l1; l1 = l1.next; }
            else { curr.next = l2; l2 = l2.next; }
            curr = curr.next;
        }
        if(l1 != null) curr.next = l1;
        if(l2 != null) curr.next = l2;
        return dummy.next;
    }
}
