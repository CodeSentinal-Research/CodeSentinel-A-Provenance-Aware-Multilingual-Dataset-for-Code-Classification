import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        next = null;
    }
}

public class Main {
    static Node josephus(int n, int k) {
        Node head = new Node(1);
        Node current = head;

        for (int i = 2; i <= n; i++) {
            current.next = new Node(i);
            current = current.next;
        }
        current.next = head;

        while (head.next != head) {
            for (int i = 1; i < k; i++) {
                head = head.next;
            }
            head.next = head.next.next;
        }
        return head;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        Node survivor = josephus(n, k);
        System.out.println(survivor.data);
    }
}
