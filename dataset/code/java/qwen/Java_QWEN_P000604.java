import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Forward order addition
        ListNode l1 = new ListNode(7); l1.next = new ListNode(2); l1.next.next = new ListNode(4); l1.next.next.next = new ListNode(3);
        ListNode l2 = new ListNode(5); l2.next = new ListNode(6); l2.next.next = new ListNode(4);
        
        Stack<Integer> s1 = new Stack<>(), s2 = new Stack<>();
        ListNode c1 = l1, c2 = l2;
        while(c1 != null) { s1.push(c1.val); c1 = c1.next; }
        while(c2 != null) { s2.push(c2.val); c2 = c2.next; }
        
        ListNode head = null;
        int carry = 0;
        while(!s1.isEmpty() || !s2.isEmpty() || carry > 0) {
            int sum = carry;
            if(!s1.isEmpty()) sum += s1.pop();
            if(!s2.isEmpty()) sum += s2.pop();
            ListNode node = new ListNode(sum % 10);
            node.next = head;
            head = node;
            carry = sum / 10;
        }
        
        ListNode curr = head;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
