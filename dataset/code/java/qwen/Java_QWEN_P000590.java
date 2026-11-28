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
        
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode second = slow.next;
        slow.next = null;
        ListNode prev = null, curr = second;
        while(curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;
        
        ListNode first = head;
        boolean isPalin = true;
        while(second != null) {
            if(first.val != second.val) { isPalin = false; break; }
            first = first.next;
            second = second.next;
        }
        System.out.println(isPalin ? "true" : "false");
    }
}
