import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextLong();

            Map<Long, Integer> map = new HashMap<>();
            map.put(0L, -1);
            long prefix = 0;
            int maxLen = 0;

            for (int i = 0; i < n; i++) {
                prefix += arr[i];
                if (map.containsKey(prefix - k)) {
                    maxLen = Math.max(maxLen, i - map.get(prefix - k));
                }
                if (!map.containsKey(prefix)) {
                    map.put(prefix, i);
                }
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}