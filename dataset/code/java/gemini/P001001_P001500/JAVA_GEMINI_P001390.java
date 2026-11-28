import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            Map<Long, Integer> map = new HashMap<>();
            map.put(0L, -1);
            long prefix = 0;
            int maxLen = 0;

            for (int i = 0; i < n; i++) {
                prefix += arr[i];
                if (map.containsKey(prefix)) {
                    maxLen = Math.max(maxLen, i - map.get(prefix));
                } else {
                    map.put(prefix, i);
                }
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}