import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n1 = scanner.nextInt();
        int n2 = scanner.nextInt();

        ListNode l1 = new ListNode(0);
        ListNode l2 = new ListNode(0);
        ListNode curr = l1;
        while (n1 > 0) {
            curr.next = new ListNode(n1 % 10);
            curr = curr.next;
            n1 /= 10;
        }
        curr = l2;
        while (n2 > 0) {
            curr.next = new ListNode(n2 % 10);
            curr = curr.next;
            n2 /= 10;
       }

        ListNode result = addTwoNumbers(l1.next, l2.next);
        while (result != null) {
            System.out.print(result.val);
            result = result.next;
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode current = result;
        int carry = 0;
        while (l1 != null || l2 != null || carry > 0) {
            int sum = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry;
            carry = sum / 10;
            current.next = new ListNode(sum % 10);
            current = current.next;
            l1 = l1 != null ? l1.next : null;
            l2 = l2 != null ? l2.next : null;
        }
        return result.next;
    }

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}
