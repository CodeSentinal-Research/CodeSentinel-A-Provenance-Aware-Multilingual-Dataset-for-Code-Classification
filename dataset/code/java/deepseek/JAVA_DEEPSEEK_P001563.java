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

    private static int longestSubarray(int[] arr, int limit) {
        int left = 0, right = 0;
        int maxLength = 0;
        int[] prefixSum = new int[arr.length + 1];
        for (int i = 0; i < arr.length; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }
        while (right < arr.length) {
            if (prefixSum[right + 1] - prefixSum[left] > limit) {
                left++;
            } else {
                maxLength = Math.max(maxLength, right - left + 1);
                right++;
            }
        }
        return maxLength;
    }
}
