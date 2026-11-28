import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Set<Long> set = new HashSet<>();
            for (int i = 0; i < n; i++) set.add(scanner.nextLong());
            long val = 1;
            // Shrink window from the left while duplicate element exists
            while (set.contains(val)) val++;
            System.out.println(val);
        }
    }
}