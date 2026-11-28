import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        Arrays.sort(arr);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i < n - 1; i++) {
            minDiff = Math.min(minDiff, Math.abs(arr[i + 1] - arr[i]));
        }
        for (int i = 0; i < n - 1; i++) {
            if (Math.abs(arr[i + 1] - arr[i]) == minDiff) {
                System.out.println(arr[i] + " " + arr[i + 1]);
            }
        }
    }
}
