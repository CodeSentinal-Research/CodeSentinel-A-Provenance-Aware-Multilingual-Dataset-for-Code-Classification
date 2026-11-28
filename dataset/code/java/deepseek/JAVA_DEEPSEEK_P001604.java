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
        System.out.println(countSubarrays(arr, n, k));
    }

    public static long countSubarrays(long[] arr, int n, long k) {
        long count = 0;
        long sum = 0;
        Map<Long, Long> map = new HashMap<>();
        map.put(0L, 1L);
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (map.containsKey(sum - k)) {
                count += map.get(sum - k);
            }
            map.put(sum, map.getOrDefault(sum, 0L) + 1);
        }
        return count;
    }
}
