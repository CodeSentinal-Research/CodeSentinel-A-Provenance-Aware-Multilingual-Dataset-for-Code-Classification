import java.util.*;
public class Solution {
    static int maxLen = 0;
    static void backtrack(List<int[]> masks, int idx, int curM, int curLen) {
        maxLen = Math.max(maxLen, curLen);
        for (int i = idx; i < masks.size(); i++) {
            int[] pair = masks.get(i);
            if ((curM & pair[0]) == 0) {
                backtrack(masks, i + 1, curM | pair[0], curLen + pair[1]);
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<int[]> masks = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String s = scanner.next();
                int m = 0; boolean dup = false;
                for (char c : s.toCharArray()) {
                    int b = 1 << (c - 'a');
                    if ((m & b) != 0) { dup = true; break; }
                    m |= b;
                }
                if (!dup) masks.add(new int[]{m, s.length()});
            }
            backtrack(masks, 0, 0, 0);
            System.out.println(maxLen);
        }
    }
}