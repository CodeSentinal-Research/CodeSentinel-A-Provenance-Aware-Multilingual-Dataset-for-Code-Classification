import java.util.Scanner;

public class Main {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;

        ListNode a = headA;
        ListNode b = headB;

        while(a != b){
            a = a == null ? headB : a.next;
            b = b == null ? headA : b.next;
        }

        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ListNode headA = new ListNode(scanner.nextInt());
        ListNode current = headA;
        for(int i = 1; i < n; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
       		current.next = null;
        }
        int m = scanner.nextInt();
        ListNode headB = new ListNode(scanner.nextInt());
        current = headB;
        for(int i = 1; i < m; i++) {
            current.next = new ListNode(scanner.nextInt());
            current = current.next;
        }
        current.next = null;
        ListNode intersection = getIntersectionNode(headA, headB);
        if(intersection == null) {
            System.out.println("null");
        } else {
            System.out.println(intersection.val);
        }
    }
}