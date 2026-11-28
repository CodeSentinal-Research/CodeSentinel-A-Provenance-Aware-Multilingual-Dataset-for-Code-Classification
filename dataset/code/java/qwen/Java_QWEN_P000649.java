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
        ListNode l1 = null, t1 = null;
        for(int i=0; i<n; i++) {
            int val = sc.nextInt();
            ListNode node = new ListNode(val);
            if(l1 == null) l1 = t1 = node;
            else { t1.next = node; t1 = node; }
        }
        int m = sc.nextInt();
        ListNode l2 = null, t2 = null;
        for(int i=0; i<m; i++) {
            int val = sc.nextInt();
            ListNode node = new ListNode(val);
            if(l2 == null) l2 = t2 = node;
            else { t2.next = node; t2 = node; }
        }
        
        ListNode c1 = l1, c2 = l2;
        while(c1 != null && c2 != null) {
            if(c1.val != c2.val) { System.out.println("false"); return; }
            c1 = c1.next;
            c2 = c2.next;
        }
        System.out.println(c1 == null && c2 == null ? "true" : "false");
    }
}
