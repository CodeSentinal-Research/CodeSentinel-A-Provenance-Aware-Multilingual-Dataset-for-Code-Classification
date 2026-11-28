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
        System.out.println(maxLength(arr, K));
    }

    public static int maxLength(int[] arr, int K) {
        int start = 0, end = 0;
        int maxLength = 0;
        int negativeCount = 0;
        while (end < arr.length) {
            if (arr[end] < 0 && negativeCount < K) {
                negativeCount++;
            }
            while (negativeCount == K) {
                if (arr[start] < 0) {
                    negativeCount--;
                }
                start++;
            }
            maxLength = Math.max(maxLength, end - start + 1);
            end++;
        }
        return maxLength;
    }
}
