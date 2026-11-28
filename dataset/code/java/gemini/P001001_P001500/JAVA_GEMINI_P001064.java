import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), m = sc.nextInt();
            Set<String> set = new HashSet<>();
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                set.add(Math.min(u, v) + "," + Math.max(u, v));
            }
            int qu = sc.nextInt(), qv = sc.nextInt();
            System.out.println(set.contains(Math.min(qu, qv) + "," + Math.max(qu, qv)) ? "YES" : "NO");
        }
        sc.close();
    }
}