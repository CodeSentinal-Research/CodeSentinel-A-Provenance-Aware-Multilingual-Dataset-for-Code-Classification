import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] heap = new int[n];
        for (int i = 0; i < n; i++) {
            heap[i] = scanner.nextInt();
        }
        scanner.close();
        long sum = 0;
        for (int i : heap) {
            sum += i;
        }
        System.out.println(sum);
    }
}
