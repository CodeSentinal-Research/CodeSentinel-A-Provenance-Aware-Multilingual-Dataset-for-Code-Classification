import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long target = scanner.nextLong();
            Set<Long> set = new HashSet<>();
            for (int i = 0; i < n; i++) {
                long val = scanner.nextLong();
                long diff = target - val;
                if (set.contains(diff)) {
                    System.out.println(diff + " " + val);
                    return;
                }
                set.add(val);
            }
            System.out.println("No Pair");
        }
    }
}