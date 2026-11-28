import java.util.*;
public class Solution {
    static void perm(char[] chars, String cur, boolean[] used) {
        if (cur.length() == chars.length) {
            System.out.println(cur);
            return;
        }
        for (int i = 0; i < chars.length; i++) {
            if (!used[i]) {
                used[i] = true;
                perm(chars, cur + chars[i], used);
                used[i] = false;
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            char[] chars = scanner.next().toCharArray();
            Arrays.sort(chars);
            perm(chars, "", new boolean[chars.length]);
        }
    }
}