import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int target = scanner.nextInt();
            int idx = 0, ans = -1;
            while (scanner.hasNextInt()) {
                int v = scanner.nextInt();
                if (v == target && ans == -1) ans = idx;
                idx++;
            }
            System.out.println(ans);
        }
    }
}