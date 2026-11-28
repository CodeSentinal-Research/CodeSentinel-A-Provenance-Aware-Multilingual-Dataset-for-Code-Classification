import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy;

        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        if(l1 != null) prev.next = l1;
        if(l2 != null) prev.next = l2;

        return dummy.next;
    }

    public static void printList(ListNode node) {
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode l1 = new ListNode(0);
        ListNode l1Head = l1;
        for (int i = 0; i < n; i++) {
            l1.next = new ListNode(scanner.nextInt());
            l1 = l1.next;
        }

        int m = scanner.nextInt();
        ListNode l2 = new ListNode(0);
        ListNode l2Head = l2;
        for (int i = 0; i < m; i++) {
            l2.next = new ListNode(scanner.nextInt());
            l2 = l2.next;
        }

        ListNode result = mergeTwoLists(l1Head.next, l2Head.next);
        printList(result);
    }
}
