import java.util.Scanner;

public class Main {
    public static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }

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
        System.out.println(findMinimum(head));
    }

    public static int findMinimum(Node head) {
        if (head == null) {
            return -1;
        }
        int min = head.value;
        while (head != null) {
            if (head.value < min) {
                min = head.value;
            }
            head = head.next;
        }
        return min;
    }
}
