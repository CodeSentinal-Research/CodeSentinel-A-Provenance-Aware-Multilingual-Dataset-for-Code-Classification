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
        int nth = sc.nextInt();
        
        ListNode curr = head;
        for(int i=1; i<nth; i++) {
            if(curr == null) { System.out.println(-1); return; }
            curr = curr.next;
        }
        System.out.println(curr == null ? -1 : curr.val);
    }
}
