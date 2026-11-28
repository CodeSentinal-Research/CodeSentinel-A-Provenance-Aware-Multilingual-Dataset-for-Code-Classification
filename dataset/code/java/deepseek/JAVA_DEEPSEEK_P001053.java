import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        PriorityQueue<Integer> queue = new PriorityQueue<>();

        while (q-- > 0) {
            String operation = scanner.next();
            if (operation.equals("I")) {
                int val = scanner.nextInt();
                queue.add(val);
            } else if (operation.equals("R")) {
                if (!queue.isEmpty()) {
                    System.out.println(queue.poll());
                } else {
                    System.out.println("Underflow");
                }
            }
        }
    }
}
