import java.util.Scanner;

public class Main {
    public static class Node {
        int val;
        Node next;
        Node(int x) {
            val = x;
            next = null;
        }
    }

    public Node mergeTwoLists(Node l1, Node l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        if (l1.val > l2.val) {
            Node temp = l1;
            l1 = l2;
            l2 = temp;
        }

        Node head = l1;
        while (l1 != null && l2 != null) {
            Node l1Next = l1.next;
            Node l2Next = l2.next;

            if (l1.val <= l2.val && (l1Next == null || l1Next.val >= l2.val)) {
                l1.next = l2;
                l2.next = l1Next;
                l1 = l1Next;
            } else {
                l1 = l1Next;
            }

            if (l1 != null && l2.val > l1.val) {
                l1 = l1.next;
            }
        }

        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        Node l1 = new Node(scanner.nextInt());
        Node head1 = l1;
        for (int i = 1; i < n; i++) {
            l1.next = new Node(scanner.nextInt());
            l1 = l1.next;
        }
        l1.next = head1;

        Node l2 = new Node(scanner.nextInt());
        Node head2 = l2;
        for (int i = 1; i < m; i++) {
            l2.next = new Node(scanner.nextInt());
            l2 = l2.next;
        }
        l2.next = head2;

        Node result = new Main().mergeTwoLists(head1, head2);
        Node temp = result;
        do {
            System.out.print(temp.val + " ");
            temp = temp.next;
        } while (temp != result);
    }
}
