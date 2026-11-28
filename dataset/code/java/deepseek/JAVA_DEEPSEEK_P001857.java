import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            queue.offer(scanner.nextInt());
        }
        boolean isValid = true;
        for (int i = 0; i < n; i++) {
            if (queue.poll() != i + 1) {
                isValid = false;
                break;
           }
        }
        System.out.println(isValid ? "YES" : "NO");
    }
}
