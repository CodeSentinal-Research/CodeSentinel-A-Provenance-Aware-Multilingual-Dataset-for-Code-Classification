import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        int q = scanner.nextInt();
        MyCircularQueue circularQueue = new MyCircularQueue(capacity);
        while (q-- > 0) {
            String operation = scanner.next();
            switch (operation) {
                case "enQueue":
                    int value = scanner.nextInt();
                    System.out.println(circularQueue.enQueue(value));
                    break;
                case "deQueue":
                    System.out.println(circularQueue.deQueue());
                    break;
                case "Front":
                    System.out.println(circularQueue.Front());
                    break;
                case "Rear":
                    System.out.println(circularQueue.Rear());
                    break;
                case "isEmpty":
                    System.out.println(circularQueue.isEmpty());
                    break;
                case "isFull":
                    System.out.println(circularQueue.isFull());
                    break;
            }
        }
    }
}

class MyCircularQueue {
    private int[] queue;
    private int headIndex;
    private int count;
    private int capacity;

    public MyCircularQueue(int k) {
        this.capacity = k;
        this.queue = new int[k];
        this.headIndex = 0;
        this.count = 0;
    }

    public boolean enQueue(int value) {
        if (this.count == this.capacity)
            return false;
        this.queue[(this.headIndex + this.count) % this.capacity] = value;
        this.count += 1;
        return true;
    }

    public boolean deQueue() {
        if (this.count == 0)
            return false;
        this.headIndex = (this.headIndex + 1) % this.capacity;
        this.count -= 1;
        return true;
    }

    public int Front() {
        if (this.count == 0)
            return -1;
        return this.queue[this.headIndex];
    }

    public int Rear() {
        if (this.count == 0)
            return -1;
        int rearIndex = (this.headIndex + this.count - 1) % this.capacity;
        return this.queue[rearIndex];
    }

    public boolean isEmpty() {
        return (this.count == 0);
    }

    public boolean isFull() {
        return (this.count == this.capacity);
    }
}
