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
        
        ListNode curr = head;
        while(curr.next.next != null) curr = curr.next;
        ListNode last = curr.next;
        curr.next = null;
        last.next = head;
        head = last;
        
        curr = head;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
