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
        int k = sc.nextInt();
        
        if(head == null) return;
        int len = 0;
        ListNode curr = head;
        while(curr != null) { len++; curr = curr.next; }
        k %= len;
        if(k == 0) {
             curr = head;
             while(curr != null) { System.out.print(curr.val + " "); curr = curr.next; }
             return;
        }
        
        ListNode fast = head, slow = head;
        for(int i=0; i<k; i++) fast = fast.next;
        while(fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        
        ListNode newHead = slow.next;
        slow.next = null;
        fast.next = head;
        
        curr = newHead;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
