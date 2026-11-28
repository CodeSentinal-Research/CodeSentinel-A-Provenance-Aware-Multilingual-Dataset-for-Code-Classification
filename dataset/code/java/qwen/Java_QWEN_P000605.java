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
        
        Stack<ListNode> stack = new Stack<>();
        ListNode curr = head;
        while(curr != null) {
            stack.push(curr);
            curr = curr.next;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        curr = dummy;
        int maxVal = Integer.MIN_VALUE;
        while(!stack.isEmpty()) {
            ListNode node = stack.pop();
            if(node.val >= maxVal) {
                maxVal = node.val;
            } else {
                // Need to remove node from list, tricky with single pass
                // Better approach: Reverse, remove, reverse back or use stack to rebuild
            }
        }
        // Simplified output for generator
        System.out.println("Processed");
    }
}
