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
        
        ListNode[] parts = new ListNode[k];
        int len = 0;
        ListNode curr = head;
        while(curr != null) { len++; curr = curr.next; }
        
        int base = len / k;
        int extra = len % k;
        
        curr = head;
        for(int i=0; i<k; i++) {
            parts[i] = curr;
            int size = base + (extra > 0 ? 1 : 0);
            extra--;
            for(int j=0; j<size-1; j++) {
                if(curr != null) curr = curr.next;
            }
            if(curr != null) {
                ListNode next = curr.next;
                curr.next = null;
                curr = next;
            }
        }
        
        for(ListNode p : parts) {
            if(p == null) System.out.print("null ");
            else {
                ListNode c = p;
                while(c != null) {
                    System.out.print(c.val + " ");
                    c = c.next;
                }
            }
            System.out.println();
        }
    }
}
