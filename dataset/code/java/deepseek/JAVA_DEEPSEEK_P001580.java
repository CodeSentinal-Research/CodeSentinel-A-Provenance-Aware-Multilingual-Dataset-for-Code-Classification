import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(longestSubarray(arr, K));
    }

    private static int longestSubarray(int[] arr, int k) {
        int start = 0, end = 0, maxLen = 0;
        int oddCount = 0;
        while (end < arr.length) {
            if (arr[end] % 2 == 1) {
                oddCount++;
            }
            while (oddCount > k) {
                if (arr[start] % 2 == 1) {
                    oddCount--;
                }
                start++;
            }
            maxLen = Math.max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
}
