import java.util.Scanner;

class Node {
    int val;
    Node next;
    Node prev;
    Node(int x) {
        val = x;
        next = null;
        prev = null;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        Node head = null;
        Node tail = null;
        for (int i = 0; i < n; i++) {
            Node node = new Node(scanner.nextInt());
            if (head == null) {
                head = node;
            }
            if (tail != null) {
                tail.next = node;
                node.prev = tail;
           
            }
            tail = node;
        }
        head = reverseKGroup(head, k);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static Node reverseKGroup(Node head, int k) {
        Node curr = head;
        int count = 0;
        while (curr != null && count != k) {
            curr = curr.next;
            count += 1;
        }
        if (count == k) {
            curr = reverseKGroup(curr, k);
            while (count-- > 0) {
                Node tmp = head.next;
                head.next = curr;
                curr = head;
                head = tmp;
            }
            head = curr;
        }
        return head;
    }
}
