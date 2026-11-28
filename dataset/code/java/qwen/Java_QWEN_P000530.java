import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int capacity = sc.nextInt();
        int q = sc.nextInt();
        int[] queue = new int[capacity];
        int front = 0, rear = 0, size = 0;
        
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("enQueue")) {
                int val = sc.nextInt();
                if(size < capacity) {
                    queue[rear] = val;
                    rear = (rear + 1) % capacity;
                    size++;
                }
            } else if(op.equals("deQueue")) {
                if(size > 0) {
                    System.out.println(queue[front]);
                    front = (front + 1) % capacity;
                    size--;
                } else {
                    System.out.println("Empty");
                }
            } else if(op.equals("Front")) {
                if(size > 0) System.out.println(queue[front]);
                else System.out.println("Empty");
            } else if(op.equals("Rear")) {
                if(size > 0) System.out.println(queue[(rear - 1 + capacity) % capacity]);
                else System.out.println("Empty");
            } else if(op.equals("isEmpty")) {
                System.out.println(size == 0 ? "true" : "false");
            } else if(op.equals("isFull")) {
                System.out.println(size == capacity ? "true" : "false");
            }
        }
    }
}
