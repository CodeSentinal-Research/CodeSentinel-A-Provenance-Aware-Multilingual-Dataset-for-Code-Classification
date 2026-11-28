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
        ListNode prev = dummy;
        ListNode curr = head;
        
        while(curr != null && curr.next != null) {
            ListNode first = curr;
            ListNode second = curr.next;
            
            first.next = second.next;
            second.next = first;
            prev.next = second;
            
            prev = first;
            curr = first.next;
        }
        
        ListNode c = dummy.next;
        while(c != null) {
            System.out.print(c.val + " ");
            c = c.next;
        }
    }
}
