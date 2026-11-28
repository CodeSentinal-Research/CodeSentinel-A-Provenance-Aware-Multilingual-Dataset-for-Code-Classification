import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(minOperations(arr, n, x));
    }

    public static int minOperations(int[] arr, int n, int x) {
        int left = 0;
        int right = n - 1;
        int operations = 0;
        int sum = 0;
        while (left <= right) {
            if (sum + arr[left] <= x) {
                sum += arr[left];
                left++;
            } else if (sum + arr[right] <= x) {
                sum += arr[right];
                right--;
            } else {
                return -1;
            }
            operations++;
        }
        return operations;
    }
}
