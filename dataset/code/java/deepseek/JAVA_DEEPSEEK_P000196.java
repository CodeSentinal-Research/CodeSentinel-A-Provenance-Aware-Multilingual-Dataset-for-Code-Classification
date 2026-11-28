import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
       
        }
        System.out.println(maxSum(arr, n, k));
    }

    static int maxSum(int arr[], int n, int k) {
        if (n < k) {
            System.out.println("Invalid");
            return -1;
        }
        int max_sum = 0;
        for (int i = 0; i < k; i++)
            max_sum += arr[i];
        int window_sum = max_sum;
        for (int i = k; i < n; i++) {
            window_sum = window_sum - arr[i - k] + arr[i];
            max_sum = Math.max(max_sum, window_sum);
        }
        return max_sum;
    }
}
