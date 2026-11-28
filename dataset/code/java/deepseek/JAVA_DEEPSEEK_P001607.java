import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(findLongestSubarray(arr));
    }

    private static int findLongestSubarray(int[] arr) {
        int n = arr.length;
        int[] prefixSum = new int[n + 1];
        int maxLength = 0;
        int currLength = 0;
        int currZeroCount = 0;
        int currOneCount = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                currZeroCount++;
            } else {
                currOneCount++;
            }
            prefixSum[i + 1] = prefixSum[i] + (arr[i] == 0 ? -1 : 1);
            if (prefixSum[i + 1] == 0) {
                maxLength = Math.max(maxLength, i + 1);
                currLength = Math.max(currLength, i - (currZeroCount > 0 ? currZeroCount - 1 : 0));
            }
        }

        return Math.max(maxLength, currLength);
    }
}
