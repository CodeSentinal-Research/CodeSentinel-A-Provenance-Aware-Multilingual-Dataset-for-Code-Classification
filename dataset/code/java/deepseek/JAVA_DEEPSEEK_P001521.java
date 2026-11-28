import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(maxChunksToSorted(arr));
    }

    public static int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int[] max = new int[n];
        int[] min = new int[n];
        max[0] = arr[0];
        min[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) {
            max[i] = Math.max(max[i - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            min[i] = Math.min(min[i + 1], arr[i]);
        }
        int chunks = 0;
        for (int i = 0; i < n - 1; i++) {
            if (max[i] == min[i + 1]) {
                chunks++;
            }
        }
        return chunks + 1;
    }
}
