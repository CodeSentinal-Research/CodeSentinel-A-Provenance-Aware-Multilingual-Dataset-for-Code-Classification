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
        
        ListNode curr = head;
        ListNode prev = null;
        int count = 0;
        while(curr != null && count < k) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(head != null) head.next = curr;
        
        curr = prev;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
