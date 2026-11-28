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
        
        Map<Integer, ListNode> prefixMap = new HashMap<>();
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        prefixMap.put(0, dummy);
        
        int sum = 0;
        ListNode curr = head;
        while(curr != null) {
            sum += curr.val;
            if(prefixMap.containsKey(sum)) {
                ListNode prev = prefixMap.get(sum);
                prev.next = curr.next;
            } else {
                prefixMap.put(sum, curr);
            }
            curr = curr.next;
        }
        
        curr = dummy.next;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
