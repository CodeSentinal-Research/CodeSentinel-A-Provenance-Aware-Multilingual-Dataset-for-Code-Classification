import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] heap = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            heap[i] = scanner.nextInt();
        }
        System.out.println(findMin(heap, n));
    }

    private static int findMin(int[] heap, int n) {
        int min = heap[1];
        for (int i = 1; i <= n; i++) {
            if (heap[i] < min) {
                min = heap[i];
            }
        }
        return min;
    }
}
