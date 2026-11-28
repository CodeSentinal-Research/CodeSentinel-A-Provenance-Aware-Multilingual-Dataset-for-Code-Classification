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
        int left = sc.nextInt();
        int right = sc.nextInt();
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        for(int i=1; i<left; i++) prev = prev.next;
        
        ListNode curr = prev.next;
        ListNode next = curr.next;
        for(int i=0; i<right-left; i++) {
            curr.next = next.next;
            next.next = prev.next;
            prev.next = next;
            next = curr.next;
        }
        
        ListNode c = dummy.next;
        while(c != null) {
            System.out.print(c.val + " ");
            c = c.next;
        }
    }
}
