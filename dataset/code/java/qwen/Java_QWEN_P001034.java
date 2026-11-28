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
            if(n > 0) {
                ListNode head = new ListNode(sc.nextInt());
                ListNode curr = head;
                for(int j=1; j<n; j++) {
                    curr.next = new ListNode(sc.nextInt());
                    curr = curr.next;
                }
                pq.offer(head);
            }
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
