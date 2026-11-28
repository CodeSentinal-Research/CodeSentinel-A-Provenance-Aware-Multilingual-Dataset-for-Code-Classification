import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int limit = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(longestSubarray(arr, limit));
    }

    public static int longestSubarray(int[] arr, int limit) {
        int left = 0, right = 0;
        int maxLength = 0;
        int[] prefixSum = new int[arr.length + 1];
        prefixSum[0] = 0;
        for (int i = 1; i <= arr.length; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }
        for (int leftIndex = 0; leftIndex < arr.length; leftIndex++) {
            for (int rightIndex = leftIndex + 1; rightIndex <= arr.length; rightIndex++) {
                int sum = prefixSum[rightIndex] - prefixSum[leftIndex];
                if (Math.abs(sum) <= limit) {
                    maxLength = Math.max(maxLength, rightIndex - leftIndex);
                }
            }
        }
        return maxLength;
    }
}
