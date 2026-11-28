import java.util.Scanner;

public class Main {
    public static class Node {
        int val;
        Node next;
        Node prev;
        Node(int x) { val = x; }
    }

    public static Node reverse(Node head) {
        Node current = head;
        Node temp = null;

        while(current != null) {
            temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current = current.prev;
        }

        return temp.next;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = null;
        Node tail = null;

        for(int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            Node node = new Node(val);

            if(head == null) {
                head = node;
                tail = node;
            } else {
                tail.next = node;
                node.prev = tail;
                tail = node;
            }
        }

        head = reverse(head);

        Node current = head;
        while(current != null) {
            System.out.println(current.val);
            current = current.next;
        }
    }
}
