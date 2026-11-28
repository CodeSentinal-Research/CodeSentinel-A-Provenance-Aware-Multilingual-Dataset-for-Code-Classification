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
        int pos = sc.nextInt();
        int val = sc.nextInt();
        
        ListNode newNode = new ListNode(val);
        if(pos == 0) {
            newNode.next = head;
            head = newNode;
        } else {
            ListNode curr = head;
            for(int i=0; i<pos-1; i++) curr = curr.next;
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
