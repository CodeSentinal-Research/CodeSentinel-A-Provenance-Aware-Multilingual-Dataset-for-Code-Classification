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
        
        if(head == null) { System.out.println(-1); return; }
        int min = head.val;
        ListNode curr = head.next;
        while(curr != null) {
            if(curr.val < min) min = curr.val;
            curr = curr.next;
        }
        System.out.println(min);
    }
}
