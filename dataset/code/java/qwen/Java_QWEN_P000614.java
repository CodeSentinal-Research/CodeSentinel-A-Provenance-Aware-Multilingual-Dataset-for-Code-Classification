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
        
        ListNode first = head;
        for(int i=1; i<k; i++) first = first.next;
        
        ListNode second = head;
        ListNode temp = head;
        int len = 0;
        while(temp != null) { len++; temp = temp.next; }
        for(int i=1; i<len-k+1; i++) second = second.next;
        
        int t = first.val;
        first.val = second.val;
        second.val = t;
        
        ListNode curr = head;
        while(curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
    }
}
