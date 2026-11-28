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
        
        Map<Integer, Integer> counts = new HashMap<>();
        ListNode curr = head;
        while(curr != null) {
            counts.put(curr.val, counts.getOrDefault(curr.val, 0) + 1);
            curr = curr.next;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        curr = dummy;
        while(curr.next != null) {
            if(counts.get(curr.next.val) > 1) curr.next = curr.next.next;
            else curr = curr.next;
        }
        
        curr = dummy.next;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
