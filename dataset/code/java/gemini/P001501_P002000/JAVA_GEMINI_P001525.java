import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            Map<Integer, Integer> map = new HashMap<>();
            map.put(0, -1);
            int diff = 0, maxLen = 0;

            for (int i = 0; i < n; i++) {
                diff += (arr[i] % 2 == 0) ? 1 : -1;
                if (map.containsKey(diff)) {
                    maxLen = Math.max(maxLen, i - map.get(diff));
                } else {
                    map.put(diff, i);
                }
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}