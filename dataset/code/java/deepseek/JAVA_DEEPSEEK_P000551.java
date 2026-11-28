import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        Queue<String> queue = new LinkedList<>();
        queue.add("1");

        for (int i = 1; i <= n; i++) {
            String binary = queue.poll();
            System.out.print(binary + " ");

            String binary1 = binary + "0";
            String binary2 = binary + "1";

            queue.add(binary1);
            queue.add(binary2);
        }
    }
}
