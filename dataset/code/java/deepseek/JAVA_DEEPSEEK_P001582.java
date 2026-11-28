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
        System.out.println(maxSubarray(arr, K));
    }

    public static int maxSubarray(int[] arr, int k) {
        int maxLength = 0;
        int left = 0;
        int right = 0;
        int zeroCount = 0;
        int[] count = new int[arr.length];
        while (right < arr.length) {
            if (arr[right] == 0) {
                zeroCount++;
            }
            count[arr[right]]++;
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                count[arr[left]]--;
                left++;
            }
            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
}
