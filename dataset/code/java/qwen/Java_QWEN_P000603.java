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
        int x = sc.nextInt();
        
        ListNode dummyLess = new ListNode(0), lessTail = dummyLess;
        ListNode dummyMore = new ListNode(0), moreTail = dummyMore;
        ListNode curr = head;
        while(curr != null) {
            if(curr.val < x) {
                lessTail.next = curr;
                lessTail = curr;
            } else {
                moreTail.next = curr;
                moreTail = curr;
            }
            curr = curr.next;
        }
        lessTail.next = dummyMore.next;
        moreTail.next = null;
        
        curr = dummyLess.next;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
