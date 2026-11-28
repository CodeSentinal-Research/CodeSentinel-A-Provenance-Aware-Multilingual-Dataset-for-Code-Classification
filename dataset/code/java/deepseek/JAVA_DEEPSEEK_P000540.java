import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Queue {
    Node front, rear;
    int size;

    Queue() {
        this.front = this.rear = null;
        this.size = 0;
    }

    void enqueue(int data) {
        Node newNode = new Node(data);
        if (this.rear == null) {
            this.front = this.rear = newNode;
        } else {
            this.rear.next = newNode;
            this.rear = newNode;
        }
        this.size++;
    }

    int dequeue() {
        if (this.front == null) {
            return -1;
        }
        Node temp = this.front;
        this.front = this.front.next;
        if (this.front == null) {
            this.rear = null;
        }
        this.size--;
        return temp.data;
    }

    int front() {
        if (this.front == null) {
            return -1;
        }
        return this.front.data;
    }

    int size() {
        return this.size;
    }

    boolean isEmpty() {
        return this.size == 0;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        Queue queue = new Queue();
        while (q-- > 0) {
            String operation = scanner.next();
            switch (operation) {
                case "enqueue":
                    int data = scanner.nextInt();
                    queue.enqueue(data);
                    break;
                case "dequeue":
                    System.out.println(queue.dequeue());
                    break;
                case "front":
                    System.out.println(queue.front());
                    break;
                case "size":
                    System.out.println(queue.size());
                    break;
                case "isEmpty":
                    System.out.println(queue.isEmpty());
                    break;
            }
        }
    }
}
