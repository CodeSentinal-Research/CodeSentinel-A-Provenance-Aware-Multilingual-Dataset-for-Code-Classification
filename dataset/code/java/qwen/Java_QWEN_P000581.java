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
        ListNode l1 = null, t1 = null;
        for(int i=0; i<n; i++) {
            int val = sc.nextInt();
            ListNode node = new ListNode(val);
            if(l1 == null) l1 = t1 = node;
            else { t1.next = node; t1 = node; }
        }
        int m = sc.nextInt();
        ListNode l2 = null, t2 = null;
        for(int i=0; i<m; i++) {
            int val = sc.nextInt();
            ListNode node = new ListNode(val);
            if(l2 == null) l2 = t2 = node;
            else { t2.next = node; t2 = node; }
        }
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) { curr.next = l1; l1 = l1.next; }
            else { curr.next = l2; l2 = l2.next; }
            curr = curr.next;
        }
        if(l1 != null) curr.next = l1;
        if(l2 != null) curr.next = l2;
        
        curr = dummy.next;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
