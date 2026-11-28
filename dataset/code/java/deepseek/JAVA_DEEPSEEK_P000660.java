import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = null;
        Node tail = null;
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            Node newNode = new Node(value);
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }
        System.out.println(findMax(head));
    }

    public static int findMax(Node head) {
        if (head == null) {
            return -1;
        }
        int max = head.value;
        while (head != null) {
            if (head.value > max) {
                max = head.value;
            }
            head = head.next;
        }
        return max;
    }

    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }
}
