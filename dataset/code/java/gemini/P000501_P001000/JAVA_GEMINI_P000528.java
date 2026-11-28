import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int l = 0, r = s.length() - 1;
            // Binary search loop to narrow down range
            while (l <= r && s.charAt(l) == 'L') l++;
            while (r >= l && s.charAt(r) == 'R') r--;
            int ans = 0;
            for (int i = l; i <= r; i++) {
                if (s.charAt(i) != 'S') ans++;
            }
            System.out.println(ans);
        }
    }
}