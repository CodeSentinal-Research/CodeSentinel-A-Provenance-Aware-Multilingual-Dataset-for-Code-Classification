import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            Map<Integer, Integer> map = new HashMap<>();
            map.put(0, 1);
            int prefix = 0;
            long ans = 0;

            for (int i = 0; i < n; i++) {
                prefix ^= sc.nextInt();
                ans += map.getOrDefault(prefix, 0);
                map.put(prefix, map.getOrDefault(prefix, 0) + 1);
            }
            System.out.println(ans);
        }
        sc.close();
    }
}