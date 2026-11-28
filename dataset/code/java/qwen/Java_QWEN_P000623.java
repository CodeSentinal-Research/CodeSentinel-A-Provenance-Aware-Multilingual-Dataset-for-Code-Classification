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
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        
        while(curr != null) {
            ListNode groupStart = curr;
            ListNode groupEnd = curr;
            for(int i=1; i<k; i++) {
                if(groupEnd.next != null) groupEnd = groupEnd.next;
                else break;
            }
            
            ListNode nextGroup = groupEnd.next;
            // Reverse k nodes
            ListNode prevRev = nextGroup;
            ListNode currRev = groupStart;
            while(currRev != nextGroup) {
                ListNode next = currRev.next;
                currRev.next = prevRev;
                prevRev = currRev;
                currRev = next;
            }
            
            prev.next = prevRev;
            prev = groupStart;
            curr = nextGroup;
            
            // Skip next k
            for(int i=0; i<k && curr != null; i++) {
                prev = curr;
                curr = curr.next;
            }
        }
        
        ListNode c = dummy.next;
        while(c != null) {
            System.out.print(c.val + " ");
            c = c.next;
        }
    }
}
