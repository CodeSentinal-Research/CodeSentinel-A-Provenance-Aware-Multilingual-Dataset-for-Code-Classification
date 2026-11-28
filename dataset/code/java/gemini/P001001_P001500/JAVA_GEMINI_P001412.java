import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                map.put(x, map.getOrDefault(x, 0) + 1);
            }

            int ans = 0;
            if (k == 0) {
                for (int cnt : map.values()) {
                    if (cnt > 1) ans++;
                }
            } else {
                for (int x : map.keySet()) {
                    if (map.containsKey(x + k)) ans++;
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}