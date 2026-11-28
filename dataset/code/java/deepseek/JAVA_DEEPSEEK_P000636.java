import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    static class Node {
        String url;
        Node prev;
        Node next;

        Node(String url) {
            this.url = url;
        }
    }

    static Node head = null;
    static Node tail = null;
    static Node current = null;

    public static void open(String url) {
        Node node = new Node(url);
        if (head == null) {
            head = tail = node;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = node;
        }
        if (current == null) {
            current = head;
        }
    }

    public static void close(int index) {
        Node node = getNode(index);
        if (node != null) {
            if (node == head) {
                head = node.next;
                if (head != null) {
                    head.prev = null;
                }
            } else if (node == tail) {
                tail = node.prev;
                if (tail != null) {
                    tail.next = null;
                }
           
            } else {
                node.prev.next = node.next;
                node.next.prev = node.prev;
            }
            if (node == current) {
                if (current.next != null) {
                    current = current.next;
                } else if (current.prev != null) {
                    current = current.prev;
                } else {
                    current = null;
                }
            }
        }
    }

    public static void switchTab(int index) {
        current = getNode(index);
    }

    public static void moveLeft(int index) {
        Node node = getNode(index);
        if (node != null && node.prev != null) {
            if (node == head) {
                head = node.next;
                head.prev = null;
                node.next = null;
                tail.next = node;
                node.prev = tail;
                tail = node;
            } else {
                node.prev.next = node.next;
                node.next.prev = node.prev;
                node.next = node.prev;
                node.prev = node.prev.prev;
                node.prev.next = node;
            }
        }
    }

    public static void moveRight(int index) {
        Node node = getNode(index);
        if (node != null && node.next != null) {
            if (node == tail) {
                tail = node.prev;
                tail.next = null;
                node.prev = null;
                head.prev = node;
                node.next = head;
                head = node;
            } else {
                node.next.prev = node.prev;
                node.prev.next = node.next;
                node.prev = node.next;
                node.next = node.next.next;
                node.next.prev = node;
            }
        }
    }

    public static String current() {
        return current != null ? current.url : "";
    }

    public static Node getNode(int index) {
        Node node = head;
        while (index-- > 0 && node != null) {
            node = node.next;
        }
        return node;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        scanner.nextLine();
        while (q-- > 0) {
            String operation = scanner.next();
            switch (operation) {
                case "open":
                    open(scanner.next());
                    break;
                case "close":
                    close(scanner.nextInt());
                    break;
                case "switch":
                    switchTab(scanner.nextInt());
                    break;
                case "moveLeft":
                    moveLeft(scanner.nextInt());
                    break;
                case "moveRight":
                    moveRight(scanner.nextInt());
                    break;
                case "current":
                    System.out.println(current());
                    break;
            }
        }
    }
}
