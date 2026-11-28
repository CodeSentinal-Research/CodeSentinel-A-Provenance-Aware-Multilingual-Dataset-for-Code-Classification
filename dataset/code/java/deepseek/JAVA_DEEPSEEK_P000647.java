import java.util.Scanner;

public class Main {
    static class Node {
        String data;
        Node prev;
        Node next;

        Node(String data) {
            this.data = data;
            prev = null;
            next = null;
        }
    }

    static Node head = null;
    static Node tail = null;
    static Node current = null;

    public static void addSong(String title) {
        Node newNode = new Node(title);
        if (head == null) {
            head = newNode;
            tail = newNode;
            current = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public static void removeSong(String title) {
        Node temp = head;
        while (temp != null) {
            if (temp.data.equals(title)) {
                if (temp.prev != null)
                    temp.prev.next = temp.next;
                if (temp.next != null)
                    temp.next.prev = temp.prev;
                if (temp == head)
                    head = temp.next;
                if (temp == tail)
                    tail = temp.prev;
                return;
            }
            temp = temp.next;
        }
    }

    public static void playNext() {
        if (current.next != null) {
            current = current.next;
            System.out.println(current.data);
        }
    }

    public static void playPrevious() {
        if (current.prev != null) {
            current = current.prev;
            System.out.println(current.data);
        }
    }

    public static void moveSong(String title, int position) {
        Node temp = head;
        while (temp != null) {
            if (temp.data.equals(title)) {
                if (temp.prev != null)
                    temp.prev.next = temp.next;
                if (temp.next != null)
                    temp.next.prev = temp.prev;
                if (position == 0) {
                    temp.next = head;
                    head.prev = temp;
                    head = temp;
                } else {
                    Node temp2 = head;
                    for (int i = 0; i < position - 1; i++) {
                        temp2 = temp2.next;
                    }
                    temp.next = temp2.next;
                    temp2.next = temp;
                    temp.prev = temp2;
                    if (temp.next != null)
                        temp.next.prev = temp;
                }
                return;
            }
            temp = temp.next;
        }
    }

    public static void currentSong() {
        System.out.println(current.data);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < q; i++) {
            String operation = scanner.next();
            switch (operation) {
                case "addSong":
                    addSong(scanner.next());
                    break;
                case "removeSong":
                    removeSong(scanner.next());
                    break;
                case "playNext":
                    playNext();
                    break;
                case "playPrevious":
                    playPrevious();
                    break;
                case "moveSong":
                    moveSong(scanner.next(), scanner.nextInt());
                    break;
                case "currentSong":
                    currentSong();
                    break;
            }
        }
    }
}
