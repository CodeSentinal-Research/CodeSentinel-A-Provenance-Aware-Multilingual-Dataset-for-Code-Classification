import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long target = scanner.nextLong();
            Map<Long, Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                long val = scanner.nextLong();
                long diff = target - val;
                if (map.containsKey(diff)) {
                    System.out.println(map.get(diff) + " " + i);
                    return;
                }
                map.put(val, i);
            }
        }
    }
}