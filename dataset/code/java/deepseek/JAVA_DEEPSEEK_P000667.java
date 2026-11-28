import java.util.Scanner;

class Node {
    int val;
    Node next;
    Node prev;
    Node(int val) {
        this.val = val;
    }
}

class MyCircularDeque {
    int size;
    int capacity;
    Node head;
    Node tail;

    public MyCircularDeque(int k) {
        capacity = k;
        head = null;
        tail = null;
    }

    public boolean insertFront(int value) {
        if (size == capacity) return false;
        Node node = new Node(value);
        if (size == 0) {
            head = tail = node;
        } else {
            node.next = head;
            head.prev = node;
            head = node;
            tail.next = head;
        }
        size++;
        return true;
    }

    public boolean insertLast(int value) {
        if (size == capacity) return false;
        Node node = new Node(value);
        if (size == 0) {
            head = tail = node;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = node;
            head.prev = tail;
        }
        size++;
        return true;
    }

    public boolean deleteFront() {
        if (size == 0) return false;
        head = head.next;
        tail.next = head;
        size--;
        return true;
    }

    public boolean deleteLast() {
        if (size == 0) return false;
        tail = tail.prev;
        head.prev = tail;
        size--;
        return true;
    }

    public int getFront() {
        return size == 0 ? -1 : head.val;
    }

    public int getRear() {
        return size == 0 ? -1 : tail.val;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        MyCircularDeque deque = new MyCircularDeque(n);
        while (scanner.hasNext()) {
            String operation = scanner.next();
            switch (operation) {
                case "insertFront" -> {
                    int value = scanner.nextInt();
                    System.out.println(deque.insertFront(value));
                }
                case "insertLast" -> {
                    int value = scanner.nextInt();
                    System.out.println(deque.insertLast(value));
                }
                case "deleteFront" -> System.out.println(deque.deleteFront());
                case "deleteLast" -> System.out.println(deque.deleteLast());
                case "getFront" -> System.out.println(deque.getFront());
                case "getRear" -> System.out.println(deque.getRear());
                case "isEmpty" -> System.out.println(deque.isEmpty());
                case "size" -> System.out.println(deque.size());
            }
        }
    }
}
