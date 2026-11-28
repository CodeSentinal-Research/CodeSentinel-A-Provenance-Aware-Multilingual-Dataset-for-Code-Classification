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
        ListNode curr = head;
        ListNode resHead = dummy;
        
        while(curr != null) {
            int sum = 0;
            while(curr.next != null && curr.next.val != 0) {
                sum += curr.next.val;
                curr = curr.next;
            }
            if(curr.next != null) {
                resHead.next = new ListNode(sum);
                resHead = resHead.next;
                curr = curr.next;
            } else {
                break;
            }
        }
        
        ListNode c = dummy.next;
        while(c != null) {
            System.out.print(c.val + " ");
            c = c.next;
        }
    }
}
