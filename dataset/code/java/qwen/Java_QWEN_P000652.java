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
        int val = sc.nextInt();
        
        ListNode newNode = new ListNode(val);
        if(head == null || head.val >= val) {
            newNode.next = head;
            head = newNode;
        } else {
            ListNode curr = head;
            while(curr.next != null && curr.next.val < val) curr = curr.next;
            newNode.next = curr.next;
            curr.next = newNode;
        }
        
        ListNode c = head;
        while(c != null) {
            System.out.print(c.val + " ");
            c = c.next;
        }
    }
}
