import java.util.Scanner;

public class Main {
    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    static int countNodes(Node n) {
        int count = 0;
        while (n != null) {
            count++;
            n = n.next;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node head = null;
        Node tail = null;
        while (n-- > 0) {
            int val = sc.nextInt();
            Node node = new Node(val);
            if (head == null) {
                head = node;
            } else {
                tail.next = node;
            }
            tail = node;
        }
        System.out.println(countNodes(head));
    }
}
