import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        long result = countSubarrays(arr, k);
        System.out.println(result);
    }

    public static long countSubarrays(long[] arr, long k) {
        long count = 0;
        long sum = 0;
        Map<Long, Long> map = new HashMap<>();
        map.put(0L, 1L);
        for (long num : arr) {
            sum += num;
            long remainder = sum % k;
            if (remainder < 0) {
                remainder += k;
            }
            count += map.getOrDefault(remainder, 0L);
            map.put(remainder, map.getOrDefault(remainder, 0L) + 1);
        }
        return count;
    }
}
