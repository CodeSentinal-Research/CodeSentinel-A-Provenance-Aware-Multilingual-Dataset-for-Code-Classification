import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node head = null;
        Node tail = null;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int value = scanner.nextInt();
            if (head == null) {
                head = new Node(value);
                tail = head;
            } else {
                tail.next = new Node(value);
                tail = tail.next;
           
               max = Math.max(max, head.value + tail.value);
               head = head.next;
               tail = tail.next;
            }
        }
        System.out.println(max);
    }

    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }
}
