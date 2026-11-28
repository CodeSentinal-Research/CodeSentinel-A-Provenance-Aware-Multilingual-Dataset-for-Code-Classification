import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        int q = scanner.nextInt();
        Queue queue = new Queue(capacity);
        for (int i = 0; i < q; i++) {
            String operation = scanner.next();
            if (operation.equals("enqueue")) {
                int x = scanner.nextInt();
                queue.enqueue(x);
            } else if (operation.equals("dequeue")) {
                System.out.println(queue.dequeue());
            } else if (operation.equals("front")) {
                System.out.println(queue.front());
            } else if (operation.equals("isEmpty")) {
                System.out.println(queue.isEmpty());
            }
        }
    }
}

class Queue {
    private int[] array;
    private int head;
    private int tail;

    public Queue(int capacity) {
        array = new int[capacity];
        head = 0;
        tail = 0;
    }

    public void enqueue(int x) {
        if (tail < array.length) {
            array[tail++] = x;
        }
    }

    public int dequeue() {
        if (head < tail) {
            return array[head++];
        }
        return -1;
    }

    public int front() {
        if (head < tail) {
            return array[head];
        }
        return -1;
    }

    public boolean isEmpty() {
        return head == tail;
    }
}
