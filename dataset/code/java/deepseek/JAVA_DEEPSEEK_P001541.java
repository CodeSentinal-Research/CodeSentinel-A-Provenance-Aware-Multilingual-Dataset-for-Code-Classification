import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        long maxSum = 0;
        long currentSum = 0;
        for (int i = 0; i < k; i++) {
            maxSum += arr[i];
        }
        currentSum = maxSum;
        for (int i = k; i < n; i++) {
            currentSum = currentSum - arr[i - k] + arr[i];
            maxSum = Math.max(maxSum, currentSum);
        }
        System.out.println(maxSum);
    }
}
