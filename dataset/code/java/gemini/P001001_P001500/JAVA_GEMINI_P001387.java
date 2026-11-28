import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                map.put(x, map.getOrDefault(x, 0) + 1);
            }
            boolean equal = true;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (!map.containsKey(x) || map.get(x) == 0) {
                    equal = false;
                } else {
                    map.put(x, map.get(x) - 1);
                }
            }
            System.out.println(equal ? 1 : 0);
        }
        sc.close();
    }
}