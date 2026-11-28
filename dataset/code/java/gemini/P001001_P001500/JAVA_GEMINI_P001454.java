import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            Set<String> set = new HashSet<>();
            int n = s.length();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    set.add(s.substring(i, j));
                }
            }
            System.out.println(set.size() + 1);
        }
        sc.close();
    }
}