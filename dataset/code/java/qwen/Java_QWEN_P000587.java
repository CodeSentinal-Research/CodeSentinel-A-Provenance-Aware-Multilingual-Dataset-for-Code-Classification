import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        for(int i=0; i<k; i++) {
            int n = sc.nextInt();
            ListNode head = null, tail = null;
            for(int j=0; j<n; j++) {
                int val = sc.nextInt();
                ListNode node = new ListNode(val);
                if(head == null) head = tail = node;
                else { tail.next = node; tail = node; }
            }
            if(head != null) pq.offer(head);
        }
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while(!pq.isEmpty()) {
            ListNode node = pq.poll();
            curr.next = node;
            curr = curr.next;
            if(node.next != null) pq.offer(node.next);
        }
        
        curr = dummy.next;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
