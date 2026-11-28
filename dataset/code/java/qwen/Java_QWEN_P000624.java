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
        
        ListNode evenHead = new ListNode(0), evenTail = evenHead;
        ListNode oddHead = new ListNode(0), oddTail = oddHead;
        ListNode curr = head;
        while(curr != null) {
            if(curr.val % 2 == 0) {
                evenTail.next = curr;
                evenTail = curr;
            } else {
                oddTail.next = curr;
                oddTail = curr;
            }
            curr = curr.next;
        }
        evenTail.next = oddHead.next;
        oddTail.next = null;
        
        curr = evenHead.next;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
