import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Difference = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(longestSubsequence(arr, N, Difference));
    }

    public static int longestSubsequence(int[] arr, int N, int Difference) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxLength = 0;
        for (int i = 0; i < N; i++) {
            int num = arr[i];
            if (map.containsKey(num - Difference)) {
                int length = map.get(num - Difference);
                map.put(num, length + 1);
            } else {
                map.put(num, 1);
            }
            maxLength = Math.max(maxLength, map.get(num));
        }
        return maxLength;
    }
}
