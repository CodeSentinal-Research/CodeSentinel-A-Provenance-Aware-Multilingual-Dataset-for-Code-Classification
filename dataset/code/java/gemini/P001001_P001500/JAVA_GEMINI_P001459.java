import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < n; i++) set.add(sc.nextInt());

            int i = 1;
            // Shrink window from the left while duplicate element exists
            while (set.contains(i)) i++;
            System.out.println(i);
        }
        sc.close();
    }
}