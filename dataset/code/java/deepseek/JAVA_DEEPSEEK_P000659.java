import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            next = null;
        }
    }

    static void printReverse(Node head) {
        if (head == null)
            return;
        printReverse(head.next);
        System.out.println(head.data);
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
        printReverse(head);
    }
}
